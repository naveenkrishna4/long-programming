import java.util.*;

public class Dish {
    String name;
    ArrayList<String> recipe;
    int quan;
    int price;
    ArrayList<Stock> stocks;
    char size;
    int branch;

    public Dish(String name, ArrayList<String> recipe, int q, int p, char s, int branch) {
        this.name = name;
        recipe = new ArrayList<>();
        for (String i : recipe) {
            this.recipe.add(i);
        }
        quan = q;
        price = p;
        size = s;
        this.branch = branch;
    }
}
