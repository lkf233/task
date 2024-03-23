package util;

import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

abstract public class JDBCUtils {
    private static String driver = null;
    private static String url = null;
    private static String userName = null;
    private static String password = null;

    static {
        try {

            //读取配置文件
            InputStream asStream = JDBCUtils.class.getResourceAsStream("/db.properties");
            Properties properties = new Properties();

            properties.load(asStream);

            driver = properties.getProperty("driver");
            url = properties.getProperty("url");
            userName = properties.getProperty("username");
            password = properties.getProperty("password");


            //驱动只要加载一次
            Class.forName(driver);

        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }

    }

    //获取连接
    public static Connection getCollection() throws SQLException {
        return DriverManager.getConnection(url, userName, password);
    }

    //释放资源
    public static void release(Connection conn, Statement st, ResultSet rs) throws SQLException {
        if (rs != null) {
            rs.close();
        }

        if (st != null) {
            st.close();
        }
        if (conn != null) {
            conn.close();
        }

    }


}
