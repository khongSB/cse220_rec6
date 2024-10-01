#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    float price;
    int stock;
    char *title;
    char **authors;
} Book;

typedef struct BookNode {
    Book *book;
    struct BookNode *next;
} BookNode;

Book * add_to_end(BookNode *head, Book *book) {
    BookNode *current = head;
    BookNode *previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
    }
    current = malloc(sizeof(BookNode));
    current->next = NULL;
    if (previous != NULL) {
        previous->next = current;
    }
    current->book = book;
    return book;
}

Book * search(BookNode *head, char *title) {
    BookNode *current = head;
    while (current != NULL) {
        if (strcmp(current->book->title, title) == 0) {
            return current->book;
        }
        current = current->next;
    }
    return NULL;
}

Book * remove_book(BookNode *head, char *title) {
    BookNode *current = head;
    BookNode *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->book->title, title) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            }
            Book *book = current->book;
            free(current);
            return book;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

void print_books(BookNode *head) {
    BookNode *current = head;
    while (current != NULL) {
        printf("Book title: %s\n", current->book->title);
        current = current->next;
    }
}

int main() {
    BookNode *head = NULL;

    head = malloc(sizeof(BookNode));
    head->next = NULL;
    head->book = NULL;
    char *title1 = "The C Programming Language 1";
    char *title2 = "The C Programming Language 2";
    char *title3 = "The C Programming Language 3";

    Book *book1 = malloc(sizeof(Book));
    Book *book2 = malloc(sizeof(Book));
    Book *book3 = malloc(sizeof(Book));

    book1->title = malloc(sizeof(char) * 100);
    book1->price = 10.0;
    book2->title = malloc(sizeof(char) * 100);
    book3->title = malloc(sizeof(char) * 100);

    strncpy(book1->title, title1, 100);
    strncpy(book2->title, title2, 100);
    strncpy(book3->title, title3, 100);

    add_to_end(head, book3);
    add_to_end(head, book1);
    add_to_end(head, book2);

    print_books(head->next);

    Book *book = remove_book(head->next, title2);
    printf("\n");
    print_books(head->next);

    book = search(head->next, title1);
    printf("\n");
    if (book != NULL) {
        printf("Book found: %s %f\n", book->title, book->price);
    }



    return EXIT_SUCCESS;
}