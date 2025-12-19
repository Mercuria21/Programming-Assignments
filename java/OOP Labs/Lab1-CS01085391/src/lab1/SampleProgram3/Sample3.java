/* 
Sample Program 3: 
File: Sample3.java 
*/ 
package lab1.cs01085391.SampleProgram3;
 
import java.util.Scanner; 
class Sample3{ 
    public static void main (String [] args) { 
        String firstName, lastName, programme; 
 
        Scanner input = new Scanner(System.in); 
        System.out.print("What is your first name? "); 
        firstName = input.next(); 
        System.out.print("What is your last name? "); 
        lastName = input.next(); 
        System.out.print("Enter your programme: "); 
        programme = input.nextLine(); 
 
 System.out.println("Your full name is " + firstName + " " + lastName); 
 System.out.println("Programme: " + programme); 
    } 
} 
