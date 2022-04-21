/**
 * Name : Darpan Bhattacharya
 * Roll no : 715
 * Problem : Command Line arguments
 */

package cc301;

/*
 * Program to find the sum of the command line arguments entered
 */

public class CC301 {

	public static void main(String[] args) {
		System.out.println("The command line arguments are: ");
		for(String str : args) System.out.print(str + " ");
		System.out.println();

		int sum = 0;
		for (String str : args) {
			try {
				int num = Integer.parseInt(str);
				sum += num;
			} catch (NumberFormatException e) {
			}
		}
		System.out.println("The sum of the integer arguments entered through command "
				+ "line are: " + sum);
	}

}
