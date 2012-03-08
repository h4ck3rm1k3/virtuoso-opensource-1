--  
--  $Id: repl_sub_tpcc.sql,v 1.2.2.1 2009/11/25 22:12:11 source Exp $
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
repl_server ('pub', 'localhost:1111', null);
repl_subscribe ('pub', 'tpcc', null, null, 'dba', 'dba');
repl_init_copy ('pub', 'tpcc', 1);
checkpoint;
sync_repl ();
repl_sched_init ();