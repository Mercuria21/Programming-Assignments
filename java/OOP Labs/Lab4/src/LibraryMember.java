/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Danial Johan bin Ahmad, CS01085391
 */
public class LibraryMember{
    private String memberName;
    private int booksBorrowed;
    private static int totalMembers;
    
    public LibraryMember(){
        this("Guest", 0);
    }
    
    public LibraryMember(String memberName){
        this(memberName, 1);
    }
    
    public LibraryMember(String memberName, int booksBorrowed){
        this.memberName = memberName;
        this.booksBorrowed = booksBorrowed;
        
        totalMembers++;
    }
    
    public void borrowBook(int count){
        this.booksBorrowed += count;
    }
    
    public void returnBook(int count){
        this.booksBorrowed = Math.max(0, this.booksBorrowed - count);
    }
    
    public void borrowBook(){
        this.borrowBook(1);
    }
    
    public LibraryMember mergeMembership(LibraryMember other){
        String newName = "Merged-" + this.memberName;
        int newBooks = this.booksBorrowed + other.booksBorrowed;
        
        return new LibraryMember(newName, newBooks);
    }
    
    public static int getTotalMembers(){
        return totalMembers;
    }
    
    public void displayInfo(){
        System.out.println("Member: " + this.memberName + ", Books Borrowed: " + this.booksBorrowed);
    }
}
