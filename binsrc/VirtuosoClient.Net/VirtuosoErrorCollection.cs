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
// $Id: VirtuosoErrorCollection.cs,v 1.1.1.1 2006/04/11 17:56:12 source Exp $
//

using System;
using System.Collections;

#if ODBC_CLIENT
namespace OpenLink.Data.VirtuosoOdbcClient
#elif CLIENT
namespace OpenLink.Data.VirtuosoClient
#else
namespace OpenLink.Data.Virtuoso
#endif
{
	/// <summary>
	/// Summary description for VirtuosoErrorCollection.
	/// </summary>
	public sealed class VirtuosoErrorCollection : ICollection
	{
		ArrayList items;

		internal VirtuosoErrorCollection()
		{
			items = new ArrayList();
		}

		internal void Add(IVirtuosoError error)
		{
			items.Add(error);
		}

		public int Count
		{
			get { return items.Count; }
		}

		bool ICollection.IsSynchronized
		{
			get { return false; }
		}

		object ICollection.SyncRoot
		{
			get { return items.SyncRoot; }
		}

		public IVirtuosoError this[int index]
		{
			get { return (IVirtuosoError)items[index]; }
		}

		public void CopyTo(Array array, int index)
		{
			items.CopyTo(array, index);
		}

		public IEnumerator GetEnumerator()
		{
			return items.GetEnumerator();
		}
	}
}
