<?xml version="1.0" encoding="UTF-8"?>
<!--
 -
 -  $Id: twitter_rest_api2rdf.xsl,v 1.1.4.3 2011/10/25 23:36:21 source Exp $
 -
 -  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 -  project.
 -
 -  Copyright (C) 1998-2009 OpenLink Software
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
-->
<!DOCTYPE xsl:stylesheet [
<!ENTITY a "http://www.w3.org/2005/Atom">
<!ENTITY bibo "http://purl.org/ontology/bibo/">
<!ENTITY dc "http://purl.org/dc/elements/1.1/">
<!ENTITY dcterms "http://purl.org/dc/terms/">
<!ENTITY foaf "http://xmlns.com/foaf/0.1/">
<!ENTITY opl "http://www.openlinksw.com/schema/attribution#">
<!ENTITY owl "http://www.w3.org/2002/07/owl#">
<!ENTITY rdf "http://www.w3.org/1999/02/22-rdf-syntax-ns#">
<!ENTITY rdfs "http://www.w3.org/2000/01/rdf-schema#">
<!ENTITY sioc "http://rdfs.org/sioc/ns#">
<!ENTITY sioct "http://rdfs.org/sioc/types#">
<!ENTITY twitter "http://www.openlinksw.com/schemas/twitter#">
<!ENTITY v "http://www.w3.org/2006/vcard/ns#">
<!ENTITY vcard "http://www.w3.org/2001/vcard-rdf/3.0#">
<!ENTITY vi "http://www.openlinksw.com/virtuoso/xslt/">
<!ENTITY xml 'http://www.w3.org/XML/1998/namespace#'>
<!ENTITY xsd "http://www.w3.org/2001/XMLSchema#">
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:a="&a;"
    xmlns:bibo="&bibo;"
	xmlns:dc="&dc;"
	xmlns:dcterms="&dcterms;"
	xmlns:foaf="&foaf;"
    xmlns:opl="&opl;"
    xmlns:owl="&owl;"
	xmlns:rdf="&rdf;"
	xmlns:rdfs= "&rdfs;"
    xmlns:sioc="&sioc;"
    xmlns:sioct="&sioct;"
	xmlns:twitter="&twitter;"
	xmlns:v="&v;"
	xmlns:vcard="&vcard;"
	xmlns:vi="&vi;"
	version="1.0">

	<xsl:output method="xml" indent="yes" omit-xml-declaration="yes" />
	<xsl:param name="baseUri" />
	<xsl:param name="what" />
	<xsl:param name="primary_user_screen_name" />

	<xsl:variable name="resourceURL" select="vi:proxyIRI ($baseUri)"/>
	<xsl:variable  name="docIRI" select="vi:docIRI($baseUri)"/>
	<xsl:variable  name="docproxyIRI" select="vi:docproxyIRI($baseUri)"/>
	<xsl:variable name="providedByIRI" select="concat ('http://twitter.com', '#this')"/>

	<xsl:template match="/">
		<rdf:RDF>
            <!-- Attribution resource -->
	        <foaf:Organization rdf:about="{$providedByIRI}">
	            <foaf:name>Twitter Inc.</foaf:name>
	            <foaf:homepage rdf:resource="http://twitter.com"/>
	        </foaf:Organization>

  		    <xsl:choose>
				<xsl:when test="$what = 'user'">
                    <!-- twitter_user_url typically matches resourceURL -->
                    <xsl:variable name="twitter_user_url" select="vi:proxyIRI(concat('http://twitter.com/', user/screen_name))" />
					<foaf:Document rdf:about="{$docproxyIRI}">
						<dcterms:subject rdf:resource="{$twitter_user_url}" />
				        <sioc:container_of rdf:resource="{$twitter_user_url}"/>
						<foaf:primaryTopic rdf:resource="{$twitter_user_url}" />
				        <owl:sameAs rdf:resource="{$docIRI}"/>
				        <dc:title><xsl:value-of select="user/screen_name"/></dc:title>
					</foaf:Document>
					<xsl:apply-templates select="user" />
				</xsl:when>
				<xsl:when test="$what = 'followers'">
					<xsl:apply-templates select="users/user" />
				</xsl:when>
				<xsl:when test="$what = 'friends'">
					<xsl:apply-templates select="users/user" />
				</xsl:when>
				<xsl:when test="$what = 'favorites'">
					<xsl:apply-templates select="statuses/status" />
				</xsl:when>
				<xsl:when test="$what = 'user_timeline'">
					<xsl:apply-templates select="statuses/status" />
				</xsl:when>
				<xsl:when test="$what = 'status'">
					<xsl:apply-templates select="status" />
				</xsl:when>
			</xsl:choose>
		</rdf:RDF>
	</xsl:template>

	<xsl:template match="user">
		<xsl:if test="$what = 'followers'">
			<rdf:Description rdf:about="{vi:proxyIRI(concat('http://twitter.com/', $primary_user_screen_name))}">
				<twitter:followed_by rdf:resource="{vi:proxyIRI(concat('http://twitter.com/', screen_name))}"/>
			</rdf:Description>
		</xsl:if>
		<xsl:if test="$what = 'friends'">
			<rdf:Description rdf:about="{vi:proxyIRI(concat('http://twitter.com/', $primary_user_screen_name))}">
				<sioc:follows rdf:resource="{vi:proxyIRI(concat('http://twitter.com/', screen_name))}"/>
			</rdf:Description>
		</xsl:if>
		<xsl:call-template name="user"/>
	</xsl:template>

	<xsl:template name="user">
        <xsl:variable name="id" select="id" />
		<foaf:Person rdf:about="{vi:proxyIRI(concat('http://twitter.com/', screen_name))}">
		    <rdf:type rdf:resource="&twitter;User"/>
            <opl:providedBy rdf:resource="{$providedByIRI}" />
            <rdfs:label><xsl:value-of select="name"/></rdfs:label>
			<foaf:name>
				<xsl:value-of select="name" />
			</foaf:name>
			<foaf:nick>
				<xsl:value-of select="screen_name" />
			</foaf:nick>
			<xsl:if test="url != ''">
				<foaf:homepage rdf:resource="{url}" />
			</xsl:if>
			<foaf:img rdf:resource="{profile_image_url}" />
			<twitter:id>
				<xsl:value-of select="id" />
			</twitter:id>
			<xsl:if test="followers_count != ''">
				<twitter:followers_count rdf:datatype="&xsd;integer">
					<xsl:value-of select="followers_count" />
				</twitter:followers_count>
			</xsl:if>
			<xsl:if test="friends_count != ''">
				<twitter:friends_count rdf:datatype="&xsd;integer">
					<xsl:value-of select="friends_count" />
				</twitter:friends_count>
			</xsl:if>
			<xsl:if test="favourites_count != ''">
				<twitter:favorites_count rdf:datatype="&xsd;integer">
					<xsl:value-of select="favourites_count" />
				</twitter:favorites_count>
			</xsl:if>
			<xsl:if test="statuses_count != ''">
				<twitter:statuses_count rdf:datatype="&xsd;integer">
					<xsl:value-of select="statuses_count" />
				</twitter:statuses_count>
			</xsl:if>
			<dcterms:created rdf:datatype="&xsd;dateTime">
				<xsl:value-of select="vi:string2date(created_at)"/>
			</dcterms:created>
			<xsl:if test="location != ''">
			    <vcard:Locality>
				    <xsl:value-of select="location" />
			    </vcard:Locality>
            </xsl:if>
			<foaf:title>
				<xsl:value-of select="description" />
			</foaf:title>
			<owl:sameAs rdf:resource="{concat('http://twitter.com/!#/', screen_name)}"/>
		</foaf:Person>
	</xsl:template>

	<xsl:template match="status">
		<xsl:call-template name="status"/>
	</xsl:template>

	<xsl:template name="status">
		<rdf:Description rdf:about="{vi:proxyIRI(concat('http://twitter.com/', user/screen_name, '/status/', id))}">
			<xsl:call-template name="status_int"/>
		</rdf:Description>

		<foaf:Person rdf:about="{vi:proxyIRI(concat('http://twitter.com/', user/screen_name))}">
		<xsl:if test="starts-with (text, '#Self #WebID #Fingerprint:')">
		    <opl:hasFingerprint>
			<xsl:value-of select="substring-after (text, '#Self #WebID #Fingerprint:')"/>
		    </opl:hasFingerprint>
		</xsl:if>
            <xsl:choose>
                <xsl:when test="$what = 'favorites'">
			        <twitter:has_favorite rdf:resource="{vi:proxyIRI(concat('http://twitter.com/', user/screen_name, '/status/', id))}"/>
                </xsl:when>
                <xsl:otherwise>
			        <twitter:made_tweet rdf:resource="{vi:proxyIRI(concat('http://twitter.com/', user/screen_name, '/status/', id))}"/>
                </xsl:otherwise>
            </xsl:choose>
		</foaf:Person>

		<xsl:if test="in_reply_to_status_id != ''">
			<rdf:Description rdf:about="{vi:proxyIRI(concat('http://twitter.com/', in_reply_to_screen_name, '/status/', in_reply_to_status_id))}">
				<sioc:has_reply rdf:resource="{vi:proxyIRI(concat('http://twitter.com/', user/screen_name, '/status/', id))}"/>
			</rdf:Description>
		</xsl:if>
	</xsl:template>

	<xsl:template name="status_int">
		<rdf:type rdf:resource="&sioct;MicroblogPost"/>
		<rdf:type rdf:resource="&twitter;Tweet"/>
        <opl:providedBy rdf:resource="{$providedByIRI}" />
		<dcterms:created rdf:datatype="&xsd;dateTime">
			<xsl:value-of select="vi:string2date(created_at)"/>
		</dcterms:created>
		<dc:title>
			<xsl:call-template name="add-href">
				<xsl:with-param name="string" select="text"/>
			</xsl:call-template>
		</dc:title>
		<bibo:content>
			<xsl:call-template name="add-href">
				<xsl:with-param name="string" select="text"/>
			</xsl:call-template>
		</bibo:content>
		<dc:source>
			<xsl:value-of select="$baseUri" />
		</dc:source>
		<xsl:if test="in_reply_to_status_id != ''">
			<sioc:reply_of rdf:resource="{vi:proxyIRI(concat('http://twitter.com/', in_reply_to_screen_name, '/status/', in_reply_to_status_id))}"/>
		</xsl:if>
		<dcterms:creator rdf:resource="{vi:proxyIRI(concat('http://twitter.com/', user/screen_name))}"/>
	</xsl:template>

	<xsl:template name="add-href">
		<xsl:param name="string"/>
		<xsl:choose>
			<xsl:when test="starts-with($string, '@')">
				<xsl:variable name="tmp1" select="substring-before($string, ' ')"/>
				<xsl:variable name="tmp2" select="substring-after($string, ' ')"/>
				<xsl:variable name="tmp3" select="concat('&lt;a href=\'', vi:proxyIRI(concat('http://twitter.com/', substring-after($tmp1, '@'))), '\'>', $tmp1, '&lt;/a&gt; ', $tmp2)"/>
				<xsl:value-of select="$tmp3"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$string"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

</xsl:stylesheet>
