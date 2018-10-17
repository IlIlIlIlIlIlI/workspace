package before0601.cars;

public class Pickup extends Car{
    private int people;//载人数
    private int weight;//载重
    public Pickup(String name, int price,int people,int weight) {
        super(name,price);
        this.people = people;
        this.weight = weight;
    }
    public int getPeople() {
        return people;
    }
    public void setPeople(int people) {
        this.people = people;
    }
    public int getWeight() {
        return weight;
    }
    public void setWeight(int weight) {
        this.weight = weight;
    }
}