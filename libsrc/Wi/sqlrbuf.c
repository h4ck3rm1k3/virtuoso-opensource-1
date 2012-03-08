/*
 *  sqlrbuf.c
 *
 *  $Id: sqlrbuf.c,v 1.2.2.1 2009/04/18 21:55:16 source Exp $
 *
 *  VDB SQL Remote query execution.
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

#include "odbcinc.h"
#include "sqlnode.h"
#include "sqlfn.h"
#include "sqlopcod.h"
#include "sqlbif.h"
#include "security.h"
#include "remote.h"
#include "list2.h"
#include "date.h"
#include "datesupp.h"




