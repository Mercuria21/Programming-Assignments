/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;

/**
 *
 * @author mikesieg
 */

abstract class Marks {
    public abstract double getPercentage();
}

class A extends Marks {
    private int mark1, mark2, mark3;

    public A(int m1, int m2, int m3) {
        this.mark1 = m1;
        this.mark2 = m2;
        this.mark3 = m3;
    }

    @Override
    public double getPercentage() {
        int total = mark1 + mark2 + mark3;
        return (total / 300.0) * 100;
    }
}

class B extends Marks {
    private int mark1, mark2, mark3, mark4;

    public B(int m1, int m2, int m3, int m4) {
        this.mark1 = m1;
        this.mark2 = m2;
        this.mark3 = m3;
        this.mark4 = m4;
    }

    @Override
    public double getPercentage() {
        int total = mark1 + mark2 + mark3 + mark4;
        return (total / 400.0) * 100;
    }
}

public class exercise3 {
    public static void main(String[] args) {
        A studentA = new A(85, 90, 80);
        System.out.println("Percentage of Student A: " + studentA.getPercentage() + "%");

        B studentB = new B(75, 85, 90, 95);
        System.out.println("Percentage of Student B: " + studentB.getPercentage() + "%");
    }
}
