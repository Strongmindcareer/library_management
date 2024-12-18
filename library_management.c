#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store book information
struct Book {
    int bookID;
    char title[50];
    char author[50];
    int year;
};

// Function declarations
void addBook(struct Book books[], int *count);
void displayBooks(struct Book books[], int count);
void searchBook(struct Book books[], int count);
void updateBook(struct Book books[], int count);
void printHeader();

// ANSI color codes for formatting
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define CYAN_COLOR "\033[1;36m"
#define MAGENTA_COLOR "\033[1;35m"

int main() {
    struct Book books[100];  // Array to store book records
    int count = 0;  // Number of books
    int choice;

    while(1) {
        printHeader();
        printf(CYAN_COLOR "1. Add a Book\n" RESET_COLOR);
        printf(GREEN_COLOR "2. Display All Books\n" RESET_COLOR);
        printf(YELLOW_COLOR "3. Search for a Book\n" RESET_COLOR);
        printf(MAGENTA_COLOR "4. Update a Book\n" RESET_COLOR);
        printf(RED_COLOR "5. Exit\n" RESET_COLOR);
        printf("------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                updateBook(books, count);
                break;
            case 5:
                printf(RED_COLOR "Exiting system. Goodbye!\n" RESET_COLOR);
                exit(0);
            default:
                printf(RED_COLOR "Invalid choice! Please try again.\n" RESET_COLOR);
        }
    }

    return 0;
}

// Function to print the header
void printHeader() {
    printf("\n");
    printf("------------------------------------------------\n");
    printf(CYAN_COLOR "  Welcome to the Enhanced Library Management System\n" RESET_COLOR);
    printf("------------------------------------------------\n");
}

// Function to add a book
void addBook(struct Book books[], int *count) {
    printf(GREEN_COLOR "\nEnter book ID: " RESET_COLOR);
    scanf("%d", &books[*count].bookID);
    
    printf(CYAN_COLOR "Enter book title: " RESET_COLOR);
    getchar();  // to clear the newline left by previous scanf
    fgets(books[*count].title, 50, stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0';  // Remove the newline character

    printf(YELLOW_COLOR "Enter author name: " RESET_COLOR);
    fgets(books[*count].author, 50, stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0';  // Remove the newline character

    printf(MAGENTA_COLOR "Enter year of publication: " RESET_COLOR);
    scanf("%d", &books[*count].year);

    (*count)++;
    printf(GREEN_COLOR "\nBook added successfully!\n" RESET_COLOR);
}

// Function to display all books
void displayBooks(struct Book books[], int count) {
    if(count == 0) {
        printf(RED_COLOR "\nNo books available in the library.\n" RESET_COLOR);
        return;
    }

    printf("\n------------------------------------------------\n");
    printf(CYAN_COLOR "Book ID\tTitle\t\t\tAuthor\t\tYear\n" RESET_COLOR);
    printf("------------------------------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%s\t\t%d\n", books[i].bookID, books[i].title, books[i].author, books[i].year);
    }
    printf("------------------------------------------------\n");
}

// Function to search for a book
void searchBook(struct Book books[], int count) {
    int searchID, found = 0;
    printf(CYAN_COLOR "\nEnter book ID to search: " RESET_COLOR);
    scanf("%d", &searchID);

    for(int i = 0; i < count; i++) {
        if(books[i].bookID == searchID) {
            printf(GREEN_COLOR "\nBook found!\n" RESET_COLOR);
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year of Publication: %d\n", books[i].year);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf(RED_COLOR "\nBook not found with the given ID.\n" RESET_COLOR);
    }
}

// Function to update a book's details
void updateBook(struct Book books[], int count) {
    int updateID, found = 0;
    printf(CYAN_COLOR "\nEnter book ID to update: " RESET_COLOR);
    scanf("%d", &updateID);

    for(int i = 0; i < count; i++) {
        if(books[i].bookID == updateID) {
            printf(GREEN_COLOR "\nBook found! Enter new details.\n" RESET_COLOR);
            printf(CYAN_COLOR "Enter new title: " RESET_COLOR);
            getchar();  // to clear the newline left by previous scanf
            fgets(books[i].title, 50, stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';  // Remove the newline character

            printf(YELLOW_COLOR "Enter new author name: " RESET_COLOR);
            fgets(books[i].author, 50, stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0';  // Remove the newline character

            printf(MAGENTA_COLOR "Enter new year of publication: " RESET_COLOR);
            scanf("%d", &books[i].year);

            printf(GREEN_COLOR "\nBook updated successfully!\n" RESET_COLOR);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf(RED_COLOR "\nBook not found with the given ID.\n" RESET_COLOR);
    }
}
