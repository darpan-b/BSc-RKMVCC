/**
 * @author : Darpan Bhattacharya
 * @details : RKMVCC Rahara, 2nd Semester, B.Sc. CS (hons)
 * @date : 19.04.2022
 */

public class Apr192022 {
	public static void main(String args[]) {
		MyAbstractClass.main(new String[]{});
	}
}



/* prog 1 : Outer class and Inner class */
class OuterClass{
	
	class InnerClass{
		 void print(){
			System.out.println("Hello I am inside inner class");
		}
	}
	void nonStatic() {
		new InnerClass().print();
	}
	
	public static void main(String args[]){
		class YetAnotherInnerClass{
			public void print(){
				System.out.println("Hello I am inside yet another inner class");
			}
		}
		new OuterClass().nonStatic();
		new YetAnotherInnerClass().print();
	}
}
class OuterClassExtensionExperiment extends OuterClass{
	void nonStaticMain() {
		InnerClass ic = new InnerClass();
		ic.print();
	}
	
	public static void main(String args[]){
		new OuterClassExtensionExperiment().nonStaticMain();
		
	}
}
class AnotherOuterClassExperiment extends OuterClass {
	void method() {
		// this stuff is not possible if AnotherOuterClassExperiment does not extend OuterClass
		OuterClass.InnerClass obj = new OuterClass.InnerClass();
		obj.print();
	}
	
	public static void main(String args[]){
		new AnotherOuterClassExperiment().method();
	}
}




/* prog 2 : Runtime polymorphism */
class BabaClass {
	void func() {
		System.out.println("I am inside baba class");
	}
	
	public static void main(String args[]){
		BabaClass objBaba = new BabaClass();
		BacchaClass objBaccha = new BacchaClass();
		
		BabaClass referenceObject;
		
		referenceObject = objBaccha;
		referenceObject.func();
		referenceObject = objBaba;
		referenceObject.func();
	}
}
class BacchaClass extends BabaClass{
	@Override
	void func() {
		System.out.println("I am inside baccha class");
	}
}



/* abstract class */
abstract class MyAbstractClass {
	abstract void wontDefineHere();
	
	void wouldDefineHere(){
		System.out.println("Inside the body of MyAbstractClass");
	}
	public static void main(String args[]){
		MyAbstractClass obj = new RealisticClass();
		obj.wontDefineHere();
		obj.wouldDefineHere();
	}
}
class RealisticClass extends MyAbstractClass{ 
	void wontDefineHere() {
		System.out.println("Inside realistic class");
	}
}
