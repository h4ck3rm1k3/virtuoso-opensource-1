/*
 *  $Id: StatementWrapper.java,v 1.2.2.3 2009/09/18 16:12:13 source Exp $
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

import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLWarning;
import java.sql.SQLException;
import java.sql.Connection;
import java.util.*;

public class StatementWrapper implements Statement, Closeable {

  private Integer r_MaxFieldSize;
  private Integer r_MaxRows;
  private Boolean r_EscapeProcessing;
  private Integer r_QueryTimeout;
  private Integer r_FetchDirection;
  private Integer r_FetchSize;

  protected Statement stmt;
  protected ConnectionWrapper wconn;
#if JDK_VER >= 16
  protected HashMap<Object,Object> objsToClose = new HashMap<Object,Object>();
#else
  protected HashMap objsToClose = new HashMap();
#endif
  protected boolean isClosed = false;


  protected StatementWrapper(ConnectionWrapper _wconn, Statement _stmt) {
    wconn = _wconn;
    stmt = _stmt;
    addLink();
  }

  protected void exceptionOccurred(SQLException sqlEx) {
    if (wconn != null)
      wconn.exceptionOccurred(sqlEx);
  }


  public synchronized void finalize () throws Throwable {
    close();
  }

  protected void addLink() {
    wconn.addObjToClose(this);
  }

  protected void removeLink() {
    wconn.removeObjFromClose(this);
  }

  protected void reset() throws SQLException {
#if JDK_VER >= 16
    HashMap<Object,Object> copy = (HashMap<Object,Object>) objsToClose.clone();
#else
    HashMap copy = (HashMap) objsToClose.clone();
#endif
    try {
      for (Iterator i = copy.keySet().iterator(); i.hasNext(); )
        ((ResultSetWrapper)(i.next())).close();

      objsToClose.clear();
      copy.clear();
      if (r_MaxFieldSize != null) {
        stmt.setMaxFieldSize(r_MaxFieldSize.intValue());
      }
      if (r_MaxRows != null)
        stmt.setMaxRows(r_MaxRows.intValue());
      if (r_EscapeProcessing != null)
        stmt.setEscapeProcessing(r_EscapeProcessing.booleanValue());
      if (r_QueryTimeout != null)
        stmt.setQueryTimeout(r_QueryTimeout.intValue());
      if (r_FetchDirection != null)
        stmt.setFetchDirection(r_FetchDirection.intValue());
      if (r_FetchSize != null)
        stmt.setFetchSize(r_FetchSize.intValue());
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public synchronized void close() throws SQLException {
    if (isClosed)
      return;
    isClosed = true;

    try {
      removeLink();
      if (stmt != null) {
        stmt.close();
        stmt = null;
      }
      wconn = null;
      if (objsToClose != null)
        objsToClose.clear();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public ResultSet executeQuery(String sql) throws SQLException {
    check_close();
    try {
      ResultSet rs = stmt.executeQuery(sql);
      if (rs != null)
        return new ResultSetWrapper(wconn, this, rs);
      else
        return null;
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int executeUpdate(String sql) throws SQLException {
    check_close();
    try {
      return stmt.executeUpdate(sql);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getMaxFieldSize() throws SQLException {
    check_close();
    try {
      return stmt.getMaxFieldSize();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setMaxFieldSize(int max) throws SQLException {
    check_close();
    try {
      if (r_MaxFieldSize == null)  // save the initial MaxFieldSize state
         r_MaxFieldSize = new Integer(getMaxFieldSize());
      stmt.setMaxFieldSize(max);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getMaxRows() throws SQLException {
    check_close();
    try {
      return stmt.getMaxRows();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setMaxRows(int max) throws SQLException {
    check_close();
    try {
      if (r_MaxRows == null)  // save the initial MaxRows state
         r_MaxRows = new Integer(getMaxRows());
      stmt.setMaxRows(max);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setEscapeProcessing(boolean enable) throws SQLException {
    check_close();
    try {
      if (r_EscapeProcessing == null)  // save the initial EscapeProcessing state
         r_EscapeProcessing = new Boolean(true);
      stmt.setEscapeProcessing(enable);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getQueryTimeout() throws SQLException {
    check_close();
    try {
      return stmt.getQueryTimeout();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setQueryTimeout(int seconds) throws SQLException {
    check_close();
    try {
      if (r_QueryTimeout == null)  // save the initial QueryTimeout state
         r_QueryTimeout = new Integer(getQueryTimeout());
      stmt.setQueryTimeout(seconds);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void cancel() throws SQLException {
    check_close();
    try {
      stmt.cancel();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public SQLWarning getWarnings() throws SQLException {
    check_close();
    try {
      return stmt.getWarnings();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void clearWarnings() throws SQLException {
    check_close();
    try {
      stmt.clearWarnings();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setCursorName(String name) throws SQLException {
    check_close();
    try {
      stmt.setCursorName(name);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public boolean execute(String sql) throws SQLException {
    check_close();
    try {
      return stmt.execute(sql);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public ResultSet getResultSet() throws SQLException {
    check_close();
    try {
      ResultSet rs = stmt.getResultSet();
      if (rs != null)
        return new ResultSetWrapper(wconn, this, rs);
      else
        return null;
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getUpdateCount() throws SQLException {
    check_close();
    try {
      return stmt.getUpdateCount();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public boolean getMoreResults() throws SQLException {
    check_close();
    try {
      return stmt.getMoreResults();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setFetchDirection(int direction) throws SQLException {
    check_close();
    try {
      if (r_FetchDirection == null)  // save the initial FetchDirection state
         r_FetchDirection = new Integer(ResultSet.FETCH_FORWARD);
      stmt.setFetchDirection(direction);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getFetchDirection() throws SQLException {
    check_close();
    try {
      return stmt.getFetchDirection();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setFetchSize(int rows) throws SQLException {
    check_close();
    try {
      if (r_FetchSize == null)  // save the initial FetchSize state
         r_FetchSize = new Integer(getFetchSize());
      stmt.setFetchSize(rows);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getFetchSize() throws SQLException {
    check_close();
    try {
      return stmt.getFetchSize();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getResultSetConcurrency() throws SQLException {
    check_close();
    try {
      return stmt.getResultSetConcurrency();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getResultSetType() throws SQLException {
    check_close();
    try {
      return stmt.getResultSetType();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void addBatch(String sql) throws SQLException {
    check_close();
    try {
      stmt.addBatch(sql);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void clearBatch() throws SQLException {
    check_close();
    try {
      stmt.clearBatch();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int[] executeBatch() throws SQLException {
    check_close();
    try {
      return stmt.executeBatch();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public Connection getConnection() throws SQLException {
    check_close();
    return wconn;
  }


#if JDK_VER >= 14
    //-------------------------- JDBC 3.0 ----------------------------------------

  public boolean getMoreResults(int current) throws SQLException {
    check_close();
    try {
      return stmt.getMoreResults(current);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public ResultSet getGeneratedKeys() throws SQLException {
    check_close();
    try {
      ResultSet rs = stmt.getGeneratedKeys();
      if (rs != null)
        return new ResultSetWrapper(wconn, this, rs);
      else
        return null;
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int executeUpdate(String sql, int autoGeneratedKeys)
    throws SQLException
  {
    check_close();
    try {
      return stmt.executeUpdate(sql, autoGeneratedKeys);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int executeUpdate(String sql, int[] columnIndexes) throws SQLException {
    check_close();
    try {
      return stmt.executeUpdate(sql, columnIndexes);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int executeUpdate(String sql, String[] columnNames) throws SQLException {
    check_close();
    try {
      return stmt.executeUpdate(sql, columnNames);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public boolean execute(String sql, int autoGeneratedKeys) throws SQLException {
    check_close();
    try {
      return stmt.execute(sql, autoGeneratedKeys);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public boolean execute(String sql, int[] columnIndexes) throws SQLException {
    check_close();
    try {
      return stmt.execute(sql, columnIndexes);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public boolean execute(String sql, String[] columnNames) throws SQLException {
    check_close();
    try {
      return stmt.execute(sql, columnNames);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public int getResultSetHoldability() throws SQLException {
    check_close();
    try {
      return stmt.getResultSetHoldability();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

#if JDK_VER >= 16
    //------------------------- JDBC 4.0 -----------------------------------
  public boolean isClosed() throws SQLException
  {
    check_close();
    try {
      return stmt.isClosed();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public void setPoolable(boolean poolable) throws SQLException
  {
    check_close();
    try {
      stmt.setPoolable(poolable);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public boolean isPoolable() throws SQLException
  {
    check_close();
    try {
      return stmt.isPoolable();
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public <T> T unwrap(java.lang.Class<T> iface) throws java.sql.SQLException
  {
    check_close();
    try {
      return stmt.unwrap(iface);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

  public boolean isWrapperFor(java.lang.Class<?> iface) throws java.sql.SQLException
  {
    check_close();
    try {
      return stmt.isWrapperFor(iface);
    } catch (SQLException ex) {
      exceptionOccurred(ex);
      throw ex;
    }
  }

#endif
#endif

  protected synchronized void check_close()
    throws SQLException
  {
    if (isClosed)
      throw new VirtuosoException("The statement is closed.",VirtuosoException.OK);
  }

  protected void addObjToClose(Object obj)
  {
    synchronized (objsToClose) {
      objsToClose.put(obj, obj);
    }
  }

  protected void removeObjFromClose(Object obj)
  {
    synchronized (objsToClose) {
      objsToClose.remove(obj);
    }
  }
}
