package before0601.cars;

public class Van extends Car{
    private int weight;//载重
    public Van(String name, int price,int weight) {
        super(name,price);
        this.weight = weight;
    }
    public int getWeight() {
        return weight;
    }
    public void setWeight(int weight) {
        this.weight = weight;
    }
}
