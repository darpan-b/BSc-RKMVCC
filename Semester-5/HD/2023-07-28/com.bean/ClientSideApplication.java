package com.bean;

public class ClientSideApplication {
  public static void main(String[] args) {
    ServerSideApplication s = new ServerSideApplication();
    s.setName("Ankit");
    s.setId(101);
    s.setCourse("Java Bean");
    s.setRoll(1);
  }
  
  void registerStudent() {
    ServerSideApplication s = new ServerSideApplication();
    System.out.println(s.getRoll());
    System.out.println(s.getId());
    System.out.println(s.getName());
    System.out.println(s.getCourse());
  }
}
