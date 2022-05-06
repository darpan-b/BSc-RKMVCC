import java.io.*;
import java.util.*;

public class May062022
{
	public static void main(String args[])
	{
		MyThread.main(new String[]{});
	}
}

class MyThread implements Runnable
{
	Thread t;
	MyThread(String name)
	{
		t=new Thread(this,name);
		t.start();
	}
	public void run()
	{
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("Currently running thread "+t+" value of i is "+i);
				Thread.sleep(1000);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Caught exception in thread "+t);
		}
	}
	public static void main(String args[])
	{
		MyThread myThread1=new MyThread("Thread 1");
		try
		{
			System.out.println(myThread1.t.isAlive());
			myThread1.t.join();
		}
		catch(InterruptedException e)
		{
			System.out.println("Caught exception in thread "+myThread1.t);
		}
		MyThread myThread2=new MyThread("Thread 2");
		try
		{
			myThread2.t.join();
		}
		catch(InterruptedException e)
		{
			System.out.println("Caught exception in thread "+myThread2.t);
		}
		System.out.println(myThread1.t.isAlive());
		System.out.println(myThread2.t.isAlive());
		System.out.println(Thread.currentThread());
	}
}
