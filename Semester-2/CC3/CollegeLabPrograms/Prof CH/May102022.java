/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 10.05.2022
 */

public class May102022 {
    public static void main(String args[]) {
        ThreadSync.main(new String[]{});
    }
}


class MyThread implements Runnable {
    Thread t;
    MyThread(String threadName) {
        t = new Thread(this, threadName);
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Printing from MyThread " + t);
            try {
                Thread.sleep(500);
            } catch (InterruptedException ie) {}
        }
    }
}
class MyThreadDriver {
    public static void main(String args[]) {
        MyThread myThread1 = new MyThread("T1");
        MyThread myThread2 = new MyThread("T2");

        myThread1.t.start();
        try {
            myThread1.t.join();
        } catch (InterruptedException iEx) {
            System.out.println("Interrupted Exception thrown: " + iEx);
        }
        myThread2.t.start();
        try {
            myThread2.t.join();
        } catch (InterruptedException iEx) {
            System.out.println("Interrupted Exception thrown: " + iEx);
        }

        System.out.println("Execution of all threads completed");
    }
}


class Counter {
    int count = 0;
    public Counter() {}
    public Counter(int l) { count += l; }
    /*
     * if the function is not synchronized, then the value of count after
     * execution of both the threads will not always be equal to 2000.
     */
    public synchronized void increment() { count++; }
}
class ThreadSync {
    public static void main(String args[]) {
        Counter ct = new Counter();
        
        Thread t1 = new Thread(()-> {
            for(int i = 0; i < 1000; i++) {
                ct.increment();
                //~ try {
                    //~ Thread.sleep(200);
                //~ } catch(InterruptedException ie) {}
            }
        }, "MyThread1");
        
        Thread t2 = new Thread(()-> {
            for(int i = 0; i < 1000; i++) {
                ct.increment();
                //~ try {
                    //~ Thread.sleep(500);
                //~ } catch(InterruptedException ie) {}
            }
        }, "MyThread2");

        t1.start();
        t2.start();
        
        try { t1.join(); } catch(InterruptedException ie) {}
        try { t2.join(); } catch(InterruptedException ie) {}
        System.out.println(ct.count);
    }
}
