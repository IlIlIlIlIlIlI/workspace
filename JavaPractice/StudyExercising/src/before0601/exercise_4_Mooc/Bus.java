package before0601.exercise_4_Mooc;

public class Bus extends Car {
    protected int person;

    public int getPerson() {
        return person;
    }

    public void setPerson(int person) {
        this.person = person;
    }

    public Bus(int number,String name,int person){
        this.number = number;
        this.name = name;
        this.person = person;
    }
}
