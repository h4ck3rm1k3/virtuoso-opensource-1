<?xml version="1.0"?>
<!--
 -
 -  $Id: map_control.xsl,v 1.5.2.1 2010/09/20 10:15:07 source Exp $
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
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
  xmlns:v="http://www.openlinksw.com/vspx/"
  xmlns:vm="http://www.openlinksw.com/vspx/community/">

  <!--
  Displays a map using the google maps
  Params:
     sql
       This is the SQL query to return the following columns for each point in the map:
         _LNG REAL : the longitude as a real value
         _LAT REAL : the latitude as a real value
	 _KEY_VAL ANY : The column whose value is compared to the 'key-val' value to find the center of the map
	 EXCERPT : the text to go into the bubble window
     balloon-inx : the index (1 based) of the EXCERPT column in the result set
     lat-inx : the index (1 based) of the _LAT column in the result set
     lng-inx : the index (1 based) of the _LNG column in the result set
     key-name-inx : the index (1 based) of the _KEY_VAL column in the result set
     key-val : the value to compare to the _KEY_VAL column
     base_url : the base uri for the marker icon
     div-id : the HTTP id of the DIV section to put the map in.
  -->
  <xsl:template match="vm:map-control_org">
   <![CDATA[
  <script
       src="http://maps.google.com/maps?file=api&amp;v=1&amp;key=<?U WA_MAPS_GET_KEY () ?>"
       type="text/javascript" >
      </script>

  <script
       src="<?V WS.WS.EXPAND_URL (]]><xsl:value-of select="@base_url" /><![CDATA[, '/community/public/js/map_control.js') ?>"
       type="text/javascript" >
      </script>
      ]]>
  &lt;?vsp
    declare _inst_id integer;
    declare _sid, _realm varchar;
    _sid := self.sid;
    _realm := self.realm;
    
    WA_MAPS_AJAX_SET_VALS_GET_ID (
      _inst_id,
      <xsl:value-of select="@sql" />,
      <xsl:value-of select="@balloon-inx" />,
      <xsl:value-of select="@lat-inx" />,
      <xsl:value-of select="@lng-inx" />,
      <xsl:value-of select="@key-name-inx" />,
      <xsl:value-of select="@key-val" />,
      <xsl:value-of select="@base_url" />,
      _sid,
      _realm
      );
    commit work;
  ?&gt;
  <![CDATA[
  <script
       type="text/javascript" >
  function onLoad ()
  {
      zoom_level=]]><xsl:value-of select="@zoom" /><![CDATA[;
      initMap (
	"]]><xsl:value-of select="@div_id"/><![CDATA[",
	"<?V WS.WS.EXPAND_URL (]]><xsl:value-of select="@base_url" /><![CDATA[ , ]]><xsl:value-of select="@wa_home_local" /><![CDATA[||'search_ajax.vsp') ?>",
	"<?V WS.WS.EXPAND_URL (]]><xsl:value-of select="@wa_home_local" /><![CDATA[, 'images/icons') ?>",
	"<?V _inst_id ?>",zoom_level);
  }
  window.onload=onLoad;
  </script>
  ]]>
 </xsl:template>
 <xsl:template match="vm:map-control">

&lt;?vsp

  declare rendered_javascript any;
  rendered_javascript:=string_output();
  
  declare _lat_inx,_lng_inx,_key_name_inx,_balloon_inx,_zoom integer;
  _lat_inx:=<xsl:value-of select="@lat-inx" />;
  _lng_inx:=<xsl:value-of select="@lng-inx" />;
  _key_name_inx:=<xsl:value-of select="@key-name-inx" />;
  _balloon_inx:=<xsl:value-of select="@balloon-inx" />;
  _zoom:=<xsl:value-of select="@zoom" />;
  
  declare _sql,_key_val varchar;
  _sql:=<xsl:value-of select="@sql" />;
  _key_val:='<xsl:value-of select="@key-val" />';
  
  declare group_inx integer;
  group_inx:=1;

  declare markericon_path,markericon_width,markericon_height varchar;
  markericon_path:=WA_LINK (0, '/ods/images/icons/user_16.png');
  markericon_width:='16';
  markericon_height:='16';

  declare center_lat, center_lng varchar;
  center_lat := NULL;
  center_lng := NULL;

  declare hndl, row any;
   
  http('var markersArr = [];var user_dshtml;\r\n',rendered_javascript);
  

  exec (_sql, NULL, NULL, vector (), 0, NULL, NULL, hndl);
  while (0 = exec_next (hndl, NULL, NULL, row))
  {
      declare _baloon_col varchar;
      declare _lat, _lng varchar;
      declare _count integer;
      declare _key_data any;

      _baloon_col := row[_balloon_inx - 1];
      _lat := sprintf ('%.6f', row[_lat_inx - 1]);
      _lng := sprintf ('%.6f', row[_lng_inx - 1]);
      _key_data := row[_key_name_inx - 1];


      if (_key_data = _key_val )
      {
          center_lat := _lat;
          center_lng := _lng;
      }
      
      http (sprintf('user_dshtml=''%s'';',replace(_baloon_col,'''','`')),rendered_javascript);
      http (sprintf('commonMapObj.addMarker(%d,%s,%s,''%s'',%s,%s,ref(commonMapObj,user_dshtml));',group_inx,_lat,_lng,markericon_path,markericon_width,markericon_height),rendered_javascript);
      http (sprintf('markersArr.push([%s,%s]);\r\n',_lat,_lng),rendered_javascript);
  }
  exec_close (hndl);

  
  if(_zoom=0){
      http ('commonMapObj.optimalPosition(markersArr);\r\n',rendered_javascript);
  }else{
      http (sprintf('commonMapObj.centerAndZoom(%s,%s,%d);\r\n',center_lat,center_lng,_zoom),rendered_javascript);
  }

declare lines any;
lines:=vector();
lines:=http_request_header();

?&gt;
<![CDATA[
<script  type="text/javascript">

ODSInitArray.push(mapInitPrepare);

function mapInitPrepare()
{
  if (typeof(window.mapInit) == "function")
    {
      OAT.Loader.loadFeatures(["gmaps","ymaps"], function(){setTimeout(mapInit,60)});
    };

  return;
}

var MAX_ZOOM_LEVEL = 15;
var BURLINGTON_LAT = 42.490;
var BURLINGTON_LNG = -71.19;


function ref(_map,user_dshtml){
 		return function(marker) {

        var user_div=OAT.Dom.create("div");
        user_div.innerHTML = user_dshtml;

				_map.closeWindow();

        _map.openWindow(marker,user_div);
      };
}

function mapInit(){
     var changeMapServiceTo='<?V get_keyword('switchmapto', self.vc_event.ve_params,'') ?>';

      if(typeof(OAT.MapData.TYPE_G)=='undefined')
      { 
        sleep(30);
      }

     var providerType=OAT.MapData.TYPE_G;
     if(changeMapServiceTo=='yahoo' && window.YMAPPID!=0){
         providerType=OAT.MapData.TYPE_Y;
     };
      
     
     var containerDiv=document.getElementById(']]><xsl:value-of select="@div_id" /><![CDATA[');
     
     if(typeof(containerDiv)!='undefined')
     {
   
       var mapOptObj = {
	                      fix:OAT.MapData.FIX_ROUND1,
	                      fixDistance:20,
	                      fixEpsilon:0.5
                       };
       var commonMapObj= new OAT.Map(containerDiv,providerType,mapOptObj);
       commonMapObj.centerAndZoom(BURLINGTON_LAT,BURLINGTON_LNG,MAX_ZOOM_LEVEL);
       commonMapObj.addTypeControl();
       commonMapObj.addMapControl();
       commonMapObj.setMapType(OAT.MapData.MAP_HYB);
       <?vsp http(string_output_string(rendered_javascript)); ?>
     }else{
        alert('Please define a div container for the map control.');
        return;
     };

      var mappingServiceSwitch=OAT.Dom.create("a");
      mappingServiceSwitch.id='mappingServiceSwitch';

      var urlPlusSwitchParam;


      if (document.location.href.indexOf('?')>-1)
      {
          urlPlusSwitchParam=document.location.href+'&';
          
          if(document.location.href.indexOf('switchmapto=')>-1){
             var urlBefore,urlAfter;
             urlBefore=document.location.href.substring(0,document.location.href.indexOf('switchmapto='));
             urlAfter=document.location.href.substring(document.location.href.indexOf('switchmapto='),document.location.href.length);
             if(urlAfter.indexOf('&')>-1){
               urlAfter=urlAfter.substring(urlAfter.indexOf('&')+1,urlAfter.length);
             }else urlAfter='';
             
             urlPlusSwitchParam=urlBefore
             
             if(urlPlusSwitchParam.substring(urlPlusSwitchParam.length-1,urlPlusSwitchParam.length)!='&') urlPlusSwitchParam=urlPlusSwitchParam+'&';
             
             urlPlusSwitchParam=urlPlusSwitchParam+urlAfter;
             
             if(urlPlusSwitchParam.substring(urlPlusSwitchParam.length-1,urlPlusSwitchParam.length)!='&') urlPlusSwitchParam=urlPlusSwitchParam+'&';
          }
      
      }else{
       urlPlusSwitchParam=document.location.href+'?';
      }
     
     if(changeMapServiceTo=='yahoo'){
        
         mappingServiceSwitch.href = urlPlusSwitchParam+'switchmapto=google';
         mappingServiceSwitch.innerHTML='Use Google Mapping Service';
         containerDiv.parentNode.appendChild(mappingServiceSwitch);
      }else if( changeMapServiceTo!='YAHOO' && window.YMAPPID!=0){
         mappingServiceSwitch.href = urlPlusSwitchParam+'switchmapto=yahoo';
         mappingServiceSwitch.innerHTML='Use Yahoo Mapping Service';
         containerDiv.parentNode.appendChild(mappingServiceSwitch);
        
      }

}  
  

</script>
]]>
</xsl:template>

</xsl:stylesheet>
