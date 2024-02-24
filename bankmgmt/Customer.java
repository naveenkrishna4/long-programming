
import java.util.ArrayList;

public class Customer {
    static int no = 1000;
    int account_no;
    String name, username, password, phone_no;
    double amount;
    ArrayList<String> trans_hist;
    ArrayList<String> payees;

    public Customer(String name, String user, String pass, String phno, ArrayList<String> Payees) {
        account_no = no;
        no++;
        this.name = name;
        username = user;
        password = pass;
        phone_no = phno;
        this.payees = payees;
        trans_hist = new ArrayList<>();
        amount = 0;
    }

    public String getName() {
        return name;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public String getPhno() {
        return phone_no;
    }

    public ArrayList<String> gethist() {
        return trans_hist;
    }

    public ArrayList<String> getPayees() {
        return payees;
    }

    public double getAmount() {
        return amount;
    }

    public int getAccno() {
        return account_no;
    }

    public void setAmount(double amt) {
        this.amount = amt;
    }

    public void addhist(String res) {
        trans_hist.add(res);
    }

    public void setpwd(String pwd) {
        password = pwd;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setphno(String phno) {
        this.phone_no = phno;
    }
}
