/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package q1;

import java.util.Objects;

/**
 CSEB3313 Object-oriented Programming
 Danial Johan bin Ahmad, CS01085391
 Lab 3
 **/
public class ComplexNumber {

    private final double real;
    private final double imag;
    
    public ComplexNumber() {
        this.real = 0.0;
        this.imag = 0.0;
    }
    
    public ComplexNumber(double r, double i) {
        this.real = r;
        this.imag = i;
    }

    public double getReal() {
        return real;
    }
    
    public double getImag() {
        return imag;
    }
    
    public ComplexNumber add(ComplexNumber other) {
        return new ComplexNumber(this.real + other.real, this.imag + other.imag);
    }
    
    public ComplexNumber subtract(ComplexNumber other) {
        return new ComplexNumber(this.real - other.real, this.imag - other.imag);
    }
    
    public ComplexNumber multiply(ComplexNumber other) {
        double newReal = this.real * other.real - this.imag * other.imag;
        double newImag = this.real * other.imag + this.imag * other.real;
        return new ComplexNumber(newReal, newImag);
    }
     
    public ComplexNumber divide(ComplexNumber other) {
        double denominator = other.real * other.real + other.imag * other.imag;

        if (denominator == 0) {
            throw new IllegalArgumentException("Cannot divide by a complex zero (0 + 0i).");
        }

        double newReal = (this.real * other.real + this.imag * other.imag) / denominator;
        double newImag = (this.imag * other.real - this.real * other.imag) / denominator;
        return new ComplexNumber(newReal, newImag);
    }
    
    public double magnitude() {
        return Math.hypot(this.real, this.imag);
    }
    
    public ComplexNumber conjugate() {
        return new ComplexNumber(this.real, -this.imag);
    }
    
    public boolean equals(ComplexNumber other, double epsilon) {
        return Math.abs(this.real - other.real) < epsilon &&
               Math.abs(this.imag - other.imag) < epsilon;
    }
    
    public String toString() {
        if (imag == 0) {
            return String.valueOf(real);
        }
        if (real == 0) {
            return imag + "i";
        }
        if (imag < 0) {
            return real + " - " + (-imag) + "i";
        }
        return real + " + " + imag + "i";
    }

    public static ComplexNumber fromPolar(double r, double theta) {
        double realPart = r * Math.cos(theta);
        double imagPart = r * Math.sin(theta);
        return new ComplexNumber(realPart, imagPart);
    }
}
    
