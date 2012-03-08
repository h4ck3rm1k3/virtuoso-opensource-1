/*
 *  unixodbc.c
 *
 *  $Id: unixodbc.c,v 1.2 2007/08/24 12:31:23 source Exp $
 *
 *  Unix ODBC driver
 *  
 *  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 *  project.
 *  
 *  Copyright (C) 1998-2006 OpenLink Software
 *  
 *  This project is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; only version 2 of the License, dated June 1991.
 *  
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "libutil.h"

/*
 *  Program information (keep libutil happy)
 */
extern char *version;
struct pgm_info program_info = {
    "VIRTODBC",
    NULL,
    NULL,
    0,
    NULL
};
