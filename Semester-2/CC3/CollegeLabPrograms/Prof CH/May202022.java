import java.io.*;

public class May202022 {
  public static void main(String args[]) throws Exception {
    FileHandling.main(args);
  }
}


class FileHandling {
  public static void main(String args[]) throws Exception {
    File fp = new File("MyFolder");
    if (fp.mkdir()) {
      System.out.println("Folder " + fp.getName() + " is successfully created");
    } else {
      System.out.println("Folder " + fp.getName() + " already exists");
    }
    
    File fp2 = new File("MyFolder/MyFile.txt");
    if (fp2.createNewFile()) {
      System.out.println("File " + fp2.getName() + " is successfully created");
    } else {
      System.out.println("File " + fp2.getName() + " already exists");
    }
    System.out.println(fp2.getAbsolutePath());
    
    FileWriter fw = new FileWriter(fp2);
    fw.write(args[0]);
    fw.close();
    
    FileReader fr = new FileReader(fp2);
    int flag;
    while (true) {
      flag = fr.read();
      if (flag != -1) {
        System.out.print((char)flag);
      } else {
        break;
      }
    }
    fr.close();
    fp2.delete();
    fp.delete();
  }
}










































