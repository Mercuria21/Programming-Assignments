/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package q2;

/*
 CSEB3313 Object-oriented Programming
 Danial Johan bin Ahmad, CS01085391
 Lab 3
 */
import java.util.Scanner;
import q1.ComplexNumber;


public class TestComplex {
    
    public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    
        //input for the two numbers
        System.out.print("Enter the first pair of complex numbers (real imag): ");
        double real1 = input.nextDouble();
        double imag1 = input.nextDouble();
        ComplexNumber c1 = new ComplexNumber(real1, imag1);
    
        System.out.print("Enter the second pair of complex number (real imag): ");
        double real2 = input.nextDouble();
        double imag2 = input.nextDouble();
        ComplexNumber c2 = new ComplexNumber(real2, imag2);
    
        System.out.println("\nResults: ");
    
        // Addition
        System.out.println("(" + c1 + ") + (" + c2 + ") = " + c1.add(c2));

        // Subtraction
        System.out.println("(" + c1 + ") - (" + c2 + ") = " + c1.subtract(c2));

        // Multiplication
        System.out.println("(" + c1 + ") * (" + c2 + ") = " + c1.multiply(c2));
    
        // Division
        try {
        System.out.println("(" + c1 + ") / (" + c2 + ") = " + c1.divide(c2));
        } catch (IllegalArgumentException e) {
            System.out.println("Division by zero complex number");
        }
    
        System.out.printf("|%s| = %.3f\n", c1, c1.magnitude());
        System.out.printf("|%s| = %.3f\n", c2, c2.magnitude());
    
        System.out.println("Conjugate of " + c1 + " is " + c1.conjugate());
        System.out.println("Conjugate of " + c2 + " is " + c2.conjugate());
    
        System.out.println("\n--- Polar Coordinates Test ---");
        System.out.print("Enter magnitude r: ");
        double r = input.nextDouble();
        System.out.print("Enter angle theta in radians: ");
        double theta = input.nextDouble();
    
        ComplexNumber fromPolar = ComplexNumber.fromPolar(r, theta);
        System.out.println("The complex number from polar(r=" + r + ", θ=" + theta + ") is " + fromPolar);
    
        input.close();
    }
}

