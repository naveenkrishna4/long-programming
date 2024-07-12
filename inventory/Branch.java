import java.util.*;

public class Branch {
    ArrayList<String> sales;

    public Branch() {
        sales = new ArrayList<>();
    }

    public void setsales(String s) {
        sales.add(s);
    }

    public ArrayList<String> getsales() {
        return sales;
    }
}
