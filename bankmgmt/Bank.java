import java.util.*;

public class Bank {

    public Customer create() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name : ");
        String name = sc.nextLine();
        System.out.print("Enter username : ");
        String user = sc.next();
        System.out.print("Enter password : ");
        String pwd = sc.next();
        System.out.print("Enter phone no : ");
        String phno = sc.next();
        System.out.print("Enter No of payess : ");
        int p = sc.nextInt();
        ArrayList<String> a = new ArrayList<>();
        for (int i = 0; i < p; i++) {
            System.out.print("Enter username of payee " + (i + 1) + " : ");
            String payeename = sc.next();
            a.add(payeename);
        }
        Customer cus = new Customer(name, user, pwd, phno, a);
        System.out.println("Created");
        return cus;
    }

    public void login(ArrayList<Customer> cus) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter username: ");
        String user = sc.next();
        System.out.print("Enter password: ");
        String pwd = sc.next();
        Customer customer = null;
        for (Customer c : cus) {
            System.out.println(c);
            if (c.getUsername().equals(user) && c.getPassword().equals(pwd)) {
                customer = c;
                break;
            }
        }
        if (customer == null) {
            System.out.println("Incorrect Username or Password");
            return;
        }
        System.out.println("Logged in");
        char y;
        do {
            System.out.println("\nMenu");
            System.out.println(
                    "1. Cash Deposit  2.Withdrawal  3.Bank transfer  4.View Account  5.Update Profile");
            System.out.print("Enter your Choice: ");
            int ch = sc.nextInt();
            if (ch == 1) {
                System.out.print("Enter amount: ");
                double amt = sc.nextDouble();
                double bal = customer.getAmount();
                System.out.println("Balance: " + (amt + bal));
                customer.setAmount(amt + bal);
                String res = "Deposit Amount:" + amt + " Bal: " + customer.getAmount();
                customer.addhist(res);
            } else if (ch == 2) {
                System.out.print("Enter amount: ");
                double amt = sc.nextDouble();
                double bal = customer.getAmount();
                System.out.println("Balance: " + (bal - amt));
                customer.setAmount(bal - amt);
                String res = "Withdrawal Amount:" + amt + " Bal: " + customer.getAmount();
                customer.addhist(res);

            } else if (ch == 3) {
                System.out.print("Enter Account Number: ");
                int acc = sc.nextInt();
                Customer payee = null;
                for (Customer c : cus) {
                    if (c.getAccno() == (acc)) {
                        payee = c;
                        break;
                    }
                }
                if (payee == null) {
                    System.out.println("Invalid acc no");
                } else {
                    System.out.print("Enter amount: ");
                    double amt = sc.nextDouble();
                    double bal1 = customer.getAmount(), bal2 = payee.getAmount();
                    customer.setAmount(bal1 - amt);
                    System.out.println("Balance: " + (bal1 - amt));
                    payee.setAmount(amt + bal2);
                    String res = "Bank transfer  Acc.no: " + acc + " Amount:" + amt + " Bal: " + customer.getAmount();
                    customer.addhist(res);
                }
            } else if (ch == 4) {
                System.out.println("Name : " + customer.getName());
                System.out.println("Phone no : " + customer.getPhno());
                System.out.println("Account no : " + customer.getAccno());
                System.out.println("Username : " + customer.getUsername());
                System.out.println("Password : " + customer.getPassword());
                System.out.println("Balance : " + customer.getAmount());
                System.out.println("Transaction History");
                ArrayList<String> ans = customer.gethist();
                for (String i : ans) {
                    System.out.println(i);
                }

            } else if (ch == 5) {
                System.out.print("Enter name: ");
                String name = sc.nextLine();
                customer.setName(name);
                System.out.print("Enter phno: ");
                String phno = sc.next();
                customer.setphno(phno);
                System.out.print("Enter password: ");
                pwd = sc.next();
                customer.setpwd(pwd);

            }
            System.out.print("Do you want to continue (y/n): ");
            y = sc.next().charAt(0);
        } while (y == 'y');
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Bank b = new Bank();
        ArrayList<Customer> customers = new ArrayList<>();
        while (true) {
            System.out.println("\nMain Menu");
            System.out.println("1.Create account  2.Login  3.Exit");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();
            if (ch == 1) {
                Customer c = b.create();
                customers.add(c);

            } else if (ch == 2) {
                b.login(customers);
            } else
                break;
        }

    }

}
