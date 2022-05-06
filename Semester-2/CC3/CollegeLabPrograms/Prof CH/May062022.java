/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 06.05.2022
 */

public class May062022
{
	public static void main(String args[])
	{
		Driver.main(new String[]{});
	}
}


class MyThread0 implements Runnable
{
	Thread t;
	MyThread0(String name)
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
		MyThread0 myThread1=new MyThread0("Thread 1");
		try
		{
			System.out.println(myThread1.t.isAlive());
			myThread1.t.join();
		}
		catch(InterruptedException e)
		{
			System.out.println("Caught exception in thread "+myThread1.t);
		}
		MyThread0 myThread2=new MyThread0("Thread 2");
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


class Meow
{
	void meow()
	{
		System.out.println("meow");
		System.out.println(Thread.currentThread());
		try
		{
			Thread.sleep(500);
		}
		catch(InterruptedException ie){ }
	}
}
class MyThread implements Runnable
{
	Thread t;
	Meow m;
	MyThread(String name,Meow mm)
	{
		t=new Thread(this,name);
		m=mm;
	}
	@Override
	public void run()
	{
		synchronized(m)
		{
			for(int i=0;i<5;i++) m.meow();
		}	
	}
}
class Driver
{
	public static void main(String args[])
	{
		Meow m=new Meow();
		MyThread myThread1=new MyThread("t1",m);
		MyThread myThread2=new MyThread("t2",m);
		
		myThread1.t.start();
		myThread2.t.start();

		try
		{
			myThread1.t.join();
			myThread2.t.join();
		}
		catch(InterruptedException e)
		{
		}
		System.out.println(myThread1.t.isAlive());
		System.out.println(myThread2.t.isAlive());
		System.out.println(Thread.currentThread());
	}

}
