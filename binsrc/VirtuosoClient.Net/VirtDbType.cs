//  
//  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
//  project.
//  
//  Copyright (C) 1998-2006 OpenLink Software
//  
//  This project is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the
//  Free Software Foundation; only version 2 of the License, dated June 1991.
//  
//  This program is distributed in the hope that it will be useful, but
//  WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
//  General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write to the Free Software Foundation, Inc.,
//  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//  
//  
//
// $Id: VirtDbType.cs,v 1.1.1.1.2.1 2009/06/15 13:24:12 source Exp $
//

#if ODBC_CLIENT
namespace OpenLink.Data.VirtuosoOdbcClient
#elif CLIENT
namespace OpenLink.Data.VirtuosoClient
#else
namespace OpenLink.Data.Virtuoso
#endif
{
	public enum VirtDbType
	{
		Integer,
		SmallInt,
		Double,
		Float = Double,
		Real,
		Numeric,
		Decimal = Numeric,
		Date,
		Time,
		DateTime,
		TimeStamp,
		Char,
		VarChar,
		LongVarChar,
		NChar,
		NVarChar,
		LongNVarChar,
		Binary,
		VarBinary,
		LongVarBinary,
		Xml,
		BigInt,
		Any,
	}
}