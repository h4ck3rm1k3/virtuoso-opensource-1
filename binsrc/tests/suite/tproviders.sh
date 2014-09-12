#!/bin/sh
#
#  $Id$
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

LOGFILE=`pwd`/tproviders.output
export LOGFILE
. ./test_fn.sh
 
CURRDIR=`pwd`
JENADIR="../../jena"
SESAME2DIR="../../sesame2"

BANNER "STARTED JENA & SESAME2 PROVIDERS TESTS (tproviders.sh)"

SHUTDOWN_SERVER

# INITIAL CHECKS
#if [ ! -x lib/arq.jar ]
#then
#  BANNER "No jars form JENA_CLASSPATH.  Exiting ..."
#  CHECK_LOG
#  BANNER "COMPLETED JENA & SESAME2 PROVIDERS TESTS (tproviders.sh)"
#  exit 0
#fi
# FIXME


rm -f $DELETEMASK

MAKECFG_FILE $TESTCFGFILE $PORT $CFGFILE

NIGHTLY_PORT=$PORT
export NIGHTLY_PORT

START_SERVER $PORT 1000 

#
#   Run Jena tests
#
cd $JENADIR

RUN make
if test $STATUS -ne 0
then
    LOG "***FAILED: Jena compile"
else
    LOG "PASSED: Jena compile"
fi

RUN make run-tests
if test $STATUS -ne 0
then
    LOG "***FAILED: Jena provider JUnit tests"
else
    LOG "PASSED: Jena provider JUnit tests"
fi

cd $CURRDIR


#
#   Run Sesame2 tests
#
cd $SESAME2DIR

RUN make
if test $STATUS -ne 0
then
    LOG "***FAILED: Sesame2 compile"
else
    LOG "PASSED: Sesame2 compile"
fi

RUN make run-tests
if test $STATUS -ne 0
then
    LOG "***FAILED: Sesame2 suite"
else
    LOG "PASSED: Sesame2 suite"
fi

cd $CURRDIR

SHUTDOWN_SERVER

CHECK_LOG

BANNER "COMPLETED JENA & SESAME2 PROVIDERS TESTS (tproviders.sh)"
