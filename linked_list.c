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

int main() {
    BookNode *head = NULL;
    BookNode *current = NULL;
    BookNode *previous = NULL;
    int num_books = 3;

    for(int i = 0; i < num_books; i++) {
        current = malloc(sizeof(BookNode));
        current->next = NULL;
        if (previous != NULL) {
            previous->next = current;
        }
        if (head == NULL) {
            head = current;
        }
        current->book = malloc(sizeof(Book));
        current->book->price = 10.0;
        current->book->title = malloc(sizeof(char) * 100);
        snprintf(current->book->title, 100, "The C Programming Language %d", i);
        previous = current;
    }

    current = head;
    while (current != NULL) {
        printf("Book title: %s\n", current->book->title);
        Book *to_free = current->book;
        BookNode *to_free_node = current;
        current = current->next;
        free(to_free->title);
        free(to_free);
        free(to_free_node);
    }

    return EXIT_SUCCESS;
}