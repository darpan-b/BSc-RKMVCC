class Box {
    double length, width, depth;

    // parameterized constructor
    public Box(double length, double width, double depth) {
        this.length = length;
        this.width = width;
        this.depth = depth;
    }

    double getVolume() {
        return this.length * this.width * this.depth;
    }
}

public class BoxDemo7 {
    public static void main(String[] args) {
        Box myBox1 = new Box(12.12, 52.21, 212.0);
        Box myBox2 = new Box(11, 2.2, 221.2);

        double volume = 0;

        // printing volume for myBox1
        volume = myBox1.getVolume();
        System.out.println("Volume of myBox1 = " + volume);

        // printing volume for myBox2
        volume = myBox2.getVolume();
        System.out.println("Volume of myBox2 = " + volume);

    }
}
