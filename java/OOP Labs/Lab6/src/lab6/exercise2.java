/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;

import java.util.Scanner;

/**
 *
 * @author mikesieg
 */

class Order {
    private String customerName;
    private String customerNumber;
    private int quantityOrdered;
    private double unitPrice;
    protected double totalPrice;
    
    static Scanner input = new Scanner(System.in);

    public void setCustomerName() {
        System.out.print("Enter Customer Name: ");
        this.customerName = input.nextLine();
    }

    public void setCustomerNumber() {
        System.out.print("Enter Customer Number: ");
        this.customerNumber = input.nextLine();
    }

    public void setQuantityOrdered() {
        System.out.print("Enter Quantity Ordered: ");
        this.quantityOrdered = input.nextInt();
    }

    public void setUnitPrice() {
        System.out.print("Enter Unit Price: ");
        this.unitPrice = input.nextDouble();
        input.nextLine();
    }

    public String getCustomerName() { return customerName; }
    public String getCustomerNumber() { return customerNumber; }
    public int getQuantityOrdered() { return quantityOrdered; }
    public double getUnitPrice() { return unitPrice; }

    public void computePrice() {
        this.totalPrice = unitPrice * quantityOrdered;
    }

    public void display() {
        System.out.println("\nOrder Summary:");
        System.out.println("Customer: " + customerName);
        System.out.println("ID: " + customerNumber);
        System.out.println("Quantity: " + quantityOrdered);
        System.out.println("Unit Price: RM" + unitPrice);
        System.out.println("Total Price: RM" + totalPrice);
    }
}

class ShippedOrder extends Order {
    @Override
    public void computePrice() {
        super.computePrice();
        this.totalPrice += 12.00;
    }
}

public class exercise2 {
    public static void main(String[] args) {
        System.out.println("--- Processing Standard Order ---");
        Order order1 = new Order();
        order1.setCustomerName();
        order1.setCustomerNumber();
        order1.setQuantityOrdered();
        order1.setUnitPrice();
        order1.computePrice();
        order1.display();

        System.out.println();

        System.out.println("--- Processing Shipped Order ---");
        ShippedOrder order2 = new ShippedOrder();
        order2.setCustomerName();
        order2.setCustomerNumber();
        order2.setQuantityOrdered();
        order2.setUnitPrice();
        order2.computePrice();
        order2.display();
    }
}
