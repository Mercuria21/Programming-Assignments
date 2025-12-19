/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PartB;

import java.util.Scanner;

/**
 * Object Oriented Programming, Lab 5
 * @author Danial Johan bin Ahmad, CS01085391
 */

class item {
    private String code;
    private String name;
    private double price;
    private int stock;
    
    public item(String code, String name, double price, int stock) {
        this.code = code;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }
    
    public String getCode() { return code; }
    public String getName() { return name; }
    public double getPrice() { return price; }
    public int getStock() { return stock; }
    
    public void display() {
        System.out.printf("%-10s %-20s RM%-10.2f %-10d\n", 
            code, name, price, stock);
    }
}

public class Q2 {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        
        System.out.print("Enter number of items: ");
        int N = scan.nextInt();
        scan.nextLine();
        
        item[] items = new item[N];
        
        for (int i = 0; i < N; i++) {
            System.out.println("\nEnter details for item " + (i+1));

            System.out.print("Code: ");
            String code = scan.nextLine();

            System.out.print("Name: ");
            String name = scan.nextLine();

            System.out.print("Price: ");
            double price = scan.nextDouble();

            System.out.print("Stock: ");
            int stock = scan.nextInt();
            scan.nextLine(); // clear newline

            items[i] = new item(code, name, price, stock);
        }
            int choice;
            do {
                System.out.println("\n===== INVENTORY MENU =====");
                System.out.println("1. List all items");
                System.out.println("2. Search by code");
                System.out.println("3. Discount view");
                System.out.println("4. Low-stock report (<5)");
                System.out.println("5. Most valuable item (price * stock)");
                System.out.println("0. Exit");
                System.out.print("Enter choice: ");
                choice = scan.nextInt();
                scan.nextLine();
               
                switch (choice) {

                    case 1:
                        System.out.println("\n--- LIST OF ITEMS ---");
                        System.out.printf("%-10s %-20s %-12s %-10s\n", "Code", "Name", "Price", "Stock");
                        for (item it : items) {
                            it.display();
                        }
                    break;

                    case 2:
                        System.out.print("Enter item code to search: ");
                        String searchCode = scan.nextLine();
                        boolean found = false;

                        for (item it : items) {
                            if (it.getCode().equalsIgnoreCase(searchCode)) {
                                System.out.println("\nItem found:");
                                it.display();
                                found = true;
                            break;
                            }
                        }

                        if (!found) {
                            System.out.println("Not found.");
                        }
                        break;

                    case 3:
                        System.out.print("Enter discount percentage: ");
                        double p = scan.nextDouble();

                        System.out.println("\n--- DISCOUNT VIEW ---");
                        System.out.printf("%-10s %-20s %-12s %-12s\n", "Code", "Name", "Original", "Discounted");

                        for (item it : items) {
                            double discounted = it.getPrice() * (1 - p/100);
                            System.out.printf("%-10s %-20s RM%-10.2f RM%-10.2f\n", it.getCode(), it.getName(), it.getPrice(), discounted);
                        }
                        break;

                    case 4:
                        System.out.println("\n--- LOW STOCK (<5) ---");
                        boolean anyLow = false;

                        for (item it : items) {
                            if (it.getStock() < 5) {
                                it.display();
                                anyLow = true;
                            }
                        }
                        if (!anyLow) {
                            System.out.println("No low-stock items.");
                        }
                        break;
                
                    case 5:
                        item best = items[0];
                        double maxValue = best.getPrice() * best.getStock();

                        for (item it : items) {
                            double val = it.getPrice() * it.getStock();
                            if (val > maxValue) {
                                best = it;
                                maxValue = val;
                            }
                        }

                        System.out.println("\n--- MOST VALUABLE ITEM ---");
                        best.display();
                        System.out.println("Value = RM" + maxValue);
                        break;

                    case 0:
                        System.out.println("Exiting program...");
                        break;

                    default:
                        System.out.println("Invalid choice!");
                }

            } while (choice != 0);
        scan.close();
    }
}