import java.util.*;
import java.io.*;

class Hello {

    public void bookTickets(Flight f, int pid, int t) {
        f.tickets -= t;
        String PassDetail = "PassID:" + pid + "  No of tickets " + t + "  Cost " + (t * f.price);
        int c = t * f.price;
        f.price += 200 * t;
        f.PassengerDeatils.add(PassDetail);
        f.PassengerIds.add(pid);
        f.TicketPrice.add(c);
        f.NoofTickets.add(t);
        System.out.println("Paasenger id: " + pid);
        System.out.println("Flight id: " + f.FlightId + " current price :" + f.price + " tickets rem: " + f.tickets);
        System.out.println("booked\n");
    }

    public void cancelTickets(int pid, Flight f) {
        int ind = f.PassengerIds.indexOf(pid);
        if (ind < 0) {
            System.out.println("Id not found");
            return;
        }
        int t = f.NoofTickets.get(ind);
        int p = f.TicketPrice.get(ind);
        System.out.println("Refund :" + p);
        f.tickets += t;
        f.price -= 200 * t;
        System.out.println("Flight id: " + f.FlightId + " current price :" + f.price + " tickets rem: " + f.tickets);
        f.PassengerDeatils.remove(ind);
        f.PassengerIds.remove(ind);
        f.NoofTickets.remove(ind);
        f.TicketPrice.remove(ind);
        System.out.println("cancelled\n");
    }

    public void printFlights(Flight f) {
        for (String s : f.PassengerDeatils) {
            System.out.println(s);
        }
        System.out.println("printed\n");
    }

    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        Hello h = new Hello();
        ArrayList<Flight> f = new ArrayList<Flight>();
        for (int i = 0; i < 3; i++) {
            f.add(new Flight());
        }
        int passengerId = 1;
        while (true) {
            System.out.println("Menu");
            System.out.println("1.Book 2.Cancel 3.Flight details 4.Exit\n");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("Enter Flight Id: ");
                    int flightid = sc.nextInt();
                    if (flightid > f.size()) {
                        System.out.print("Invalid FlightId");
                        break;
                    }
                    Flight curr = null;
                    for (Flight flights : f) {
                        if (flightid == flights.FlightId) {
                            curr = flights;
                            break;
                        }
                    }
                    System.out.print("Enter no of tickets: ");
                    int t = sc.nextInt();
                    if (t > curr.tickets) {
                        System.out.print("Seats not available");
                        break;
                    }
                    h.bookTickets(curr, passengerId, t);
                    passengerId += 1;
                    break;
                case 2:
                    System.out.print("Enter Flight Id: ");
                    flightid = sc.nextInt();
                    if (flightid > f.size()) {
                        System.out.print("Invalid FlightId");
                        break;
                    }
                    curr = null;
                    for (Flight flights : f) {
                        if (flightid == flights.FlightId) {
                            curr = flights;
                            break;
                        }
                    }
                    System.out.print("Enter passenger id: ");
                    int pid = sc.nextInt();
                    h.cancelTickets(pid, curr);
                    break;
                case 3:
                    System.out.print("Enter Flight Id: ");
                    flightid = sc.nextInt();
                    if (flightid > f.size()) {
                        System.out.print("Invalid FlightId");
                        break;
                    }
                    curr = null;
                    for (Flight flights : f) {
                        if (flightid == flights.FlightId) {
                            curr = flights;
                            break;
                        }
                    }
                    h.printFlights(curr);
                    break;
                case 4:
                    System.exit(0);
            }
        }
    }
}