#!/bin/sh
#
#  $Id$
#
#  Database recovery tests
#  
#  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
#  project.
#  
#  Copyright (C) 1998-2012 OpenLink Software
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
#  

LOGFILE=tcpt.output
export LOGFILE
. ./test_fn.sh


BANNER "STARTED CPT TEST (tcpt.sh)"

rm -f $DBLOGFILE
rm -f $DBFILE
rm -f *.cpt-after-recov *.trx-after-recov *.cpt
MAKECFG_FILE $TESTCFGFILE $PORT $CFGFILE

STOP_SERVER
START_SERVER $PORT 1000

RUN $INS $DSN 100000 1

RUN $ISQL $DSN PROMPT=OFF VERBOSE=OFF ERRORS=STDOUT -u "FLAG=1" < tcptdt.sql

rm -f $LOCKFILE
#exit;
START_SERVER $PORT 1000

RUN $ISQL $DSN PROMPT=OFF VERBOSE=OFF ERRORS=STDOUT < tcptck.sql

if test $STATUS -ne 0
then
    LOG "***ABORTED: tcptck.sql "
    exit 3
fi

STOP_SERVER
rm -f $DBLOGFILE
rm -f $DBFILE
rm -f *.cpt-after-recov *.trx-after-recov *.cpt

START_SERVER $PORT 1000

RUN $INS $DSN 100000 1

RUN $ISQL $DSN PROMPT=OFF VERBOSE=OFF ERRORS=STDOUT -u "FLAG=2" < tcptdt.sql

rm -f $LOCKFILE
START_SERVER $PORT 1000

RUN $ISQL $DSN PROMPT=OFF VERBOSE=OFF ERRORS=STDOUT < tcptck.sql

if test $STATUS -ne 0
then
    LOG "***ABORTED: tcptck.sql "
    exit 3
fi

STOP_SERVER
CHECK_LOG
rm -f *.cpt-after-recov *.trx-after-recov *.cpt
# DO NOT REMOVE DBFILE we want trecov to start with same file
BANNER "COMPLETED CPT TEST (tcpt.sh)"
