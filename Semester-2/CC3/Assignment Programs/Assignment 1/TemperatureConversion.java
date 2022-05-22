import java.util.Scanner;
public class TemperatureConversion {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter temperature in Celsius:");
    float c = in.nextFloat();
    float f = (c / 5) * 9 + 32;
    System.out.println("Temperature in Fahrenheit = " + f);
    in.close();
  }
}
