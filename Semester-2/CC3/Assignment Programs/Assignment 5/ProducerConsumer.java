class Producer extends Thread {
  public String produce() {
    return "Produced String";
  }
  public void run() {
    for (int i = 0; i < 5; i++) {
      System.out.println(produce());
      try {
        sleep(500);
      } catch (InterruptedException ie) {
        System.out.println("Producer thread interrupted");
      }
    }
  }
}
class Consumer extends Thread {
  public String consume() {
    return null;
  }
  public void run() {
    for (int i = 0; i < 5; i++) {
      System.out.println(consume());
      try {
        sleep(500);
      } catch (InterruptedException ie) {
        System.out.println("Consumer thread interrupted");
      }
    }
  }
}
public class ProducerConsumer {
  public static void main(String[] args) {
    Producer p = new Producer();
    Consumer c = new Consumer();
    try {
      p.join();
      c.join();
    } catch (InterruptedException ie) {
      System.out.println("Interrupted exception encountered");
    }
    p.start();
    c.start();
  }
}
