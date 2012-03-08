<?xml version="1.0"?>
<!--
 -
 -  $Id: foaf.xsl,v 1.7.2.1 2010/09/20 10:15:20 source Exp $
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
<xsl:stylesheet
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
  xmlns:rdfs="http://www.w3.org/2000/01/rdf-schema#"
  xmlns:dc="http://purl.org/dc/elements/1.1/"
  xmlns:foaf="http://xmlns.com/foaf/0.1/"
  xmlns:vi="http://www.openlinksw.com/ods/"
  xmlns:ods="http://openlinksw.com/ods/1.0/"
  xmlns:rss="http://purl.org/rss/1.0/"
  xmlns:geo="http://www.w3.org/2003/01/geo/wgs84_pos#"
  xmlns:vCard="http://www.w3.org/2001/vcard-rdf/3.0#"
  xmlns:sioc="http://rdfs.org/sioc/ns#"
  xmlns:sioct="http://rdfs.org/sioc/types#"
  xmlns:bio="http://purl.org/vocab/bio/0.1/"
  xmlns:xml="xml"
  version="1.0">

  <xsl:output indent="yes" />
  <xsl:param name="httpHost" select="vi:getHost()"/>

  <xsl:template match="/">
      <xsl:comment>FOAF based XML document generated By OpenLink Virtuoso</xsl:comment>
      <xsl:apply-templates />
  </xsl:template>

  <xsl:template match="rdf:RDF">
      <xsl:copy>
	  <xsl:copy-of select="@*"/>
	  <!--xsl:attribute name="xml:base">http://<xsl:value-of select="$httpHost"/>/dataspace/<xsl:value-of select="foaf:Person/foaf:nick"/>#person</xsl:attribute-->
	  <xsl:apply-templates />
      </xsl:copy>
  </xsl:template>

  <xsl:template match="*">
      <xsl:if test="namespace-uri() = 'http://openlinksw.com/ods/1.0/' and dc:title and local-name(preceding-sibling::ods:*) != local-name(.)">
	  <xsl:variable name="ename" select="local-name(.)"/>
	  <xsl:comment><xsl:value-of select="translate (substring ($ename, 1, 1), 'abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')"/><xsl:value-of select="substring ($ename, 2)"/> Data Space</xsl:comment>
      </xsl:if>
      <xsl:copy>
	  <xsl:copy-of select="@*[local-name()!='about']"/>
	  <xsl:if test="local-name() = 'PersonalProfileDocument'">
	      <xsl:attribute name="rdf:about">http://<xsl:value-of select="$httpHost"/>/dataspace/person/<xsl:value-of select="ancestor::rdf:RDF/foaf:Person/foaf:nick"/>/about.rdf</xsl:attribute>
	      <rdfs:label>
		  <xsl:choose>
		      <xsl:when test="ancestor::rdf:RDF/foaf:Person/foaf:name">
			  <xsl:value-of select="ancestor::rdf:RDF/foaf:Person/foaf:name"/>
		      </xsl:when>
		      <xsl:otherwise>
			  <xsl:value-of select="ancestor::rdf:RDF/foaf:Person/foaf:nick"/>
		      </xsl:otherwise>
		  </xsl:choose>
		  <xsl:text>'s profile</xsl:text>
	      </rdfs:label>
	  </xsl:if>
	  <xsl:if test="(local-name() = 'primaryTopic' or local-name() = 'maker') and @rdf:resource = ''">
	      <xsl:attribute name="rdf:resource">http://<xsl:value-of select="$httpHost"/>/dataspace/<xsl:value-of select="ancestor::rdf:RDF/foaf:Person/foaf:nick"/>#person</xsl:attribute>
	  </xsl:if>
	  <xsl:if test="local-name() = 'Person' and @rdf:about = ''">
	      <xsl:attribute name="rdf:about">http://<xsl:value-of select="$httpHost"/>/dataspace/<xsl:value-of select="foaf:nick"/>#person</xsl:attribute>
	      <!--rdfs:label>
		  <xsl:choose>
		      <xsl:when test="foaf:name">
			  <xsl:value-of select="foaf:name"/>
		      </xsl:when>
		      <xsl:otherwise>
			  <xsl:value-of select="foaf:nick"/>
		      </xsl:otherwise>
		  </xsl:choose>
		  <xsl:text>'s profile</xsl:text>
	      </rdfs:label-->
	  </xsl:if>
	  <xsl:if test="@rdf:about and @rdf:about != ''">
	      <xsl:attribute name="rdf:about"><xsl:value-of select="translate (@rdf:about, ' ', '+')"/></xsl:attribute>
	      <xsl:if test="namespace-uri() = 'http://openlinksw.com/ods/1.0/' and dc:title">
		  <rdfs:label><xsl:value-of select="dc:title"/> Data Space</rdfs:label>
	      </xsl:if>
	  </xsl:if>

	  <xsl:apply-templates />
      </xsl:copy>
  </xsl:template>

  <!--xsl:template match="comment ()">
      <xsl:copy-of select="."/>
  </xsl:template-->

</xsl:stylesheet>