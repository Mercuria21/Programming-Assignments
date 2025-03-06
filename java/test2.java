import java.util.Scanner;

public class test2{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("The following list is a test to see if  a loop to choose from a list can work properly");
        System.out.println("1. Strawberry");
        System.out.println("2. Manggo");
        System.out.println("3. Vanilla");
        System.out.println("4. Apple");
        System.out.print("Please enter a selection: ");

        int choice = scanner.nextInt();
        scanner.close();

    
        switch(choice){
            case 1:
                System.out.println("You chose Strawberry");
                break;
            case 2:
                System.out.println("You chose Manggo");
                break;
            case 3:
                System.out.println("You chose Vanilla");
                break;
            case 4:
                System.out.println("You chose Apple");
                break;
            default:
                System.out.println("Invalid selection. Please try again.");
        }
    }
}