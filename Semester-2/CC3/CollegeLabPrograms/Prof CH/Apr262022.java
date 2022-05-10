/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 26.04.2022
 */

public class Apr262022 {
	public static void main(String args[]) throws MyException {
		MyExceptionDemo.main(new String[]{});
	}
}

class ExceptionDemo {
	public static void main(String args[]) {
		try {
			int k = 5/0;
			int arr[] = new int[2];
			arr[2]=60;
		}catch(ArithmeticException ae){
			System.out.println("ArithmeticException found = " + ae);
		}catch(NumberFormatException nfe){
			System.out.println("NumberFormatException found = " + nfe);
		}catch(Exception e){
			throw e;
		} finally {
			System.out.println("Finally executed");
		}
		
		try{
			try{
				try{
					int f = 6/0;
					System.out.println("Meow");
				}catch(Exception e){
					throw e;
				}
			}catch(Exception e){
				throw e;
			}
		}catch(Exception e){
			throw e;
		}
		finally{
			System.out.println("Woof!");
		}

		try {
			System.out.println("Try with just finally");
		}finally{
			System.out.println("My finally");
		}
		
	}
}

class MyException extends Exception {
	MyException() {
		System.out.println("My exception executed");
	}
}
class MyExceptionDemo {
	public static void main(String args[]){
		try{
			throw new MyException();
		}catch(MyException me){
			System.out.println("My Exception thrown");
		}
	}
}


/**
 * problem: to make your own exception such that it executes whenever p > 20
 */
// TODO
class MyException2 extends Exception {
	MyException() {
	}
}




