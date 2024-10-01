#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    float price;
    int stock;
    char *title;
    char **authors;
} Book;

int main() {
    Book *book = malloc(sizeof(Book));
    book->price = 10.0;
    book->title = malloc(sizeof(char) * 100);
    
    strncpy(book->title, "The C Programming Language", 100);
    printf("Book title: %s\n", book->title);

    char *author = malloc(sizeof(char) * 100);
    strncpy(author, "Brian W. Kernighan", 100);
    book->authors = malloc(sizeof(char *) * 3);
    book->authors[0] = author;
    char *author2 = malloc(sizeof(char) * 100);
    strncpy(author2, "Dennis M. Ritchie", 100);
    book->authors[1] = author2;
    book->authors[2] = NULL;

    char **current = book->authors;
    while (*current != NULL) {
        printf("Author: %s\n", *current);
        current++;
    }

    return EXIT_SUCCESS;
}