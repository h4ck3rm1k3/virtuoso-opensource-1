/*
 *  $Id: LRUCache.java,v 1.1.2.1 2009/08/20 20:13:28 source Exp $
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

import java.util.*;


class LRUCache<K,V> extends LinkedHashMap<K,V>
{
  int maxSize;

  public LRUCache(int size) {
    super(size);
    maxSize = size;
  }

  protected boolean removeEldestEntry(Map.Entry eldest) {
    return (size() > this.maxSize);
  }

}

