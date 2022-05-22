import java.io.FileReader;
import java.io.FileWriter;
public class CopyFile {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.out.println("File names not properly specified");
      return;
    }
    FileReader fr = new FileReader(args[0]);
    FileWriter fw = new FileWriter(args[1]);
    while (true) {
      int curChar = fr.read();
      if (curChar == -1) break;
      fw.write((char)curChar);
    }
    System.out.println("Data copied from " + args[0] + " to " + args[1]);
    fr.close();
    fw.close();
  }  
}
