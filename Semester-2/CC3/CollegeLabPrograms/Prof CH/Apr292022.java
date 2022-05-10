/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 29.04.2022
 */

public class Apr292022 {
  public static void main(String args[]) { MultiThreading.main(new String[]{}); }
}


/* Demonstrating multi-threading */
class MyThread extends Thread {
  MyThread()
  {
    super();
    start();
  }
  
  @Override
  public void run()
  {
    try {
      for (int i = 0; i < 5; i++) {
        System.out.println("Inside MyThread class " + i);
        sleep(1000);
      }
    } catch (InterruptedException e) {
      System.out.println("Inside MyThread class exception found: " + e);
    }
  }
}

class Shuto implements Runnable {
  @Override
  public void run()
  {
    try {
      for (int i = 0; i < 5; i++) {
        System.out.println("Inside Shuto class implementing Runnable interface " + i);
        Thread.sleep(1000);
      }
    } catch (InterruptedException e) {
      System.out.println("Inside Shuto class exception found: " + e);
    }
  }
}

class MyThread2 extends Thread {
  MyThread2()
  {
    super();
    start();
  }
  
  @Override
  public void run()
  {
    try {
      for (int i = 0; i < 5; i++) {
        System.out.println("Inside MyThread2 class " + i);
        sleep(1000);
      }
    } catch (InterruptedException e) {
      System.out.println("Inside MyThread2 class exception found: " + e);
    }
  }
}

class MultiThreading {
  public static void main(String args[])
  {
    MyThread thread = new MyThread();        // extending Thread class
    System.out.println("Priority of thread = " + thread.getPriority());
    
    Shuto shuto = new Shuto();               // implementing Runnable interface
    Thread shutoThread = new Thread(shuto);
    shutoThread.start();
    System.out.println("Priority of secondThread = " + shutoThread.getPriority());
    
    MyThread2 thread2 = new MyThread2();
    System.out.println("Priority of thread2 = " + thread2.getPriority());
    
    try {                                    // main thread  
      for (int i = 0; i < 5; i++) {
        System.out.println("Inside MultiThreading class " + i);
        Thread.sleep(1000);
      }
    } catch (InterruptedException e) {
      System.out.println("Inside MultiThreading class exception found: " + e);
    }
  }
}
