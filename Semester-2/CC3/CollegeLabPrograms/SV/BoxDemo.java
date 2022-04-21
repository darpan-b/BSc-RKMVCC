/*
    Box Demo Code 1
    02.03.2022
*/

class Box {
    double depth, width, length;
}

public class BoxDemo {
    public static void main(String[] args) {

        Box myBox = new Box();

        // assign values to instance variables of Box class
        myBox.length = 12.532;
        myBox.width = 10.22;
        myBox.depth = 5.10;

        // compute volume of box

        double volume = myBox.depth * myBox.width * myBox.length;

        System.out.println("The volume of my box is: " + volume);
    }
}
