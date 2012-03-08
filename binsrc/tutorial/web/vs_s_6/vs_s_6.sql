--  
--  $Id: vs_s_6.sql,v 1.2 2006/08/16 07:58:13 source Exp $
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
VHOST_REMOVE (vhost=>'test:4444',lhost=>'test:4444',lpath=>'/')
;

VHOST_REMOVE (vhost=>'localhost:4444',lhost=>'localhost:4444',lpath=>'/')
;


VHOST_DEFINE (vhost=>'test:4444',lhost=>'test:4444',
    lpath=>'/',ppath=>'/www2/', def_page=>'index.html', is_brws=>1)
;

VHOST_DEFINE (vhost=>'localhost:4444',lhost=>'localhost:4444', 
    lpath=>'/',ppath=>'/DAV/', is_dav=>1, def_page=>'index.html', is_brws=>1)
;
