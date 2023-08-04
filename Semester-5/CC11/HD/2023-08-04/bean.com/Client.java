package bean.com;

import java.util.*;

public class Client {
	public static void main(String[] args) {
		BankServer bankServer = new BankServer();
		bankServer.setUsername("Jishnu");
		bankServer.setUserid("6842002486");
		bankServer.setAccount_no(1000101);
		bankServer.setBalance(5_00_000.0);
		bankServer.setPassword("ffsrfseff");
		Client c = new Client();
		c.printClient(bankServer);
		Scanner sc = new Scanner(System.in);
		System.out.println("Amount to credit:");
		double toCredit = sc.nextDouble();
		bankServer.credit(toCredit);
		System.out.println("Current balance = " + bankServer.getBalance());
		System.out.println("Amount to debit:");
		double toDebit = sc.nextDouble();
		bankServer.debit(toDebit);
		System.out.println("Current balance = " + bankServer.getBalance());
	}
	
	public void printClient(BankServer bServer) {
		System.out.println(bServer);
	}
}
