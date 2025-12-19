/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package PartA;

/**
 * Object Oriented Programming, Lab 5
 * @author Danial Johan bin Ahmad, CS01085391
 */

import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Please enter a username: ");
        String username = scan.nextLine();
        
        if (!username.matches("^[A-Za-z].*")) {
            System.out.println("Invalid: Username must start with a letter.");
        } 
        else if (!username.matches("^[A-Za-z0-9._]+$")) {
            System.out.println("Invalid: Username can only contain letters, digits, underscores, or dots.");
        } 
        else if (username.length() < 5 || username.length() > 15) {
            System.out.println("Invalid: Username must be 5 to 15 characters long.");
        } 
        else {
            System.out.println("Valid");        
        }
 }
}