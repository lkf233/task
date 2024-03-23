package util;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

abstract public class CRUDUtils {

    public static int update(String sql, Object... params) throws SQLException {

        Connection conn = JDBCUtils.getCollection();
        PreparedStatement st = null;

        try {
            st = conn.prepareStatement(sql);
            setParams(st, params);
            return st.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            JDBCUtils.release(conn, st, null);
        }
    }

    public static List<Map<String, Object>> querryMap(String sql, Object... params) throws SQLException {
        Connection conn = null;
        PreparedStatement st = null;
        ResultSet rs = null;

        try {
            conn = JDBCUtils.getCollection();
            st = conn.prepareStatement(sql);
            rs = st.executeQuery();
            ResultSetMetaData metaData = rs.getMetaData();
            ArrayList<Map<String, Object>> maps = new ArrayList<>();
            while (rs.next()) {

                HashMap<String, Object> map = new HashMap<>();
                for (int i = 1; i < metaData.getColumnCount(); i++) {
                    map.put(metaData.getColumnName(i), rs.getObject(i));
                }
                maps.add(map);
                return maps;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            JDBCUtils.release(conn, st, rs);
        }
        return null;

    }

    private static void setParams(PreparedStatement st, Object... params) throws SQLException {
        if (params != null) {
            for (int i = 1; i <= params.length; i++) {
                st.setObject(i, params[i]);
            }
        }
    }


}
