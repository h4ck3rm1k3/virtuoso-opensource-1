#!/bin/sh
#
#  $Id: generate_drop_proc.sh,v 1.3.2.2 2010/09/20 10:15:46 source Exp $
#
#  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
#  project.
#
#  Copyright (C) 1998-2009 OpenLink Software
#
#  This project is free software; you can redistribute it and/or modify it
#  under the terms of the GNU General Public License as published by the
#  Free Software Foundation; only version 2 of the License, dated June 1991.
#
#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
#  General Public License for more details.
#
#  You should have received a copy of the GNU General Public License along
#  with this program; if not, write to the Free Software Foundation, Inc.,
#  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
#

echo "select 'WV.WIKI.SILENT_EXEC(''' || 'drop procedure ' || p_name || ''');' from sys_procedures where p_name like 'WV.%.%' and p_name not like 'WV.%.SILENT_EXEC'; " | isql $PORT dba dba | grep drop  > drop_proc.sql
echo "drop procedure WV.WIKI.SILENT_EXEC;" >>  drop_proc.sql