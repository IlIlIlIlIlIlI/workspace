package before0601.exercise_5;

public class Vehicle {
    private String brand;
    private int velocity;

    public int getVelocity() {
        return velocity;
    }

    public void setVelocity(int velocity) {
        this.velocity = velocity;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }
    private int calculSpeed(int journey){
        int time = velocity * journey;
                return time;
    }
    public Vehicle(String brand,int velocity){
        this.setBrand(brand);
        this.setVelocity(velocity);
    }
}
