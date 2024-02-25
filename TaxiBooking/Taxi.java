import java.util.*;

public class Taxi {
    char loc;
    int no, time;
    double earn;
    ArrayList<String> hist;

    public Taxi(char l, int i, double earn) {
        this.loc = l;
        this.no = i;
        this.earn = earn;
        time = 5;
        hist = new ArrayList<>();
    }

    public int getno() {
        return no;
    }

    public char getloc() {
        return loc;
    }

    public int gettime() {
        return time;
    }

    public double getearn() {
        return earn;
    }

    public void setearn(double e) {
        earn = e;
    }

    public void settime(int t) {
        time = t;
    }

    public void setloc(char l) {
        loc = l;
    }

    public ArrayList<String> gethist() {
        return hist;
    }

    public void sethist(String h) {
        hist.add(h);
    }

}