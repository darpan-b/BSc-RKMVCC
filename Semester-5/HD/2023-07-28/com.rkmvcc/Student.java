package com.rkmvcc;

public class Student {
  int roll, id;
  String name, course;
  
  void registerStudent(int roll, int id, String name, String course) {
    this.roll = roll;
    this.id = id;
    this.name = name;
    this.course = course;
  }
  
  @Override
  public String toString() {
    return "Student [roll = " + roll + ", id = " + id + ", name = " + name + ", course = " + course + "]";
  }
  
  public static void main(String[] args) {
    Student s = new Student();
    s.registerStudent(1, 101, "Ankit", "Java Bean");
    System.out.println("s = " + s);
  }
}
