package com.bean;

public class ServerSideApplication implements java.io.Serializable {
  private int id, roll;
  private String name, course;
  
  public ServerSideApplication() {
  }
  
  // setter method to set the values
  public void setRoll(int roll) {
    this.roll = roll;
  }
  public void setId(int id) {
    this.id = id;
  }
  public void setName(String name) {
    this.name = name;
  }
  public void setCourse(String course) {
    this.course = course;
  }
  
  
  // getter method to get the values
  public int getRoll() {
    return roll;
  }
  public int getId() {
    return id;
  }
  public String getName() {
    return name;
  }
  public String getCourse() {
    return course;
  }    
}
