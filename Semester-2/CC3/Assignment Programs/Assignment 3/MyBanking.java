import java.util.Scanner;
abstract class BankAccount {
  final float MIN_BALANCE = 1000.0f;
  String accHolder;
  float bal;
  abstract float interestRate(int time);
}
class SavingsAccount extends BankAccount {
  @Override
  float interestRate(int time) {
    return 0.5f * bal * time;
  }
  void credit(float amt) {
    this.bal += amt;
  }
  void debit(float amt) {
    if (bal - amt >= this.MIN_BALANCE) this.bal -= amt;
  }
}
class FixedDepositAccount extends BankAccount {
  @Override
  float interestRate(int time) {
    return 0.3f * bal * time;
  }
}
public class MyBanking {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    SavingsAccount sAccount = new SavingsAccount();
    FixedDepositAccount fAccount = new FixedDepositAccount();
    System.out.println("Enter the name of account holder:");
    String aHolder = in.nextLine();
    sAccount.accHolder = fAccount.accHolder = aHolder;
    System.out.println("Enter the balance amount (greater than " + sAccount.MIN_BALANCE + "):");
    float bal = in.nextFloat();
    sAccount.bal = fAccount.bal = bal;
    System.out.println("Enter amount to be credited to savings account:");
    float cred = in.nextFloat();
    sAccount.credit(cred);
    System.out.println("Current balance of savings account = " + sAccount.bal);
    System.out.println("Enter amount to be debited from savings account:");
    float deb = in.nextFloat();
    sAccount.debit(deb);
    System.out.println("Current balance of savings account = " + sAccount.bal);
    System.out.println("Interest in savings account = " + sAccount.interestRate(5));
    System.out.println("Interest in fixed deposit account = " + fAccount.interestRate(5));    
    in.close();
  }
}
