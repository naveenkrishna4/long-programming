
import java.util.*;

public class Booking {

    public static void book(char p, char d, ArrayList<Taxi> t, int id, int time) {
        double earning = Double.MAX_VALUE;
        int mindis = Integer.MAX_VALUE;
        int tim = Math.abs(p - d), distance = tim * 15;
        Taxi curr = null;
        for (Taxi taxi : t) {
            if (taxi.gettime() <= time) {
                int dist = Math.abs(taxi.getloc() - p);
                if (dist < mindis) {
                    mindis = dist;
                    curr = taxi;
                }
                if (dist == mindis) {
                    if (earning > taxi.getearn()) {
                        curr = taxi;
                    }
                }
            }
        }
        if (curr == null) {
            System.out.print("No taxi available");
            return;
        }
        double amt = (distance - 5) * 10 + 100;
        curr.setloc(d);
        curr.setearn(curr.getearn() + amt);
        String str = "Customer id: " + id + " Pickup: " + p + " Drop: " + d + "  Cost: " + amt + " Start Time: "
                + time + " End time: " + (time + tim);
        curr.sethist(str);
        curr.settime(time + tim);
        System.out.println(
                "Booked taxi no:" + curr.getno() + " Cost: " + amt + " Start Time: " + time + " End time: "
                        + (time + tim));
    }

    public static void view(ArrayList<Taxi> taxis, int n) {
        Taxi curr = null;
        for (Taxi t : taxis) {
            if (t.getno() == n) {
                curr = t;
                break;
            }
        }
        System.out.println("Current Location: " + curr.getloc());
        System.out.println("Current Earnings: " + curr.getearn());
        System.out.println("Free Time: " + curr.gettime());

        System.out.println("History");

        for (String s : curr.gethist()) {
            System.out.println(s);
        }

    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Taxi> taxis = new ArrayList<>();
        for (int i = 1; i <= 4; i++) {
            taxis.add(new Taxi('A', i, 0));
        }
        char ch = 'y';
        do {
            System.out.println("\nMenu");
            System.out.println("1.Book  2.Taxi Deatils");
            System.out.print("Choice :");
            int c = sc.nextInt();
            if (c == 1) {
                System.out.print("Customer id: ");
                int id = sc.nextInt();
                System.out.print("Pickup: ");
                char p = sc.next().charAt(0);
                System.out.print("Drop: ");
                char d = sc.next().charAt(0);
                System.out.print("Time: ");
                int time = sc.nextInt();
                book(p, d, taxis, id, time);
            } else if (c == 2) {
                System.out.print("Enter taxi no: ");
                int n = sc.nextInt();
                view(taxis, n);
            } else {
                System.out.println("Invalid input");
            }
            System.out.print("Do you want to continue (y/n) :");
            ch = sc.next().charAt(0);

        } while (ch == 'y');
    }
}
