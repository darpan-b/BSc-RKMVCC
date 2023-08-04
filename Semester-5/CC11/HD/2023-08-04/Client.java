package bean.com;

public class Client {
	public static void main(String[] args) {
		BankServer bankServer = new BankServer();
		bankServer.setUsername("Jishnu");
		bankServer.setUserid("6842002486");
		bankServer.setAccount_no(100101);
		bankServer.setBalance(5_00_000.0);
		bankServer.setPassword("ffsrfseff");
		Client c = new Client();
		c.printClient(bankServer);
	}
	
	public void printClient(BankServer bServer) {
		System.out.println(bServer);
	}
}
