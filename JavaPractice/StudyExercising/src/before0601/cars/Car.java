package before0601.cars;

public class Car{
    private String name;//车辆名称
    private int price;//租车价格
    public Car(String name,int price){
        this.setName(name);
        this.setPrice(price);
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getPrice() {
        return price;
    }
    public void setPrice(int price) {
        this.price = price;
    }
}