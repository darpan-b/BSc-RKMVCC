public class ExceptionHandling {
  public static void main(String[] args) {
    try {
      int res = 5 / 0;
    } catch (ArithmeticException ae) {
      System.out.println("Arithmetic exception encountered: " + ae);
    }
    try {
      int[] arr = {0, 1};
      System.out.println("Element at 2nd index = " + arr[2]);
    } catch (ArrayIndexOutOfBoundsException aie) {
      System.out.println("Array index out of bounds exception encountered: " + aie);
    }
    try {
      int[] arr = null;
      System.out.println("Element at 0th index = " + arr[0]);
    } catch (NullPointerException npe) {
      System.out.println("Null pointer exception encountered: " + npe);
    }
  }
}
