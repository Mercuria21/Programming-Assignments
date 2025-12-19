/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PartA;

/**
 * Object Oriented Programming, Lab 5
 * @author Danial Johan bin Ahmad, CS01085391
 */

import java.util.Arrays;
import java.util.Scanner;
import java.util.HashSet<>;
import java.util.Set<>;

public class Q2 {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Please enter title: ");
        String title = scan.nextLine();
        
        String[] smallWords = {"a", "an", "the", "and", "or", "but", "of", "in", "on", "to"};
        Set<String> lowerWords = new HashSet<>(Arrays.asList(smallWords));

        String[] words = title.toLowerCase().split("\\s+");
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            if (i == 0 || i == words.length - 1 || !lowerWords.contains(word)) {
                result.append(Character.toUpperCase(word.charAt(0)))
                      .append(word.substring(1));
            } else {
                result.append(word);
            }
            if (i < words.length - 1) result.append(" ");
        }

        System.out.println("Output: " + result);     
    }
}
