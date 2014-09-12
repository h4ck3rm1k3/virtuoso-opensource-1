rem  
rem  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
rem  project.
rem  
rem  Copyright (C) 1998-2012 OpenLink Software
rem  
rem  This project is free software; you can redistribute it and/or modify it
rem  under the terms of the GNU General Public License as published by the
rem  Free Software Foundation; only version 2 of the License, dated June 1991.
rem  
rem  This program is distributed in the hope that it will be useful, but
rem  WITHOUT ANY WARRANTY; without even the implied warranty of
rem  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
rem  General Public License for more details.
rem  
rem  You should have received a copy of the GNU General Public License along
rem  with this program; if not, write to the Free Software Foundation, Inc.,
rem  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
rem  
rem  
@echo off

del demo.db
del demo.trx
del demo.log

virtuoso -I demo -S create -c mkdemo
virtuoso -I demo -S start
isql localhost:1112 PROMPT=OFF VERBOSE=OFF <mkdemo.sql >NUL
isql localhost:1112 PROMPT=OFF VERBOSE=OFF EXEC=checkpoint >NUL
isql localhost:1112 PROMPT=OFF VERBOSE=OFF EXEC=shutdown >NUL
virtuoso -I demo -S delete

del demo.trx
del demo.log
