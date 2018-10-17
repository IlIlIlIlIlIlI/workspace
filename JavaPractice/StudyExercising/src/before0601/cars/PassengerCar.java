package before0601.cars;

public class PassengerCar extends Car {
    private int people;//乘客人数
    public PassengerCar(String name, int price,int people) {
        super(name,price);
        this.people=people;
    }
    public int getPeople() {
        return people;
    }
    public void setPeople(int people) {
        this.people = people;
    }
}
