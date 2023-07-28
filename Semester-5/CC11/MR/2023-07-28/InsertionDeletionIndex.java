// Q2. Write a program to perform insertion and deletion based on index in an array

import java.util.Scanner;

class Solver {
  int[] arr;
  int size;  
  int upto = -1;
  
  boolean canInsert(int idx) {
    if (idx < 0 || idx >= size) {
      System.out.println("Please enter a valid index value (between 0 and " + (size - 1) + ")");
      return false;
    }
    if (upto == size - 1) {
      System.out.println("Array is full!");
      return false;
    }
    if (idx > upto + 1) {
      System.out.println("Gaps are not allowed during insertion.");
      return false;
    }
    for (int i = upto; i >= idx; i--) arr[i + 1] = arr[i];
    upto++;
    return true;
  }
  
  boolean canDelete(int idx) {
    if (idx < 0 || idx >= size) {
      System.out.println("Please enter a valid index value (between 0 and " + (size - 1) + ")");
      return false;
    }
    if (upto == -1) {
      System.out.println("Array is empty!");
      return false;
    }
    if (idx > upto) {
      System.out.println("There is no value at that index!");
      return false;
    }
    for (int i = idx; i <= upto; i++) arr[i] = arr[i + 1];
    upto--;
    return true;
  }
  
  void solve() {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the capacity of the array:");
    size = in.nextInt();
    arr = new int[size];
    System.out.println("Enter the initial number of elements in the array:");
    int n = in.nextInt();
    System.out.println("Enter the initial " + n + " elements:");
    upto = n - 1;
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    while (true) {
      System.out.println("============================================================================");
      System.out.println("Press 1 to insert element, 2 to delete element in the array.");
      System.out.println("Press 3 to display the array.");
      System.out.println("Press any other numeric key to exit.\n");
      System.out.println("Enter your choice:");
      int choice = in.nextInt();
      if (choice == 1) {
        System.out.println("Enter the index at which you want to insert:");
        int idx = in.nextInt();
        if (!canInsert(idx)) continue;
        System.out.println("Enter the value to insert:");
        int value = in.nextInt();
        arr[idx] = value;
        System.out.println("Value inserted!");
      }
      else if (choice == 2) {
        System.out.println("Enter the index whose value you want to delete:");
        int idx = in.nextInt();
        if (canDelete(idx)) System.out.println("Value deleted!");
      }
      else if (choice == 3) {
        if (upto == -1) {
          System.out.println("Array is empty!");
          continue;
        }
        System.out.println("Array is: ");
        for (int i = 0; i <= upto; i++) System.out.print(arr[i] + " ");
        System.out.println();
      }
      else {
        break;
      }
    }
  }
}

public class InsertionDeletionIndex {
  public static void main(String[] args) {
    Solver solver = new Solver();
    solver.solve();
  }
}
