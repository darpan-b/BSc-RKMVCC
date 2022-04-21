class Box {
    double length, width, height;

    double getVolume() {
        return length * width * height;
    }

    void setDim(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }
}

public class BoxDemo4 {
    public static void main(String[] args) {
        Box myBox1 = new Box();
        Box myBox2 = new Box();

        // setting dimensions for myBox1
        myBox1.setDim(12.12, 15.20, 20.00);
        // setting dimensions for myBox2
        myBox2.setDim(21.02, 15.2, 17.78);

        double volume = 0;

        // printing volume for myBox1
        volume = myBox1.getVolume();
        System.out.println("Volume of myBox1 = " + volume);

        // printing volume for myBox2
        volume = myBox2.getVolume();
        System.out.println("Volume of myBox2 = " + volume);
    } 
}
