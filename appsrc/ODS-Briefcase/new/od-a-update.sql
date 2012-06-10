--
--  $Id: od-a-update.sql,v 1.1.2.2 2010/09/20 10:14:57 source Exp $
--
--  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
--  project.
--
--  Copyright (C) 1998-2007 OpenLink Software
--
--  This project is free software; you can redistribute it and/or modify it
--  under the terms of the GNU General Public License as published by the
--  Free Software Foundation; only version 2 of the License, dated June 1991.
--
--  This program is distributed in the hope that it will be useful, but
--  WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
--  General Public License for more details.
--
--  You should have received a copy of the GNU General Public License along
--  with this program; if not, write to the Free Software Foundation, Inc.,
--  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
--

-------------------------------------------------------------------------------
--
create procedure ODRIVE.WA.tmp_upgrade ()
{
  declare inst any;

  if (registry_get ('odrive_path_upgrade') = '1')
    return;
  registry_set ('odrive_path_upgrade', '1');

  for (select WAI_ID, WAI_NAME, WAI_INST from DB.DBA.WA_INSTANCE where WAI_TYPE_NAME = 'oDrive') do
  {
    VHOST_REMOVE(lpath    => '/odrive/' || cast (WAI_ID as varchar));
    VHOST_DEFINE(lpath    => '/odrive/' || cast (WAI_ID as varchar),
                 ppath    => (WAI_INST as wa_oDrive).get_param ('host') || 'www/',
                 ses_vars => 1,
                 is_dav   => (WAI_INST as wa_oDrive).get_param ('isDAV'),
                 is_brws  => 0,
                 vsp_user => 'dba',
                 realm    => 'wa',
                 def_page => 'home.vspx',
                 opts     => vector ('domain', WAI_ID)
               );
    update DB.DBA.WA_MEMBER
       set WAM_HOME_PAGE = '/odrive/' || cast (WAI_ID as varchar) || '/home.vspx'
     where WAM_INST = WAI_NAME;
  }
  VHOST_REMOVE (lpath    => '/odrive/');
}
;

ODRIVE.WA.tmp_upgrade ();

-------------------------------------------------------------------------------
--
create procedure ODRIVE.WA.tmp_set_criteria (
  inout search varchar,
  inout id integer,
  in fType any,
  in fCriteria any,
  in fValue any,
  in fSchema any := null,
  in fProperty any := null)

{
	if (is_empty_or_null (fCriteria))
	  return;
	if (is_empty_or_null (fValue))
	  return;
	ODRIVE.WA.dc_set_criteria (search, cast (id as varchar), fType, fCriteria, fValue, fSchema, fProperty);
	id := id + 1;
}
;
-------------------------------------------------------------------------------
--
create procedure ODRIVE.WA.tmp_upgrade ()
{
  if (registry_get ('odrive_items_upgrade') = '1')
    return;
  registry_set ('odrive_items_upgrade', '1');

	declare I, N, M integer;
  declare tmp, oldSearch, newSearch, aXml, aEntity any;

  for (select COL_ID, WS.WS.COL_PATH (COL_ID) as COL_FULL_PATH from WS.WS.SYS_DAV_COL where COL_DET = 'ResFilter' or COL_DET = 'CatFilter') do
  {
  	M := 0;
    oldSearch := ODRIVE.WA.DAV_PROP_GET (COL_FULL_PATH, 'virt:Filter-Params', null, 'dav');
    newSearch := null;

	  aXml := ODRIVE.WA.dc_xml_doc (oldSearch);

	  -- base
	  --
    ODRIVE.WA.dc_set_base (newSearch, 'path', ODRIVE.WA.dc_get (oldSearch, 'base', 'path'));

	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_NAME',         'like',                                                   ODRIVE.WA.dc_get(oldSearch, 'base', 'name'));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_CONTENT',      'contains_text',                                          ODRIVE.WA.dc_get(oldSearch, 'base', 'content'));

	  -- advanced
	  --
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_TYPE',         'like',                                                   ODRIVE.WA.dc_get(oldSearch, 'advanced', 'mime'));
    ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_OWNER_NAME',   '=',                                                      ODRIVE.WA.account_name (ODRIVE.WA.dc_get(oldSearch, 'advanced', 'owner')));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_GROUP_NAME',   '=',                                                      ODRIVE.WA.account_name (ODRIVE.WA.dc_get(oldSearch, 'advanced', 'group')));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_CR_TIME',      ODRIVE.WA.dc_get(oldSearch, 'advanced', 'createDate11'),  ODRIVE.WA.dc_get(oldSearch, 'advanced', 'createDate12'));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_CR_TIME',      ODRIVE.WA.dc_get(oldSearch, 'advanced', 'createDate21'),  ODRIVE.WA.dc_get(oldSearch, 'advanced', 'createDate22'));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_MOD_TIME',     ODRIVE.WA.dc_get(oldSearch, 'advanced', 'modifyDate11'),  ODRIVE.WA.dc_get(oldSearch, 'advanced', 'modifyDate12'));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_MOD_TIME',     ODRIVE.WA.dc_get(oldSearch, 'advanced', 'modifyDate21'),  ODRIVE.WA.dc_get(oldSearch, 'advanced', 'modifyDate22'));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_PUBLIC_TAGS',  ODRIVE.WA.dc_get(oldSearch, 'advanced', 'publicTags11'),  ODRIVE.WA.dc_get(oldSearch, 'advanced', 'publicTags12'));
	  ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RES_PRIVATE_TAGS', ODRIVE.WA.dc_get(oldSearch, 'advanced', 'privateTags11'), ODRIVE.WA.dc_get(oldSearch, 'advanced', 'privateTags12'));

	  -- properties
	  --
	  I := xpath_eval('count(/dc/property/entry)', aXml);
	  for (N := 1; N <= I; N := N + 1)
	  {
	    aEntity := xpath_eval('/dc/property/entry', aXml, N);
	    ODRIVE.WA.tmp_set_criteria (newSearch, M, 'PROP_VALUE', cast (xpath_eval ('@condition', aEntity) as varchar), cast (xpath_eval ('.', aEntity) as varchar), null, cast (xpath_eval ('@property', aEntity) as varchar));
	  }

	  -- metadata
	  --
	  I := xpath_eval('count(/dc/metadata/entry)', aXml);
	  for (N := 1; N <= I; N := N + 1)
	  {
	    aEntity := xpath_eval('/dc/metadata/entry', aXml, N);
	    if (cast (xpath_eval ('@type', aEntity) as varchar) = 'RDF')
	    {
  	    ODRIVE.WA.tmp_set_criteria (newSearch, M, 'RDF_VALUE', cast (xpath_eval ('@condition', aEntity) as varchar), cast (xpath_eval ('.', aEntity) as varchar), cast (xpath_eval ('@schema', aEntity) as varchar), cast (xpath_eval ('@property', aEntity) as varchar));
	    } else {
  	    ODRIVE.WA.tmp_set_criteria (newSearch, M, 'PROP_VALUE', cast (xpath_eval ('@condition', aEntity) as varchar), cast (xpath_eval ('.', aEntity) as varchar), null, cast (xpath_eval ('@property', aEntity) as varchar));
	    }
	  }

    ODRIVE.WA.DAV_PROP_SET (COL_FULL_PATH, 'virt:Filter-Params', newSearch, 'dav');
  }
}
;

ODRIVE.WA.tmp_upgrade ();
