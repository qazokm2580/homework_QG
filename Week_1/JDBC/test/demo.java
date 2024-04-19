import java.sql.*;

public class demo {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        Class.forName("oracle.jdbc.driver.OracleDriver");

        Connection connection = DriverManager.getConnection('jdbc:mysql://localhost:3306/student, "root", "root");

                String sql = "update message set age =30 where name = 'zhangsan'";
        Statement statement = connection.createStatement();
        int result = statement.executeUpdate(sql);
        System.out.println(result);

        statement.close()
        connection.close()
    }
}