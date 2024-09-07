#include <stdio.h>
#include <string.h>

// Structure to store book details
struct Book {
    int id;
    char title[100];
    char author[100];
};

// Global array of books and count of books
struct Book library[100];
int count = 0;

// Function to add a book to the library
void addBook() {
    struct Book newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    getchar(); // To consume the newline character left by scanf
    printf("Enter book title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character
    printf("Enter book author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    library[count] = newBook;
    count++;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks() {
    if (count == 0) {
        printf("No books in the library!\n");
    } else {
        printf("Library Books:\n");
        for (int i = 0; i < count; i++) {
            printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
        }
    }
}

// Function to search for a book by its ID
void searchBook() {
    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("Book found: ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found!\n");
}

// Function to delete a book by its ID
void deleteBook() {
    int id, i, j;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (library[i].id == id) {
            for (j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

// Main function
int main() {
    int choice;

    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        default:
            printf("Invalid choice! Exiting the program.\n");
    }

    return 0;
}
