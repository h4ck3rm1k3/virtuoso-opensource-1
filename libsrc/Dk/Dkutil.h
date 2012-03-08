/*
 *  Dkutil.h
 *
 *  $Id: Dkutil.h,v 1.2 2009/04/07 22:00:54 source Exp $
 *
 *  Helper functions
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

#ifndef _DKUTIL_H
#define _DKUTIL_H

BEGIN_CPLUSPLUS

int gpf_notice (const char *file, int line, const char *text);
void get_real_time (timeout_t * time_ret);
long get_msec_real_time (void);
long approx_msec_real_time (void);
void time_add (timeout_t * time1, timeout_t * time2);
int time_gt (timeout_t * time1, timeout_t * time2);

END_CPLUSPLUS
#endif