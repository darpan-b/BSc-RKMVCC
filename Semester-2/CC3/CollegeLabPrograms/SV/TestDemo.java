/**
 * Name : Darpan Bhattacharya
 * Roll no : 715
 * Problem : Packages in Java
 */

package testDemo;

class A {
	public String toString() {
		return "This is Class A";
	}
}
class B {
	public String toString() {
		return "This is Class B";
	}
}
class C {
	public String toString() {
		return "This is Class C";
	}
}

public class TestDemo {
	public static void main(String[] args) {
		A aObj = new A();
		B bObj = new B();
		C cObj = new C();
		System.out.println(aObj);
		System.out.println(bObj);
		System.out.println(cObj);
	}
}
