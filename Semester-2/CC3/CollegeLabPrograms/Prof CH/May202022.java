/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 20.05.2022
 */

import java.io.*;

public class May202022 {
  public static void main(String args[]) throws Exception {
    MyFileHandling.main(args);
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

/* Write a program to copy content from  one file to another, in encrypted form.
Then decrypt it to a separate file in decrypted form */
class MyFileHandling {
  public static void main(String[] args) throws Exception {
    FileReader fr = new FileReader("/home/first/Documents/715DBCC3Java/FolderMay202022/File1.txt");
    FileWriter fw = new FileWriter("/home/first/Documents/715DBCC3Java/FolderMay202022/File2.txt");
    while (true) {
      int curChar = fr.read();
      if (curChar != -1) {
        fw.write((char)(curChar + 69));
      } else {
        break;
      }
    }
    fr.close();
    fw.close();

    fr = new FileReader("/home/first/Documents/715DBCC3Java/FolderMay202022/File2.txt");
    fw = new FileWriter("/home/first/Documents/715DBCC3Java/FolderMay202022/File3.txt");
    while (true) {
      int curChar = fr.read();
      if (curChar != -1) {
        fw.write((char)(curChar - 69));
      } else {
        break;
      }
    }
    fr.close();
    fw.close();
  }
}
