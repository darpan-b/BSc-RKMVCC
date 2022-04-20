/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 12.04.2022
 */


import java.util.Scanner;

class RightShiftOperator {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number:");
		int n = in.nextInt();
		System.out.println("After right shift (int) = " + (n >>> 1));
		System.out.println("After right shift (long) = " + ((long)n >>> 1));
		System.out.println("After right shift (short) = " + ((short)n >>> 1));
		System.out.println("After right shift (byte) = " + ((byte)n >>> 1));
	}
}

class VarArgs {
	void varArgsTest(int... p){
		System.out.println("Function signature -> void varArgsTest(int... p)");
		System.out.print("Parameters entered = ");
		for(int i = 0; i < p.length; i++){
			System.out.print(p[i]+" ");
		}
		System.out.println();
	}
	void varArgsTest(boolean... p){
		System.out.println("Function signature -> void varArgsTest(boolean... p)");
		System.out.print("Parameters entered = ");
		for(int i = 0; i < p.length; i++){
			System.out.print(p[i]+" ");
		}
		System.out.println();
	}
	
	
	/// Ambiguous as of javac 11.0.14
	/// Not ambiguous as of javac 17.0.1
	/*
	int m1(int... x){
		System.out.println("int");
	}
	double m1(boolean... x){
		System.out.println("double");
	}
	*/
	
	
	/// commented because it's ambiguous, compiler confuses it with
	/// void varArgsTest(int... p)
	/*
	void varArgsTest(int p0, int... p){
		System.out.println("Function signature -> void varArgsTest(int p0, int... p)");
		System.out.print("Parameters entered = ");
		for(int i = 0; i < p.length; i++){
			System.out.print(p[i]+" ");
		}
		System.out.println();
	}
	*/
	public static void main(String args[]) {
		VarArgs obj = new VarArgs();
	}
}

class CommandLineArguments {
	public static void main(String args[]) {
		System.out.println("Number of command line arguments = " + args.length);
		System.out.print("The command line arguments entered = ");
		for(String str : args) System.out.print(str + " ");
		System.out.println();
		int sum = 0;
		for(String str : args) {
			try {
				sum += Integer.parseInt(str);
			} catch(NumberFormatException e) {}
		}
		System.out.println("The sum of integer arguments entered = " + sum);
	}
}

class StaticTest {
	static int p;
	int k;
	
	static {
		p = 32;
		System.out.println("p = " + p);
	}
	
	void getInput() {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the value of p and k respectively: ");
		p = in.nextInt();
	}
	
	public static void main(String args[]) {
		System.out.println(StaticTest.p);
		StaticTest sObj = new StaticTest();
		sObj.getInput();
		System.out.println(StaticTest.p);
	}
}

public class Apr122022 {
	public static void main(String args[]) {
		StaticTest.main(new String[]{});
	}
}
