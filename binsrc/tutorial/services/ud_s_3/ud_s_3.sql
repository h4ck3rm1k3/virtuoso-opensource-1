--  
--  $Id: ud_s_3.sql,v 1.2 2006/08/16 07:58:13 source Exp $
--  
--  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
--  project.
--  
--  Copyright (C) 1998-2006 OpenLink Software
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
--  
create user UDDI;

user_set_qualifier ('UDDI', 'UDDI');

-- this can be a strict grant (only over UDDI schema: tables, procedures)
grant all privileges to UDDI;

VHOST_REMOVE (lpath=>'/uddi');

VHOST_DEFINE (lpath=>'/uddi', ppath=>'/SOAP/', soap_user=>'UDDI');

