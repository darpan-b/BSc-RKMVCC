package bean.com;

public class BankServer implements java.io.Serializable {
	private String userid, username, password;
	private long account_no;
	private double balance;
	
	public BankServer() {
	}
	
	// setter methods
	public void setUserid(String userid) {
		this.userid = userid;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public void setAccount_no(long account_no) {
		this.account_no = account_no;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	// getter methods
	public String getUserid() {
		return userid;
	}
	public String getUsername() {
		return username;
	}
	public String getPassword() {
		return password;
	}
	public long getAccount_no() {
		return account_no;
	}
	public double getBalance() {
		return balance;
	}

	@Override
	public String toString() {
		return "BankServer [userid=" + userid + ", username=" + username + ", password=" + password + ", account_no="
				+ account_no + ", balance=" + balance + "]";
	}
	
	public void credit(double amount) {
		this.balance += amount;
	}
	public void debit(double amount) {
		if (amount <= this.balance) this.balance -= amount;
	}

}
