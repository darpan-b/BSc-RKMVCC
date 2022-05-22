public class NestedExceptionHandling {
  public static void main(String[] args) {
    try {
      try {
        int[] arr = null;
        System.out.println("Element at 0th index of arr = " + arr[0]);
      } catch (NullPointerException ne) {
        System.out.println("Null pointer exception encountered: " + ne);
      }
    } catch (ArrayIndexOutOfBoundsException ae) {
      System.out.println("Array index out of bounds exception encountered: " + ae);
    }
  }
}
