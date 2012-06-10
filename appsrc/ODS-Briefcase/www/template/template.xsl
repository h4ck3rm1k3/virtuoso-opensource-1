<?xml version="1.0" encoding="UTF-8"?>
<!--
 -
 -  $Id: template.xsl,v 1.18.2.10 2011/05/02 14:16:28 source Exp $
 -
 -  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 -  project.
 -
 -  Copyright (C) 1998-2006 OpenLink Software
 -
 -  This project is free software; you can redistribute it and/or modify it
 -  under the terms of the GNU General Public License as published by the
 -  Free Software Foundation; only version 2 of the License, dated June 1991.
 -
 -  This program is distributed in the hope that it will be useful, but
 -  WITHOUT ANY WARRANTY; without even the implied warranty of
 -  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 -  General Public License for more details.
 -
 -  You should have received a copy of the GNU General Public License along
 -  with this program; if not, write to the Free Software Foundation, Inc.,
 -  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 -
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0" xmlns:v="http://www.openlinksw.com/vspx/" xmlns:xhtml="http://www.w3.org/1999/xhtml" xmlns:vm="http://www.openlinksw.com/vspx/macro" xmlns:ods="http://www.openlinksw.com/vspx/ods/">
  <xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>

  <!--=========================================================================-->
  <xsl:include href="http://local.virt/DAV/VAD/wa/comp/ods_bar.xsl"/>

  <!--=========================================================================-->
  <xsl:variable name="page_title" select="string (//vm:pagetitle)"/>

  <!--=========================================================================-->
  <xsl:template match="head/title[string(.)='']" priority="100">
    <title>
      <xsl:value-of select="$page_title"/>
    </title>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="head/title">
    <title>
      <xsl:value-of select="replace(string(.),'!page_title!',$page_title)"/>
    </title>
  </xsl:template>
  <xsl:template match="vm:pagetitle"/>

  <!--=========================================================================-->
  <xsl:template match="v:page[not @style and not @on-error-redirect][@name != 'error_page']">
    <xsl:copy>
  	  <xsl:copy-of select="@*"/>
  	    <xsl:attribute name="on-error-redirect">error.vspx</xsl:attribute>
        <xsl:if test="not (@on-deadlock-retry)">
        	<xsl:attribute name="on-deadlock-retry">5</xsl:attribute>
  	   </xsl:if>
  	   <xsl:apply-templates />
    </xsl:copy>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="v:button[not @xhtml_alt or not @xhtml_title]">
    <xsl:copy>
  	  <xsl:copy-of select="@*"/>
      <xsl:if test="not (@xhtml_alt)">
        <xsl:choose>
          <xsl:when test="@xhtml_title">
      	    <xsl:attribute name="xhtml_alt"><xsl:value-of select="@xhtml_title"/></xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
      	    <xsl:attribute name="xhtml_alt"><xsl:value-of select="@value"/></xsl:attribute>
          </xsl:otherwise>
        </xsl:choose>
  	  </xsl:if>
      <xsl:if test="not (@xhtml_title)">
        <xsl:choose>
          <xsl:when test="@xhtml_alt">
      	    <xsl:attribute name="xhtml_title"><xsl:value-of select="@xhtml_alt"/></xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
      	    <xsl:attribute name="xhtml_title"><xsl:value-of select="@value"/></xsl:attribute>
          </xsl:otherwise>
        </xsl:choose>
  	  </xsl:if>
  	  <xsl:apply-templates />
    </xsl:copy>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:copyright">
    <?vsp http (coalesce (wa_utf8_to_wide ((select top 1 WS_COPYRIGHT from WA_SETTINGS)), '')); ?>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:disclaimer">
    <?vsp http (coalesce (wa_utf8_to_wide ((select top 1 WS_DISCLAIMER from WA_SETTINGS)), '')); ?>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:popup_pagewrapper">
    <v:variable name="nav_pos_fixed" type="integer" default="1"/>
    <v:variable name="nav_top" type="integer" default="0"/>
    <xsl:for-each select="//v:variable">
      <xsl:copy-of select="."/>
    </xsl:for-each>
    <xsl:if test="not @clean or @clean = 'no'">
      <div style="padding: 0 0 0.5em 0;">
        <span class="button pointer" onclick="javascript: if (opener != null) opener.focus(); window.close();"><img class="button" src="/ods/images/icons/close_16.png" border="0" alt="Close" title="Close" /> Close</span>
      </div>
    </xsl:if>
    <div id="app_area">
      <v:form name="F1" type="simple" method="POST">
        <xsl:apply-templates select="vm:pagebody" />
      </v:form>
    </div>
    <xsl:if test="not @clean or @clean = 'no'">
    <div class="copyright"><vm:copyright /></div>
    </xsl:if>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:pagewrapper">
    <v:variable name="nav_pos_fixed" type="int" default="0"/>
    <v:variable name="nav_top" type="int" default="0"/>
    <xsl:for-each select="//v:variable">
      <xsl:copy-of select="."/>
    </xsl:for-each>
    <xsl:apply-templates select="vm:init"/>
    <v:form name="F1" method="POST" type="simple" action="--ODRIVE.WA.utf2wide (ODRIVE.WA.page_url (self.domain_id))" xhtml_enctype="multipart/form-data">
      <ods:ods-bar app_type='oDrive'/>
      <div id="app_area" style="clear: right;">
      <div style="background-color: #fff;">
        <div style="float: left;">
            <?vsp
              http (sprintf ('<a alt="Briefcase Home" title="Briefcase Home" href="%s"><img src="image/drivebanner_sml.jpg" border="0" alt="Briefcase Home" /></a>', ODRIVE.WA.utf2wide (ODRIVE.WA.domain_sioc_url (self.domain_id, self.sid, self.realm))));
            ?>
        </div>
          <?vsp
            if (0)
            {
          ?>
              <v:button name="searchHead" action="simple" style="url" value="Submit">
                <v:on-post>
                  <![CDATA[
                    declare S, q, params any;

                    params := e.ve_params;
                    q := trim (get_keyword ('keywords', params, ''));
                    S := case when q <> ''then sprintf ('&keywords=%s&step=1', q) else '' end;
                    self.vc_redirect (ODRIVE.WA.utf2wide (ODRIVE.WA.page_url (self.domain_id, sprintf ('home.vspx?mode=%s%s', get_keyword ('select', params, 'advanced'), S))));
                    self.vc_data_bind(e);
                   ]]>
                 </v:on-post>
              </v:button>
          <?vsp
            }
          ?>
        <div style="float: right; text-align: right; padding-right: 0.5em; padding-top: 20px;">
            <input name="keywords" value="" onkeypress="javascript: if (checkNotEnter(event)) return true; vspxPost('searchHead', 'select', 'simple'); return false;" />
            &amp;nbsp;
            <a href="<?vsp http (ODRIVE.WA.utf2wide (ODRIVE.WA.page_url (self.domain_id, 'search.vspx?mode=simple', self.sid, self.realm))); ?>" onclick="vspxPost('searchHead', 'select', 'simple'); return false;" title="Simple Search">Search</a>
          |
            <a href="<?vsp http (ODRIVE.WA.utf2wide (ODRIVE.WA.page_url (self.domain_id, 'search.vspx?mode=advanced', self.sid, self.realm))); ?>" onclick="vspxPost('searchHead', 'select', 'advanced'); return false;" title="Advanced">Advanced</a>
        </div>
      </div>
        <div style="clear: both; border: solid #935000; border-width: 0px 0px 1px 0px;">
          <div style="float: left; padding-left: 0.5em;">
            <?vsp http (ODRIVE.WA.utf2wide (ODRIVE.WA.banner_links (self.domain_id, self.sid, self.realm))); ?>
          </div>
          <div style="float: right; padding-right: 0.5em;">
            <vm:if test="self.account_role not in ('public', 'guest')">
              <a href="<?vsp http (ODRIVE.WA.utf2wide (ODRIVE.WA.page_url (self.domain_id, 'settings.vspx', self.sid, self.realm))); ?>" title="Preferences">Preferences</a>
              |
            </vm:if>
            <a href="<?vsp http (ODRIVE.WA.utf2wide (ODRIVE.WA.page_url (self.domain_id, 'about.vsp'))); ?>" onclick="javascript: ODRIVE.aboutDialog(); return false;" title="About">About</a>
      </div>
          <p style="clear: both; line-height: 0.1em" />
        </div>
      <v:include url="odrive_login.vspx"/>
    <table id="RCT">
      <tr>
          <td id="RC">
              <v:tree show-root="0" multi-branch="0" orientation="horizontal" root="ODRIVE.WA.navigation_root" start-path="" child-function="ODRIVE.WA.navigation_child">
                <v:before-data-bind>
                  <![CDATA[
                    declare page_name any;

                    page_name := ODRIVE.WA.page_name ();
                    if (page_name = 'error.vspx')
                    {
                      self.nav_pos_fixed := 1;
                    }
                    else if (not self.nav_top and page_name <> '')
                    {
                      self.nav_pos_fixed := 0;
                      self.nav_pos_fixed := ODRIVE.WA.check_grants2 (self.account_role, page_name);
                      control.vc_open_at (sprintf ('//*[@url = "%s"]', page_name));
                    }
                  ]]>
                </v:before-data-bind>

                <v:node-template>
                  <td nowrap="nowrap" class="<?V case when control.tn_open then 'sel' else '' end ?>">
                    <v:button action="simple" style="url" xhtml_class="--(case when (control.vc_parent as vspx_tree_node).tn_open = 1 then 'sel' else '' end)" value="--(control.vc_parent as vspx_tree_node).tn_value">
                      <v:after-data-bind>
                        <![CDATA[
                          if ((control.vc_parent as vspx_tree_node).tn_open = 1)
                            control.ufl_active := 0;
                          else
                            control.ufl_active := ODRIVE.WA.check_grants2(self.account_role, ODRIVE.WA.page_name ());
                        ]]>
                      </v:after-data-bind>
                      <v:before-render>
                        <![CDATA[
                          control.bt_anchor := 0;
                          control.bt_url := ODRIVE.WA.utf2wide (replace (control.bt_url, sprintf ('/odrive/%d', self.domain_id), ODRIVE.WA.page_url (self.domain_id)));
                        ]]>
                      </v:before-render>
                      <v:on-post>
                        <![CDATA[
                          declare node vspx_tree_node;
                          declare tree vspx_control;
                          self.nav_pos_fixed := 0;
                          node := control.vc_parent;
                          tree := node.tn_tree;
                          node.tn_tree.vt_open_at := NULL;
                          self.nav_top := 1;
                          tree.vc_data_bind (e);
                        ]]>
                      </v:on-post>
                    </v:button>
                  </td>
                </v:node-template>
                <v:leaf-template>
                  <td nowrap="nowrap" class="<?V case when control.tn_open then 'sel' else '' end ?>">
                    <v:button action="simple" style="url" xhtml_class="--case when (control.vc_parent as vspx_tree_node).tn_open = 1 then 'sel' else '' end" value="--(control.vc_parent as vspx_tree_node).tn_value">
                      <v:before-render>
                        <![CDATA[
                          control.bt_anchor := 0;
                          control.bt_url := ODRIVE.WA.utf2wide (replace (control.bt_url, sprintf ('/odrive/%d', self.domain_id), ODRIVE.WA.page_url (self.domain_id)));
                        ]]>
                      </v:before-render>
                    </v:button>
                  </td>
                </v:leaf-template>
                <v:horizontal-template>
                  <table class="nav_bar" cellspacing="0">
                    <tr>
                      <v:node-set />
                      <?vsp
                        if ((control as vspx_tree).vt_node <> control) {
                      ?>
                      <td class="filler"> </td>
                      <?vsp } ?>
                    </tr>
                  </table>
                  <?vsp
                    if ((control as vspx_tree).vt_node = control and not length (childs)) {
                  ?>
                  <div class="nav_bar nav_seperator" >x</div>
                  <?vsp } ?>
                </v:horizontal-template>
              </v:tree>
              <v:template name="t2" type="simple" condition="not self.vc_is_valid">
      	    <div class="error">
      		    <p><v:error-summary/></p>
      	    </div>
      	  </v:template>
      	  <div class="main_page_area">
      	    <xsl:apply-templates select="vm:pagebody" />
      	  </div>
      	</td>
      </tr>
    </table>
        <?vsp
          declare C any;
          C := vsp_ua_get_cookie_vec(self.vc_event.ve_lines);
        ?>
        <div id="FT" style="display: <?V case when get_keyword ('interface', C, '') = 'js' then 'none' else '' end ?>">
        <div id="FT_L">
          <a href="http://www.openlinksw.com/virtuoso">
            <img alt="Powered by OpenLink Virtuoso Universal Server" src="image/virt_power_no_border.png" border="0" />
          </a>
    </div>
        <div id="FT_R">
          <a href="<?V ODRIVE.WA.wa_home_link () ?>faq.html">FAQ</a> |
          <a href="<?V ODRIVE.WA.wa_home_link () ?>privacy.html">Privacy</a> |
          <a href="<?V ODRIVE.WA.wa_home_link () ?>rabuse.vspx">Report Abuse</a>
	    <div><vm:copyright /></div>
	    <div><vm:disclaimer /></div>
    </div>
      </div> <!-- FT -->
      </div>
    </v:form>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:ds-navigation">
    &lt;?vsp
        declare n_start, n_end, n_total integer;
        declare ds vspx_data_set;

      ds := case when (udt_instance_of (control, fix_identifier_case ('vspx_data_set'))) then control else control.vc_find_parent (control, 'vspx_data_set') end;
        if (isnull (ds.ds_data_source))
        {
          n_total := ds.ds_rows_total;
          n_start := ds.ds_rows_offs + 1;
          n_end   := n_start + ds.ds_nrows - 1;
        } else {
          n_total := ds.ds_data_source.ds_total_rows;
          n_start := ds.ds_data_source.ds_rows_offs + 1;
          n_end   := n_start + ds.ds_data_source.ds_rows_fetched - 1;
        }
        if (n_end > n_total)
          n_end := n_total;

        if (n_total)
        http (sprintf ('Showing %d - %d of %d', n_start, n_end, n_total));

      declare _prev, _next vspx_button;

  	    _next := control.vc_find_control ('<xsl:value-of select="@data-set"/>_next');
  	    _prev := control.vc_find_control ('<xsl:value-of select="@data-set"/>_prev');
      if ((_next is not null and _next.vc_enabled) or (_prev is not null and _prev.vc_enabled))
            http (' | ');
    ?&gt;
    <v:button name="{@data-set}_first" action="simple" style="url" value="" xhtml_alt="First" xhtml_class="navi-button" >
      <v:before-render>
        <![CDATA[
          control.ufl_value := '<img src="/ods/images/skin/pager/p_first.png" border="0" alt="First" title="First"/> First ';
        ]]>
      </v:before-render>
    </v:button>
    &nbsp;
    <v:button name="{@data-set}_prev" action="simple" style="url" value="" xhtml_alt="Previous" xhtml_class="navi-button">
      <v:before-render>
        <![CDATA[
          control.ufl_value := '<img src="/ods/images/skin/pager/p_prev.png" border="0" alt="Previous" title="Previous"/> Prev ';
        ]]>
      </v:before-render>
    </v:button>
    &nbsp;
    <v:button name="{@data-set}_next" action="simple" style="url" value="" xhtml_alt="Next" xhtml_class="navi-button">
      <v:before-render>
        <![CDATA[
          control.ufl_value := '<img src="/ods/images/skin/pager/p_next.png" border="0" alt="Next" title="Next"/> Next ';
        ]]>
      </v:before-render>
    </v:button>
    &nbsp;
    <v:button name="{@data-set}_last" action="simple" style="url" value="" xhtml_alt="Last" xhtml_class="navi-button">
      <v:before-render>
        <![CDATA[
          control.ufl_value := '<img src="/ods/images/skin/pager/p_last.png" border="0" alt="Last" title="Last"/> Last ';
        ]]>
      </v:before-render>
    </v:button>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template name="vm:links">
    <div class="left_container">
      <ul class="left_navigation">
        <li><a href="/doc/docs.vsp" target="_empty" alt="Documentation" title="Documentation">Documentation</a></li>
        <li><a href="/tutorial/index.vsp" target="_empty" alt="Tutorials" title="Tutorials">Tutorials</a></li>
        <li><a href="http://www.openlinksw.com" alt="OpenLink Software" title="OpenLink Software">OpenLink Software</a></li>
        <li><a href="http://www.openlinksw.com/virtuoso" alt="Virtuoso Web Site" title="Virtuoso Web Site">Virtuoso Web Site</a></li>
      </ul>
    </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template name="vm:splash">
    <div style="padding: 1em; font-size: 0.70em;">
      <a href="http://www.openlinksw.com/virtuoso"><img title="Powered by OpenLink Virtuoso Universal Server" src="image/PoweredByVirtuoso.gif" border="0" /></a>
      <br />
      Server version: <?V sys_stat('st_dbms_ver') ?><br/>
      Server build date: <?V sys_stat('st_build_date') ?><br/>
      Briefcase version: <?V registry_get('_oDrive_version_') ?><br/>
      Briefcase build date: <?V registry_get('_oDrive_build_') ?><br/>
    </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:rawheader">
  &lt;?vsp if (self.nav_pos_fixed) { ?&gt;
  <xsl:apply-templates select="node()|processing-instruction()"/>
  &lt;?vsp } ?&gt;
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:raw">
  &lt;?vsp if (self.nav_pos_fixed) { ?&gt;
  <xsl:apply-templates select="node()|processing-instruction()"/>
  &lt;?vsp } ?&gt;
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:pagebody">
    &lt;?vsp if (self.nav_pos_fixed) { ?&gt;
    <xsl:choose>
      <xsl:when test="@url">
        <v:template name="vm_pagebody_include_url" type="simple">
          <v:include url="{@url}"/>
        </v:template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates select="node()|processing-instruction()"/>
      </xsl:otherwise>
    </xsl:choose>
    &lt;?vsp } else { ?&gt;
      <table class="splash_table">
        <tr>
          <td>
            <xsl:call-template name="vm:splash"/>
          </td>
        </tr>
      </table>
    &lt;?vsp } ?&gt;
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:header">
    <xsl:if test="@caption">
    &lt;?vsp if (self.nav_pos_fixed) { ?&gt;
    <td class="page_title">
      <!-- <xsl:copy-of select="@class"/> -->
      <xsl:value-of select="@caption"/>
    </td>
    &lt;?vsp } ?&gt;
    </xsl:if>
    <xsl:apply-templates/>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:init">
    <xsl:apply-templates select="node()|processing-instruction()"/>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:if">
    <xsl:processing-instruction name="vsp">
      if (<xsl:value-of select="@test"/>)
      {
    </xsl:processing-instruction>
        <xsl:apply-templates />
    <xsl:processing-instruction name="vsp">
      }
    </xsl:processing-instruction>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:caption">
    <xsl:value-of select="@fixed"/>
    <xsl:apply-templates/>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:label">
    <label>
      <xsl:attribute name="for"><xsl:value-of select="@for"/></xsl:attribute>
      <v:label><xsl:attribute name="value"><xsl:value-of select="@value"/></xsl:attribute></v:label>
    </label>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:tabCaption">
    <div>
      <xsl:attribute name="id"><xsl:value-of select="concat('tab_', @tab)"/></xsl:attribute>
      <xsl:attribute name="class">tab <xsl:if test="@activeTab = @tab">activeTab</xsl:if></xsl:attribute>
      <xsl:attribute name="onclick">javascript:showTab(<xsl:value-of select="@tab"/>, <xsl:value-of select="@tabs"/>)</xsl:attribute>
      <xsl:value-of select="@caption"/>
    </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template name="nbsp">
    <xsl:param name="count" select="1"/>
    <xsl:if test="$count != 0">
      <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
      <xsl:call-template name="nbsp">
        <xsl:with-param name="count" select="$count - 1"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:permissions-header1">
    <tr>
      <xsl:if test="@text">
        <th rowspan="2" style="background-color: #EFEFEF; border-width: 0px;" />
      </xsl:if>
      <th colspan="3">Owner</th>
      <th colspan="3">Group</th>
      <th class="right" colspan="3">Other</th>
    </tr>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:permissions-header2">
    <tr>
      <td>r</td>
      <td>w</td>
      <td>x</td>
      <td>r</td>
      <td>w</td>
      <td>x</td>
      <td>r</td>
      <td>w</td>
      <td class="right">x</td>
    </tr>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:search-dc-template4">
    <div id="4" class="tabContent" style="display: none;">
      <table class="form-body" cellspacing="0">
    <tr>
          <th>
            <v:label for="dav_oMail_DomainId" value="--'oMail domain'" />
          </th>
      <td>
            <v:text name="dav_oMail_DomainId" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="regexp" regexp="^[0-9]+$" message="Number is expected" runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_oMail_DomainId', self.dav_path, 'virt:oMail-DomainId', '1');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="dav_oMail_FolderName" value="--'oMail folder name'" />
          </th>
          <td>
            <v:text name="dav_oMail_FolderName" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="1" max="255" message="The input can not be empty." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_oMail_FolderName', self.dav_path, 'virt:oMail-FolderName', 'Inbox');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="dav_oMail_NameFormat" value="--'oMail name format'" />
          </th>
          <td>
            <v:text name="dav_oMail_NameFormat" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="1" max="255" message="The input can not be empty." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_oMail_NameFormat', self.dav_path, 'virt:oMail-NameFormat', '^from^ ^subject^');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
      </table>
        </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:search-dc-template5">
    <div id="5" class="tabContent" style="display: none;">
      <table class="form-body" cellspacing="0">
        <tr>
          <th>
            <v:label for="dav_PropFilter_SearchPath" value="--'Search path'" />
          </th>
          <td>
            <v:text name="dav_PropFilter_SearchPath" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="1" max="255" message="The input can not be empty." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_PropFilter_SearchPath', self.dav_path, 'virt:PropFilter-SearchPath', ODRIVE.WA.path_show (self.dir_path));
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="dav_PropFilter_PropName" value="--'Property name'" />
          </th>
          <td>
            <v:text name="dav_PropFilter_PropName" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="1" max="255" message="The input can not be empty." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_PropFilter_PropName', self.dav_path, 'virt:PropFilter-PropName', '');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="dav_PropFilter_PropValue" value="--'Property value'" />
          </th>
          <td>
            <v:text name="dav_PropFilter_PropValue" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_PropFilter_PropValue', self.dav_path, 'virt:PropFilter-PropValue', '');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
      </table>
        </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:search-dc-template6">
    <div id="6" class="tabContent" style="display: none;">
      <table class="form-body" cellspacing="0">
        <tr>
          <th>
            <v:label for="dav_S3_BucketName" value="Bucket Name" />
          </th>
          <td>
            <v:text name="dav_S3_BucketName" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="0" max="63" message="The input can not be empty." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_S3_BucketName', self.dav_path, 'virt:S3-BucketName', '');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="dav_S3_AccessKey" value="Access Key ID (*)" />
          </th>
          <td>
            <v:text name="dav_S3_AccessKeyID" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="20" max="20" message="The input must be 20 characters long." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_S3_AccessKeyID', self.dav_path, 'virt:S3-AccessKeyID', '');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="dav_S3_SecretKey" value="Secret Key (*)" />
          </th>
          <td>
            <v:text name="dav_S3_SecretKey" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="40" max="40" message="The input must be 40 characters long." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_S3_SecretKey', self.dav_path, 'virt:S3-SecretKey', '');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
      </table>
    </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:search-dc-template7">
    <div id="7" class="tabContent" style="display: none;">
      <table class="form-body" cellspacing="0">
        <tr>
          <th width="30%">
            <v:label for="ts_path" value="--'Search path'" />
          </th>
          <td>
            <?vsp http (sprintf ('<input type="text" name="ts_path" value="%V" disabled="disabled" class="field-text" />', ODRIVE.WA.dc_get(self.search_dc, 'base', 'path', ODRIVE.WA.path_show(self.dir_path)))); ?>
          </td>
        </tr>
      </table>
      <br />
      <table style="width: 100%;">
        <tr>
          <td>
      <table id="searchProperties" class="form-list" style="width: 100%;" cellspacing="0">
        <thead>
          <tr>
            <th id="search_th_0" width="20%">Field</th>
            <th id="search_th_1" width="20%" style="display: none;">Schema</th>
            <th id="search_th_2" width="20%" style="display: none;">Property</th>
            <th id="search_th_3" width="20%">Condition</th>
            <th id="search_th_4" width="20%">Value</th>
            <th id="search_th_5" width="1%" nowrap="nowrap"><xsl:call-template name="nbsp"/></th>
          </tr>
        </thead>
        <tbody id="search_tbody">
                <tr id="search_tr_no"><td colspan="6"><b>No Criteria</b></td></tr>
    		  <![CDATA[
    		    <script type="text/javascript">
              OAT.MSG.attach(OAT, "PAGE_LOADED", ODRIVE.initFilter);
    		  <?vsp
            		    declare I, N integer;
            		    declare S varchar;
            		    declare aCriteria, criteria any;
                    declare V, f0, f1, f2, f3, f4 any;

                    aCriteria := ODRIVE.WA.dc_xml_doc (self.search_dc);
                    I := xpath_eval('count(/dc/criteria/entry)', aCriteria);
              for (N := 1; N <= I; N := N + 1)
              {
                criteria := xpath_eval('/dc/criteria/entry', aCriteria, N);
                f0 := coalesce (cast (xpath_eval ('@field', criteria) as varchar), 'null');
                f1 := coalesce (cast (xpath_eval ('@schema', criteria) as varchar), 'null');
                f2 := coalesce (cast (xpath_eval ('@property', criteria) as varchar), 'null');
                f3 := coalesce (cast (xpath_eval ('@criteria', criteria) as varchar), 'null');
                f4 := coalesce (cast (xpath_eval ('.', criteria) as varchar), 'null');
                      S := replace (sprintf ('field_0:\'%s\', field_1:\'%s\', field_2:\'%s\', field_3:\'%s\', field_4:\'%s\'', f0, f1, f2, f3, f4), '\'null\'', 'null');

                      http (sprintf ('OAT.MSG.attach(OAT, "PAGE_LOADED", function(){ODRIVE.searchRowCreate({%s});});', S));
              }
    		  ?>
    		    </script>
    		  ]]>
        </tbody>
      </table>
          </td>
          <td valign="top" nowrap="nowrap" width="1%">
            <span class="button pointer" onclick="javascript: ODRIVE.searchRowCreate();"><img src="image/add_16.png" border="0" class="button" alt="Add Criteria" title="Add Criteria" /> Add</span><br /><br />
          </td>
        </tr>
      </table>
        </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:search-dc-template8">
    <div id="8" class="tabContent" style="display: none;">
      <table class="form-body" cellspacing="0">
        <tr>
          <th>
            <v:label for="dav_rdfSink_rdfGraph" value="--'Graph name'" />
          </th>
          <td>
            <v:text name="dav_rdfSink_rdfGraph" format="%s" xhtml_disabled="disabled" xhtml_class="field-text">
              <v:validator test="length" min="1" max="255" message="The input can not be empty." runat="client" />
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_rdfSink_rdfGraph', self.dav_path, 'virt:rdf_graph', '');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="dav_rdfSink_rdfSponger" value="--'Sponger (on/off)'" />
          </th>
          <td>
            <v:text name="dav_rdfSink_rdfSponger" format="%s" xhtml_disabled="disabled" xhtml_class="field-short">
              <v:before-data-bind>
                <![CDATA[
                  control.ufl_value := self.get_fieldProperty ('dav_rdfSink_rdfSponger', self.dav_path, 'virt:rdf_sponger', '');
                ]]>
              </v:before-data-bind>
            </v:text>
          </td>
        </tr>
      </table>
        </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:search-dc-template9">
    <div id="9" class="tabContent" style="display: none;">
      <table class="form-body" cellspacing="0">
        <tr>
          <th >
            <v:label value="File State" />
          </th>
          <td>
            <?vsp
              http (sprintf ('Lock is <b>%s</b>, ', ODRIVE.WA.DAV_GET_INFO (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'), 'lockState')));
              http (sprintf ('Version Control is <b>%s</b>, ', ODRIVE.WA.DAV_GET_INFO (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'), 'vc')));
              http (sprintf ('Auto Versioning is <b>%s</b>, ', ODRIVE.WA.DAV_GET_INFO (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'), 'avcState')));
              http (sprintf ('Version State is <b>%s</b>', ODRIVE.WA.DAV_GET_INFO (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'), 'vcState')));
            ?>
          </td>
        </tr>
        <v:template name="t3" type="simple" enabled="-- case when (equ(self.command_mode, 10)) then 1 else 0 end">
          <tr>
            <th >
              <v:label value="--sprintf ('Content is %s in Version Control', either(equ(ODRIVE.WA.DAV_GET (self.dav_item, 'versionControl'),1), '', 'not'))" format="%s" />
            </th>
            <td>
              <v:button name="template_vc" action="simple" value="--sprintf ('%s VC', either(equ(ODRIVE.WA.DAV_GET (self.dav_item, 'versionControl'),1), 'Disable', 'Enable'))" xhtml_class="button" xhtml_disabled="disabled">
                <v:on-post>
                  <![CDATA[
                    declare retValue any;

                    if (ODRIVE.WA.DAV_GET (self.dav_item, 'versionControl'))
                    {
                      retValue := ODRIVE.WA.DAV_REMOVE_VERSION_CONTROL (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    } else {
                      retValue := ODRIVE.WA.DAV_VERSION_CONTROL (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    }
                    if (ODRIVE.WA.DAV_ERROR(retValue))
                    {
                      self.vc_error_message := ODRIVE.WA.DAV_PERROR(retValue);
                      self.vc_is_valid := 0;
                      return;
                    }
                    self.vc_data_bind (e);
                  ]]>
                </v:on-post>
              </v:button>
            </td>
          </tr>
        </v:template>
        <vm:autoVersion />
        <v:template name="t4" type="simple" enabled="-- case when (equ(ODRIVE.WA.DAV_GET (self.dav_item, 'versionControl'),1)) then 1 else 0 end">
          <tr>
            <th >
              File commands
            </th>
            <td>
              <v:button name="tepmpate_lock" action="simple" value="Lock" enabled="-- case when (ODRIVE.WA.DAV_IS_LOCKED(ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'))) then 0 else 1 end" xhtml_class="button">
                <v:on-post>
                  <![CDATA[
                    declare retValue any;

                    retValue := ODRIVE.WA.DAV_LOCK (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    if (ODRIVE.WA.DAV_ERROR(retValue))
                    {
                      self.vc_error_message := ODRIVE.WA.DAV_PERROR(retValue);
                      self.vc_is_valid := 0;
                      return;
                    }
                    self.vc_data_bind (e);
                  ]]>
                </v:on-post>
              </v:button>
              <v:button name="tepmpate_unlock" action="simple" value="Unlock" enabled="-- case when (ODRIVE.WA.DAV_IS_LOCKED(ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'))) then 1 else 0 end" xhtml_class="button">
                <v:on-post>
                  <![CDATA[
                    declare retValue any;

                    retValue := ODRIVE.WA.DAV_UNLOCK (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    if (ODRIVE.WA.DAV_ERROR(retValue))
                    {
                      self.vc_error_message := ODRIVE.WA.DAV_PERROR(retValue);
                      self.vc_is_valid := 0;
                      return;
                    }
                    self.vc_data_bind (e);
                  ]]>
                </v:on-post>
              </v:button>
            </td>
          </tr>
          <tr>
            <th >
              Versioning commands
            </th>
            <td>
              <v:button name="tepmpate_checkIn" action="simple" value="Check-In" enabled="-- case when (is_empty_or_null(ODRIVE.WA.DAV_GET (self.dav_item, 'checked-in'))) then 1 else 0 end" xhtml_class="button">
                <v:on-post>
                  <![CDATA[
                    declare retValue any;

                    retValue := ODRIVE.WA.DAV_CHECKIN (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    if (ODRIVE.WA.DAV_ERROR(retValue)) {
                      self.vc_error_message := ODRIVE.WA.DAV_PERROR(retValue);
                      self.vc_is_valid := 0;
                      return;
                    }
                    self.vc_data_bind (e);
                  ]]>
                </v:on-post>
              </v:button>
              <v:button  name="tepmpate_checkOut" action="simple" value="Check-Out" enabled="-- case when (is_empty_or_null(ODRIVE.WA.DAV_GET (self.dav_item, 'checked-out'))) then 1 else 0 end" xhtml_class="button">
                <v:on-post>
                  <![CDATA[
                    declare retValue any;

                    retValue := ODRIVE.WA.DAV_CHECKOUT (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    if (ODRIVE.WA.DAV_ERROR(retValue))
                    {
                      self.vc_error_message := ODRIVE.WA.DAV_PERROR(retValue);
                      self.vc_is_valid := 0;
                      return;
                    }
                    self.vc_data_bind (e);
                  ]]>
                </v:on-post>
              </v:button>
              <v:button  name="tepmpate_uncheckOut" action="simple" value="Uncheck-Out" enabled="-- case when (is_empty_or_null(ODRIVE.WA.DAV_GET (self.dav_item, 'checked-in'))) then 1 else 0 end" xhtml_class="button">
                <v:on-post>
                  <![CDATA[
                    declare retValue any;

                    retValue := ODRIVE.WA.DAV_UNCHECKOUT (ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    if (ODRIVE.WA.DAV_ERROR(retValue))
                    {
                      self.vc_error_message := ODRIVE.WA.DAV_PERROR(retValue);
                      self.vc_is_valid := 0;
                      return;
                    }
                    self.vc_data_bind (e);
                  ]]>
                </v:on-post>
              </v:button>
            </td>
          </tr>
          <tr>
            <th >
              Number of Versions in History
            </th>
            <td>
              <v:label value="--ODRIVE.WA.DAV_GET_VERSION_COUNT(ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'))" format="%d" />
            </td>
          </tr>
          <tr>
            <th >
              Root version
            </th>
            <td>
              <v:button style="url" action="simple" value="--ODRIVE.WA.DAV_GET_VERSION_ROOT(ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'))" format="%s">
                <v:on-post>
                  <![CDATA[
                    declare path varchar;

                    path := ODRIVE.WA.DAV_GET_VERSION_ROOT(ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath'));
                    if (ODRIVE.WA.odrive_permission(path) = '')
                    {
                      self.vc_error_message := 'You have not rights to read this folder/file!';
                      self.vc_is_valid := 0;
                      self.vc_data_bind (e);
                      return;
                    }

                    http_request_status ('HTTP/1.1 302 Found');
                    http_header (sprintf ('Location: view.vsp?sid=%s&realm=%s&file=%U&mode=download\r\n', self.sid , self.realm, path));
                    self.vc_data_bind (e);
                  ]]>
                </v:on-post>
              </v:button>
            </td>
          </tr>
          <tr>
            <th>Versions</th>
            <td>
              <v:data-set name="ds_versions" sql="select rs.* from ODRIVE.WA.DAV_GET_VERSION_SET(rs0)(c0 varchar, c1 integer) rs where rs0 = :p0" nrows="0" scrollable="1">
                <v:param name="p0" value="--ODRIVE.WA.DAV_GET (self.dav_item, 'fullPath')" />

                <v:template name="ds_versions_header" type="simple" name-to-remove="table" set-to-remove="bottom">
                  <table class="form-list" style="width: auto;" id="versions" cellspacing="0">
                    <tr>
                      <th>Path</th>
                      <th>Number</th>
                      <th>Size</th>
                      <th>Modified</th>
                      <th>Action</th>
                    </tr>
                  </table>
                </v:template>

                <v:template name="ds_versions_repeat" type="repeat">

                  <v:template name="ds_versions_empty" type="if-not-exists" name-to-remove="table" set-to-remove="both">
                    <table>
                      <tr align="center">
                        <td colspan="5">No versions</td>
                      </tr>
                    </table>
                  </v:template>

                  <v:template name="ds_versions_browse" type="browse" name-to-remove="table" set-to-remove="both">
                    <table>
                      <tr>
                        <td nowrap="nowrap">
                          <v:button name="button_versions_show" style="url" action="simple" value="--(control.vc_parent as vspx_row_template).te_column_value('c0')" format="%s">
                            <v:on-post>
                              <![CDATA[
                                declare path varchar;

                                path := (control.vc_parent as vspx_row_template).te_column_value('c0');
                                if (ODRIVE.WA.odrive_permission(path) = '')
                                {
                                  self.vc_error_message := 'You have not rights to read this folder/file!';
                                  self.vc_is_valid := 0;
                                  self.vc_data_bind (e);
                                  return;
                                }

                                http_request_status ('HTTP/1.1 302 Found');
                                http_header (sprintf ('Location: view.vsp?sid=%s&realm=%s&file=%U&mode=download\r\n', self.sid , self.realm, path));
                                self.vc_data_bind (e);
                              ]]>
                            </v:on-post>
                          </v:button>
                        </td>
                        <td nowrap="nowrap" align="right">
                          <v:label value="--ODRIVE.WA.path_name((control.vc_parent as vspx_row_template).te_column_value('c0'))" />
                        </td>
                        <td nowrap="nowrap" align="right">
                          <v:label>
                            <v:after-data-bind>
                              <![CDATA[
                                control.ufl_value := ODRIVE.WA.ui_size(ODRIVE.WA.DAV_PROP_GET((control.vc_parent as vspx_row_template).te_column_value('c0'), ':getcontentlength'), 'R');
                              ]]>
                            </v:after-data-bind>
                          </v:label>
                        </td>
                        <td nowrap="nowrap" align="right">
                          <v:label>
                            <v:after-data-bind>
                              <![CDATA[
                                control.ufl_value := ODRIVE.WA.ui_date(ODRIVE.WA.DAV_PROP_GET((control.vc_parent as vspx_row_template).te_column_value('c0'), ':getlastmodified'));
                              ]]>
                            </v:after-data-bind>
                          </v:label>
                        </td>
                        <td nowrap="nowrap">
                          <v:button name="button_versions_delete" action="simple" style="url" value="Version Delete" enabled="--(control.vc_parent as vspx_row_template).te_column_value('c1')">
                            <v:after-data-bind>
                              <![CDATA[
                                control.ufl_value := '<img src="image/del_16.png" border="0" alt="Version Delete" title="Version Delete" onclick="javascript: if (!confirm(\'Are you sure you want to delete the chosen version and all previous versions?\')) { event.cancelBubble = true;};" />';
                              ]]>
                            </v:after-data-bind>
                            <v:on-post>
                              <![CDATA[
                                declare retValue any;

                                retValue := ODRIVE.WA.DAV_DELETE((control.vc_parent as vspx_row_template).te_column_value('c0'));
                                if (ODRIVE.WA.DAV_ERROR(retValue))
                                {
                                  self.vc_error_message := ODRIVE.WA.DAV_PERROR(retValue);
                                  self.vc_is_valid := 0;
                                  return;
                                }
                                self.vc_data_bind (e);
                              ]]>
                            </v:on-post>
                          </v:button>
                        </td>
                      </tr>
                    </table>
                  </v:template>

                </v:template>

                <v:template name="ds_versions_footer" type="simple" name-to-remove="table" set-to-remove="top">
                  <table>
                  </table>
                </v:template>

              </v:data-set>
            </td>
          </tr>
        </v:template>
      </table>
        </div>
  </xsl:template>

  <!--=========================================================================-->
  <xsl:template match="vm:search-dc-template10">
    <div id="10" class="tabContent" style="display: none;">
      <table class="form-body" cellspacing="0">
        <tr>
          <th>
            <v:label for="ts_max" value="Max Results" />
          </th>
          <td>
            <?vsp http (sprintf ('<input type="text" name="ts_max" value="%s" size="5" />', ODRIVE.WA.dc_get (self.search_dc, 'options', 'max', '100'))); ?>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="ts_order" value="Order by" />
          </th>
          <td>
            <select name="ts_order">
              <?vsp
                declare N integer;

                for (N := 0; N < length(self.dir_columns); N := N + 1)
                  if (self.dir_columns[N][3] = 1)
                    http (self.option_prepare(self.dir_columns[N][0], self.dir_columns[N][2], self.dir_order));
              ?>
            </select>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="ts_direction" value="Direction" />
          </th>
          <td>
            <select name="ts_direction">
              <?vsp
                http (self.option_prepare('asc',  'Asc',  self.dir_direction));
                http (self.option_prepare('desc', 'Desc', self.dir_direction));
              ?>
            </select>
          </td>
        </tr>
        <tr>
          <th>
            <v:label for="ts_grouping" value="Group by" />
          </th>
          <td>
            <select name="ts_grouping">
              <?vsp
                declare N integer;

                http (self.option_prepare('', '', self.dir_grouping));
                for (N := 0; N < length(self.dir_columns); N := N + 1)
                  if (self.dir_columns[N][4] = 1)
                    http (self.option_prepare(self.dir_columns[N][0], self.dir_columns[N][2], self.dir_grouping));
              ?>
            </select>
          </td>
        </tr>
        <tr>
          <th/>
          <td>
            <v:check-box name="ts_cloud" xhtml_id="ts_cloud" value="1" />
            <vm:label for="ts_cloud" value="Show tag cloud" />
          </td>
        </tr>
      </table>
        </div>
  </xsl:template>

  <!--=========================================================================-->
  <!-- Auto Versioning -->
  <xsl:template match="vm:autoVersion">
    <vm:if test="self.dav_category = ''">
    <tr id="davRow_version">
      <th>
        <v:label for="dav_autoversion" value="--'Auto Versioning Content'" />
      </th>
      <td>
        <?vsp
          declare tmp any;

          tmp := '';
          if ((self.dav_type = 'R') and (self.command_mode = 10))
            tmp := 'onchange="javascript: window.document.F1.submit();"';
          http (sprintf ('<select name="dav_autoversion" %s disabled="disabled">', tmp));

          tmp := ODRIVE.WA.DAV_GET (self.dav_item, 'autoversion');
          if (isnull(tmp) and (self.dav_type = 'R'))
            tmp := ODRIVE.WA.DAV_GET_AUTOVERSION (ODRIVE.WA.odrive_real_path(self.dir_path));
          http (self.option_prepare('',   'No',   tmp));
          http (self.option_prepare('A',  'Checkout -> Checkin', tmp));
          http (self.option_prepare('B',  'Checkout -> Unlocked -> Checkin', tmp));
          http (self.option_prepare('C',  'Checkout', tmp));
          http (self.option_prepare('D',  'Locked -> Checkout', tmp));

          http ('</select>');
        ?>
      </td>
    </tr>
    </vm:if>
  </xsl:template>

</xsl:stylesheet>
