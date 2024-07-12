
public class Stock {
    String item;
    int quan;
    int price;

    public Stock(String i, int q, int p) {
        item = i;
        quan = q;
        price = p;
    }

    public String getitem() {
        return item;
    }

    public int getquan() {
        return quan;
    }

    public void setquan(int q) {
        quan = q;
    }

    public int getprice() {
        return price;
    }

}
