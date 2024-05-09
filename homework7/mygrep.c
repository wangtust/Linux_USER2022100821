#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <regex.h>
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    int opt;
    int line_number = 0;
    int print_line_number = 0;
    char *pattern = NULL;
    char *filename = NULL;

    // Parse command line options
    while ((opt = getopt(argc, argv, "n")) != -1) {
        if (opt == 'n') {
            print_line_number = 1;
        } else {
            printf("Usage: %s [-n] <pattern> <filename>\n", argv[0]);
            return 1;
        }
    }

    // Check if pattern and filename are provided as arguments
    if (optind + 2 != argc) {
        printf("Usage: %s [-n] <pattern> <filename>\n", argv[0]);
        return 1;
    }

    pattern = argv[optind];
    filename = argv[optind + 1];

    FILE *file = fopen(filename, "r"); // Open the file
    if (file == NULL) {
        printf("Error: File '%s' not found\n", filename);
        return 1;
    }

    regex_t regex;
    int reti;
    char msgbuf[100];

    // Compile regular expression
    reti = regcomp(&regex, pattern, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];     // Read each line from the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line_number++;
        // Execute regular expression
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            if (print_line_number) {
                printf("%d: %s", line_number, line);
            } else {
                printf("%s", line);
            }
        }
    }

    // Free memory allocated to the pattern buffer by regcomp()
    regfree(&regex);
    fclose(file);      // Close the file
    return 0;
}