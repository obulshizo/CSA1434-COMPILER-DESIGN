#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100  // Maximum length for input line

// Function to check for single-line comments (//)
int is_single_line_comment(char *line) {
    return strstr(line, "//") != NULL;
}

// Function to check for multi-line comments (/* */)
int is_multi_line_comment(char *line) {
    return strstr(line, "/*") != NULL && strstr(line, "*/") != NULL;
}

// Function to handle comment detection in a line
void process_comment(char *line) {
    // Check for single-line comment
    if (is_single_line_comment(line)) {
        printf("Single-line comment detected: %s\n", line);
    }
    // Check for multi-line comment (only detect if the start and end exist on the same line)
    else if (is_multi_line_comment(line)) {
        printf("Multi-line comment detected: %s\n", line);
    } else {
        printf("No comment in the line: %s\n", line);
    }
}

int main() {
    char input[MAX_LENGTH];

    // Example input with comments
    printf("Enter a line of code to check for comments: ");
    fgets(input, MAX_LENGTH, stdin);  // Read the line of input

    process_comment(input);  // Process and identify if there's a comment in the line

    return 0;
}
