package before0601.exercise_4_Mooc;

public class LittleCar extends Car {
    private int person;

    public int getPerson() {
        return person;
    }

    public void setPerson(int person) {
        this.person = person;
    }

    public LittleCar(int number,String name,int person){
        this.number = number;
        this.name = name;
        this.person = person;
    }
}
