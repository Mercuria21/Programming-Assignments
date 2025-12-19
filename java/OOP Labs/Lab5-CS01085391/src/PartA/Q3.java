/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PartA;

import java.util.Scanner;

/**
 * Object Oriented Programming, Lab 5
 * @author Danial Johan bin Ahmad, CS01085391
 */

public class Q3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Please enter title: ");
        String word = scan.nextLine();
        
        String[] words = word.trim().split("\\s+");
        StringBuilder reversed = new StringBuilder();

        for (int i = words.length - 1; i >= 0; i--) {
            reversed.append(words[i]);
            if (i > 0) reversed.append(" ");
        }

        System.out.println(reversed);
    }
}
