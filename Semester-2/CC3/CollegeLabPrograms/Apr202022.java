/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 20.04.2022
 */

public class Apr202022 {
	public static void main(String args[]) {
		InnerInterfaceDemo.main(new String[]{});
	}
}


/* 
 * nested interfaces 
 */
interface OuterInterface {
	interface InnerInterface {
		void displayInner();
	}
	void displayOuter();
}
class InterfaceDemo1 implements OuterInterface {
	// InterfaceDemo1 needn't contain an implementation of displayInner()
	// It can, but that is not compulsory.
	// See InterafaceDemo2 for elaboration.
	public void displayOuter() {
		System.out.println("Inside displayOuter method in InterfaceDemo1 class");
	}
	
	public static void main(String args[]) {
		new InterfaceDemo1().displayOuter();
	}
}
class InterfaceDemo2 implements OuterInterface.InnerInterface {
	public void displayOuter() {
		System.out.println("Inside displayOuter method in InterfaceDemo2 class");
	}
	public void displayInner() {
		System.out.println("Inside displayInner method in InterfaceDemo2 class");
	}
	
	public static void main(String args[]) {
		InterfaceDemo2 id2 = new InterfaceDemo2();
		id2.displayOuter();
		id2.displayInner();
	}
}

/* 
 * lambda interfaces 
 */
interface SingleMethodInterface {
	int mySum(int a, int b);
}
interface SingleMethodInterface2 {
	void meow();
}
class LambdaInterfaceDemo {
	public static void main(String args[]){ 
		SingleMethodInterface lambdaF = (a,b) -> {
			// contains body of mySum method
			// under braces coz it is multi-line method
			a *= 3;
			b *= 2;
			return a+b;
		};
		
		// return statements are internally multi-line(?) which is why single line
		// lambda functions do not work for return statements
		SingleMethodInterface lambdaF2 = (a,b) -> { return a+b; };
		SingleMethodInterface2 lambdaF3 = () -> System.out.println("meow");
		
		System.out.println(lambdaF.mySum(2,3));
		System.out.println(lambdaF2.mySum(2,3));
		lambdaF3.meow();
	}
}


/*
 * interface polymorphism
 */
interface BaseInterface {
	void displayBase();
}
interface ChildInterface extends BaseInterface {
	void displayChild();
}
class InterfacePolymorphism1 implements BaseInterface{
	
	public void displayBase() {
		System.out.println("Inside displayBase method in InterfacePolymorphism1 class");
	}
	
	public static void main(String args[]){
		new InterfacePolymorphism1().displayBase();
	}
}
class InterfacePolymorphism2 implements ChildInterface {
	// displayBase() method should compulsorily be implemented here.
	// displayChild() method needn't be implemented in InterfacePolymorphism1 class.
	public void displayBase() {
		System.out.println("Inside displayBase method in InterfacePolymorphism2 class");
	}
	public void displayChild() {
		System.out.println("Inside displayChild method in InterfacePolymorphism2 class");
	}
	
	public static void main(String args[]){
		new InterfacePolymorphism2().displayBase();
		new InterfacePolymorphism2().displayChild();
	}
}
class InterfacePolymorphism3 {
	public static void main(String args[]) {
		ChildInterface referenceObject = new InterfacePolymorphism2();
		BaseInterface referenceObject2 = new InterfacePolymorphism2();
		// incompatible, rest all are compatible:
		// ChildInterface referenceObject3 = new InterfacePolymorphism1();
		BaseInterface referenceObject4 = new InterfacePolymorphism1();
	}
}


/*
 * implementing multiple interfaces in single class
 */
interface AdditionInterface {
	int add(int a,int b);
}
interface SubtractionInterface {
	int sub(int a,int b);
}
class MyCalculator implements AdditionInterface,SubtractionInterface {
	public int add(int a,int b) {
		return a+b;
	}
	public int sub(int a,int b) {
		return a-b;
	}
	
	public static void main(String args[]) {
		MyCalculator cal = new MyCalculator();
		System.out.println("Sum = "+cal.add(5,8));
		System.out.println("Difference = "+cal.sub(100,101));
	}
}


/*
 * interfaces inside a class
 */
class InnerInterfaceDemo {
	interface MyInnerInterface {
		void mult(int a,int b);
		void div(int a,int b);
	}
	
	public void mult(int a,int b){
		System.out.println("Product = "+a*b);
	}
	public void div(int a,int b){
		System.out.println("Quotient = "+a/b);
	}
	
	interface MyInnerInterface2 {
		void bark();
	}
	
	public static void main(String args[]) {
		InnerInterfaceDemo obj = new InnerInterfaceDemo();
		obj.mult(15,23);
		obj.div(15,3);
		
		MyInnerInterface2 refObj = () -> System.out.println("Woof");
		refObj.bark();
	}
}
