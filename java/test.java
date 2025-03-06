import java.util.Scanner;

public class test {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();

		System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();

		int sum = num1 + num2;
		int difference = num1 - num2;
		
		double product = (double) num1 * num2;
		double quotient = (double) num1 / num2;

		System.out.println("Sum of " + num1 + " and " + num2 + " is: " + sum);
		System.out.println("Difference of " + num1 + " and " + num2 + " is: " + difference);
		System.out.println("Product of " + num1 + " and " + num2 + " is: " + product);
		System.out.println("Quotient of " + num1 + " and " + num2 + " is: " + quotient);
	}
}