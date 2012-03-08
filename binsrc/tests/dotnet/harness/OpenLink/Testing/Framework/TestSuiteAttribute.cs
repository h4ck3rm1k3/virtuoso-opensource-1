//
//  $Id: TestSuiteAttribute.cs,v 1.1.1.1.2.1 2009/04/20 21:15:32 source Exp $
//
//  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
//  project.
//
//  Copyright (C) 1998-2009 OpenLink Software
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

using System;

namespace OpenLink.Testing.Framework
{
	[AttributeUsage (AttributeTargets.Class, AllowMultiple=false, Inherited=false)]
	public class TestSuiteAttribute : Attribute
	{
		private string name;

		public TestSuiteAttribute (string name)
		{
			this.name = name;
		}

		public string Name
		{
			get { return name; }
		}
	}
}