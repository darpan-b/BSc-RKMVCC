/*
    Box Demo program 2
    02.03.2022
*/

class Box {
    double length,width,depth;

    void getVolume() {
        System.out.println("Volume of the box = "+(this.length * this.depth * this.width));
    }
}

public class BoxDemo2 {
    public static void main(String[] args) {
        Box myBox1 = new Box();
        Box myBox2 = new Box();

        // assigning values to box1
        myBox1.length = 45;
        myBox1.depth = 56.5;
        myBox1.width = 20.51;

        // assigning values to Box
        myBox2.length = 415;
        myBox2.depth = 526.5;
        myBox2.width = 202.251;

        myBox1.getVolume();
        myBox2.getVolume();

    }
}
