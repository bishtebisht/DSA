class Pen{
    String color;
    String type;

    public void write(){
        System.out.println("writing something");
    }
    public void printColor(){
        System.out.println(this.color);
    }
}

public class ObjPrg {
    public static void main(String[] args) {
        Pen pen1 = new Pen();
        pen1.color = "blue";
        pen1.type = "ball";
        
        Pen pen2 = new Pen();
        pen2.color = "blacl";
        pen2.type = "gel";


        pen1.write();
        pen1.printColor();
        pen2.printColor();
    }
}
