/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PartB;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Object Oriented Programming, Lab 5
 * @author Danial Johan bin Ahmad, CS01085391
 */

public class Q1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double[] rain = new double[12];
        
        System.out.print("Please enter monthly rainfall (12 values)");
        for (int i = 0; i < 12; i++) {
            rain[i] = scan.nextDouble();
        }
        
        double total = 0;
        double min = rain[0];
        double max = rain[0];
        
        for (double r : rain) {
            total += r;
            if (r < min) min = r;
            if (r > max) max = r;
        }
        
        double average = total/12;
        
        double[] sorted = Arrays.copyOf(rain, 12);
        Arrays.sort(sorted);
        double median =  (sorted[5] + sorted[6]) / 2.0;
        
        double sumsq = 0;
        for (double r : rain){
            sumsq += Math.pow(r - average, 2);
        }
        
        double stddev = Math.sqrt(sumsq / 12);
        
        int countAboveSq = 0;
        for (double r : rain) {
            if (r > average) countAboveSq++;
        }
        
        // Output
        System.out.printf("Total Rainfall       : %.2f mm\n", total);
        System.out.printf("Average Rainfall     : %.2f mm\n", average);
        System.out.printf("Minimum Rainfall     : %.2f mm\n", min);
        System.out.printf("Maximum Rainfall     : %.2f mm\n", max);
        System.out.printf("Median Rainfall      : %.2f mm\n", median);
        System.out.printf("Standard Deviation   : %.2f\n", stddev);
        System.out.printf("Months Above Average : %d\n", countAboveSq);
    }
}
