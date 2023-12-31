#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    // Command line/argument error handling
    if (argc != 2){
        printf("Error: Incorrect argument usage. Ex: ./a.out <filename>\n");
        return 1;
    }

    // Obtain file name & create file
    FILE *file = fopen(argv[1], "r");

    // File error handling
    if (file == NULL) {
        printf("Error: Error retrieving and opening file name\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    char *second_last_line = NULL;
    char *last_line = NULL;

    // Begin reading lines
    while (getline(&line, &len, file) != -1) {
        printf("%s", line);
        if (second_last_line != NULL){
            free(second_last_line);
        }

        second_last_line = last_line;
        last_line = strdup(line);
    }

    // Print statements
    printf("\n\n");
    if (second_last_line != NULL){
        printf("Second last line: %s", second_last_line);
        free(second_last_line);
    }
    if (last_line != NULL){
        printf("Last line: %s\n\n", last_line);
        free(last_line);
    }

    // Close file
    fclose(file);
    
    // Free memory allocation done by getLine
    free(line);
}