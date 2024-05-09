#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
int main(int argc, char *argv[]) {
    // Check if filename and string to search are provided as arguments
    FILE *file ;
    if (argc < 2) {
        printf("Usage: %s <string> <filename> \n", argv[0]);
        return 1;
    }
    if(argc==3)
    {
    file = fopen(argv[2], "r"); // Open the file
    if (file == NULL) {
        printf("Error: File '%s' not found\n", argv[2]);
        return 1;
    }
    }
    else
     file = stdin; 
    char line[MAX_LINE_LENGTH];     // Read each line from the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) 
        // Search for the string in the line
        if (strstr(line, argv[1]) != NULL)   printf("%s", line);
    fclose(file);      // Close the file
    return 0;
}
