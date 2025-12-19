/* 
Sample Program 2: 
File: Sample2.java 
*/ 
package lab1.cs01085391.SampleProgram2;

import javax.swing.*; 
import java.awt.*;  
//for JFrame class and JOptionPane class 
//for Point class

class Sample2 { 
public static void main( String[] args ) { 
    JFrame window; 
    Point position; 
    String name; 
 
    window = new JFrame (); 
    position = new Point(200,500); 
 
    window.setSize(400,300); 
    window.setTitle("My First Java Program in Lab"); 
    window.setLocation(position); 
    window.setVisible(true); 
 
    name = JOptionPane.showInputDialog(null, "What is your name?"); 
    JOptionPane.showMessageDialog(window, "Nice to meet you, " + name + "."); 
    } 
}