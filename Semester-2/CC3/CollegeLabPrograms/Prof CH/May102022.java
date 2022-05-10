/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 10.05.2022
 */

public class May102022{
  public static void main(String args[]){
    MyThreadDriver.main(new String[]{});
  }
}

class MyThread implements Runnable{
  Thread t;
  MyThread(String threadName){
    t = new Thread(this,threadName);
    //~ try{
      //~ t.join();
    //~ }catch(InterruptedException ie){}
  }
  public void run(){
    for(int i = 0; i < 5; i++){
      System.out.println("Printing from MyThread "+t);
      try{
        Thread.sleep(500);
      }catch(InterruptedException ie){}
    }
  }
}
class MyThreadDriver{
  public static void main(String args[]){
    MyThread myThread1 = new MyThread("T1");
    MyThread myThread2 = new MyThread("T2");
    //~ try{
      //~ myThread1.t.join();
      //~ myThread2.t.join();
    //~ }catch(InterruptedException iEx){
      //~ System.out.println("Interrupted Exception thrown: "+iEx);
    //~ }
    myThread1.t.start();
    try{
      myThread1.t.join();
      //~ myThread2.t.join();
    }catch(InterruptedException iEx){
      System.out.println("Interrupted Exception thrown: "+iEx);
    }
    myThread2.t.start();
    try{
      //~ myThread1.t.join();
      myThread2.t.join();
    }catch(InterruptedException iEx){
      System.out.println("Interrupted Exception thrown: "+iEx);
    }
    System.out.println("Execution of all threads completed");
  }
}
