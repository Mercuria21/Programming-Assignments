/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab6;

/**
 *
 * @author Danial Johan bin Ahmad
 * CS01085391, Lab 6, Object Oriented Program 
 */

class Media {
    private String title;
    private String genre;
    private int publicationYear;

    public Media(String title, String genre, int pubYear) {
        this.title = title;
        this.genre = genre;
        this.publicationYear = pubYear;
    }

    public void displayInfo() {
        System.out.println("Title: " + title);
        System.out.println("Genre: " + genre);
        System.out.println("Year: " + publicationYear);
    }

    public boolean isOldEdition(int currYear) {
        return (currYear - publicationYear) > 10;
    }
}

class Book extends Media {
    private String author;
    private int totalPages;

    public Book(String title, String genre, int pubYear, String author, int totPages) {
        super(title, genre, pubYear);
        this.author = author;
        this.totalPages = totPages;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Author: " + author);
        System.out.println("Total Pages: " + totalPages);
    }
}

class DVD extends Media {
    private int duration;
    private String director;

    public DVD(String title, String genre, int pubYear, int duration, String director) {
        super(title, genre, pubYear);
        this.duration = duration;
        this.director = director;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Duration: " + duration + " mins");
        System.out.println("Director: " + director);
    }

    public boolean isFeatureFilm() {
        return duration > 40;
    }
}

public class exercise1 {   
    public static void main(String[] args) {
        int currentYear = 2025;

        Book myBook = new Book("Java Programming", "Education", 2010, "John Doe", 450);
        System.out.println("--- Book Details ---");
        myBook.displayInfo();
        System.out.println("Is Old Edition: " + myBook.isOldEdition(currentYear));

        System.out.println();

        DVD myDVD = new DVD("Inception", "Sci-Fi", 2010, 148, "Christopher Nolan");
        System.out.println("--- DVD Details ---");
        myDVD.displayInfo();
        System.out.println("Is Feature Film: " + myDVD.isFeatureFilm());
        System.out.println("Is Old Edition: " + myDVD.isOldEdition(currentYear));
    }
}
