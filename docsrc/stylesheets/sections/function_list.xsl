<?xml version='1.0'?>
<!--
 -  
 -  $Id: function_list.xsl,v 1.2 2006/08/15 22:09:22 source Exp $
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
 -  
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'>

<xsl:output method="text"/>

	<xsl:param name="imgroot">../images/</xsl:param>


<xsl:template match="/"><xsl:apply-templates select="/book"/></xsl:template>

<xsl:template match="/book">
<xsl:apply-templates select="/book/chapter[@id='functions']/refentry" />
</xsl:template>

<xsl:template match="refentry">
<xsl:value-of select="@id" />
<xsl:text>
</xsl:text>
</xsl:template>

<xsl:template match="*" />

</xsl:stylesheet>