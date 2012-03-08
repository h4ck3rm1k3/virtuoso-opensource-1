/*
 *  $Id: VirtuosoClob.java,v 1.1.1.1.2.1 2009/08/20 20:13:28 source Exp $
 *
 *  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 *  project.
 *
 *  Copyright (C) 1998-2009 OpenLink Software
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

package virtuoso.jdbc2;

import java.sql.*;
import java.io.*;

/**
 * This is an implementation of a Clob object. It's equivalent to a LONG CHAR SQL
 * type.
 *
 * @version 1.0 (JDBC API 2.0 implementation)
 */
public class VirtuosoClob extends VirtuosoBlob
{
   VirtuosoClob(InputStream is, long length, long index) throws VirtuosoException
   {
      super(is,length,index);
   }

   VirtuosoClob(byte[] array) throws VirtuosoException
   {
      super(array);
   }

   VirtuosoClob(Object obj, long index) throws VirtuosoException
   {
      super(obj,index);
   }

   VirtuosoClob(VirtuosoConnection connection, long ask, long index, long length) throws VirtuosoException
   {
      super(connection,ask,index,length);
   }

}
