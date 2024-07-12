import java.util.*;

public class Inventory {

    public static Dish makedish(ArrayList<Stock> stocks, ArrayList<Branch> branches) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Branch: ");
        int b = sc.nextInt();
        System.out.print("Name: ");
        String n = sc.next();
        System.out.print("Quantity: ");
        int q = sc.nextInt();
        System.out.print("Price: ");
        int p = sc.nextInt();
        System.out.print("Enter number of items: ");
        int c = sc.nextInt();
        for (int i = 0; i < c; i++) {
            System.out.print("Item: ");
            String item = sc.next();
            System.out.print("Quantity: ");
            int k = sc.nextInt();
            Stock curr = null;
            for (Stock s : stocks) {
                if (s.getitem().equals(item)) {
                    curr = s;
                    break;
                }
            }
            if (curr == null) {
                System.out.println("Item not available");
                return null;
            }
            if (curr.getquan() < k) {
                System.out.println("Stocks not sufficient");
                return null;
            }
            curr.setquan(curr.getquan() - k);
        }
        ArrayList<String> r = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            r.add("Step " + (i + 1));
        }
        String s = "Name : " + n + " Quantity: " + q + "  Price: " + (q * p);
        if (b == 1) {
            branches.get(0).setsales(s);
        } else {
            branches.get(1).setsales(s);
        }
        return new Dish(n, r, q, p, 'L', b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Dish> dishes = new ArrayList<>();
        ArrayList<Stock> stocks = new ArrayList<>();
        ArrayList<Branch> branches = new ArrayList<>();
        branches.add(new Branch());
        branches.add(new Branch());
        stocks.add(new Stock("potato", 100, 10));
        stocks.add(new Stock("tomatoe", 200, 20));
        stocks.add(new Stock("onion", 100, 15));
        while (true) {
            System.out.print("\n1. Make Dish   2.Branch Sales  3.Exit\nEnter choice:");
            int ch = sc.nextInt();
            if (ch == 1) {
                Dish d = makedish(stocks, branches);
                if (d == null) {
                    System.out.println("Food not ready");
                } else {
                    dishes.add(d);
                    System.out.println("Food ready");
                }
            } else if (ch == 2) {
                System.out.print("Branch no: ");
                int s = sc.nextInt();
                for (String i : branches.get(s - 1).getsales()) {
                    System.out.println(i);
                }
            } else {
                break;
            }
        }

    }
}
