package cl.franciscosolis.onlinegdbuploader

import com.google.gson.JsonObject
import com.google.gson.JsonParser
import java.io.*
import java.net.*

fun main(){
    val files = Utils.lookForFiles(File("."))
    val uploaded = mutableMapOf<String,String>()
    files.forEach {
        uploaded[it.path] = Utils.share(it)
    }

    val file = File("OnlineGDB.md")
    file.writeText("# Files uploaded to [OnlineGDB](https://onlinegdb.com)".plus("\n\n").plus(files.joinToString("\n") {
        "- [${it.path}](${uploaded[it.path]})"
    }))
}

object Utils {

    private val files = mutableListOf<File>()

    fun lookForFiles(folder: File): Array<File> {
        val exclude: String? = System.getenv("EXCLUDE")
        (folder.listFiles() ?: arrayOf()).filter { exclude == null || !exclude.split(";").any { excl -> it.path.contains(excl) } }.forEach {
            if (it.isDirectory) {
                lookForFiles(it)
            } else if (it.extension in arrayOf("c", "cpp")){
                files.add(it)
            }
        }
        return files.toTypedArray()
    }

    fun share(file: File): String = "https://onlinegdb.com/" + JsonParser.parseString(String((URL("https://www.onlinegdb.com/share").openConnection() as HttpURLConnection).apply {
        requestMethod = "POST"
        setRequestProperty("Content-Type", "application/json")
        setRequestProperty("Accept", "application/json")
        setRequestProperty("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36")
        doOutput = true
        outputStream.write(JsonObject().apply {
            addProperty("src", file.readText())
            addProperty("lang",  if(file.extension == "c") "c" else "c++")
            addProperty("stdin", "")
            addProperty("cmd_line_args", "")
            addProperty("type", "S")
            addProperty("input_method", "I")
        }.toString().toByteArray())
        connect()
    }.inputStream.readAllBytes())).asJsonObject.get("uid").asString

}