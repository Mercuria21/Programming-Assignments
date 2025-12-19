/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author Danial Johan bin Ahmad, CS01085391
 */
import LibraryMember;

public class LibraryDemo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        LibraryMember member1 = new LibraryMember();
        LibraryMember member2 = new LibraryMember("Alice");
        LibraryMember member3 = new LibraryMember("Bob", 2);
        
        member2.borrowBook();
        member2.borrowBook(1);
        
        member3.returnBook(1);
        
        
        LibraryMember mergedMember = member2.mergeMembership(member3);
        
        System.out.println("--- All Member Details ---");
        member1.displayInfo();
        member2.displayInfo();
        member3.displayInfo();
        mergedMember.displayInfo();
        System.out.println();
        
        int total = LibraryMember.getTotalMembers();
        System.out.println("Total members registered: " + total);
    }
}
