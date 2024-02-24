import java.util.*;

public class Flight {
    static int id = 0;
    public int FlightId, tickets, price;
    public ArrayList<String> PassengerDeatils;
    public ArrayList<Integer> PassengerIds, TicketPrice, NoofTickets;

    public Flight() {
        tickets = 50;
        FlightId = id;
        price = 100;
        id++;
        PassengerDeatils = new ArrayList<String>();
        PassengerIds = new ArrayList<Integer>();
        TicketPrice = new ArrayList<Integer>();
        NoofTickets = new ArrayList<Integer>();
    }

}
