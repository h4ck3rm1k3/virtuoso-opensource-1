/*
 *  Dksesstr.h
 *
 *  $Id: Dksesstr.h,v 1.2 2009/04/07 22:00:54 source Exp $
 *
 *  String sessions
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
 *
 */

#ifdef WIN32
#define PATH_MAX         MAX_PATH
#endif

#ifndef DKSESSTR_H
#define DKSESSTR_H

typedef struct strdevice_s
{
  device_t 		str_device;
  int 			strdev_in_read;
  buffer_elt_t *	strdev_buffer_ptr;
  unsigned 		strdev_is_utf8:1;
} strdevice_t;

#endif