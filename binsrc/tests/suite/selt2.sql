--
--  selt2.sql
--
--  $Id: selt2.sql,v 1.1.1.1.2.1 2010/01/25 23:27:37 source Exp $
--
--  checkpoint errors #2.

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

set autocommit manual;
update t1 set fi2 = 222 where row_no = 1000;
select fi2, count (*), avg (fi2), sum (fi2)  from t1 group  by fi2;
commit work;