package before0601.exercise_4_Mooc;

public class Pickup extends Car {
    private int person;
    private double weight;

    public int getPerson() {
        return person;
    }

    public void setPerson(int person) {
        this.person = person;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public Pickup(int number,String name,int person,int weight){
        this.number = number;
        this.name = name;
        this.person = person;
        this.weight = weight;
    }
}
