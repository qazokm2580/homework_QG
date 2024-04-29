
import java.net.URL;
import java.net.HttpURLConnection;
import java.io.*;

public class main {
    public static void main(String[] args) throws Exception {
        URL url = new URL("http://localhost:8080/LoginServlet"); 
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        con.setRequestMethod("POST");
        con.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
        String requestBody = "username=1&password=123456";
        con.setDoOutput(true);
        DataOutputStream outputStream = new DataOutputStream(con.getOutputStream());
        outputStream.writeBytes(requestBody);
        outputStream.flush();
        outputStream.close();
        int responseCode = con.getResponseCode();
        System.out.println("Response Code: " + responseCode);
    }
}