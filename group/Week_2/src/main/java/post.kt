import java.net.URL

object Main {
    @Throws(Exception::class)
    fun main(args: Array<String?>?) {
        val url: URL = URL("https://myword.moity-soeoe.xyz/login")
        val con: HttpURLConnection = url.openConnection() as HttpURLConnection
        con.setRequestMethod("POST")
        con.setRequestProperty("Content-Type", "application/json")
        val requestBody = "username=qgstudio&password=qgstudio"
        con.setDoOutput(true)
        val outputStream: DataOutputStream = DataOutputStream(con.getOutputStream())
        outputStream.writeBytes(requestBody)
        outputStream.flush()
        outputStream.close()
        val responseCode: Int = con.getResponseCode()
        System.out.println("Response Code : " + response.getStatusLine().getStatusCode())

        // 输出响应内容
        if (responseEntity != null) {
            System.out.println("Response content: " + EntityUtils.toString(responseEntity, "UTF-8"))
        }

        val responseCode: Int = con.getResponseCode()
        // 处理响应码和其他逻辑...
    }
}