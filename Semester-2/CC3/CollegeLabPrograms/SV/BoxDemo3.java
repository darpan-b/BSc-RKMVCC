/*
    Box Demo program 3
    02.03.2022
*/

class Box {
    double length,width,depth;

    double getVolume(){ 
        return this.length*this.width*this.depth;
    }
}

public class BoxDemo3 {
    public static void main(String[] args) {
        Box myBox1 = new Box();
        Box myBox2 = new Box();

        // assigning values to the instance variables for myBox1
        myBox1.depth = 54.52;
        myBox1.length = 7.20;
        myBox1.width = 12.21;

        // assigning values to the instance variables for myBox2
        myBox2.depth = 51.33;
        myBox2.length = 43.22;
        myBox2.width = 13.69;
        

        double volume = 0;

        volume = myBox1.getVolume();
        // printing volume of myBox1
        System.out.println("Volume of myBox1 = "+volume);

        volume = myBox2.getVolume();
        // printing volume of myBox2
        System.out.println("Volume of myBox2 = "+volume);

    }
}
