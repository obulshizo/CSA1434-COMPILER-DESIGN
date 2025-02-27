#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000  // Maximum length for the input string

// Function to count whitespaces and newline characters
void count_whitespaces_and_newlines(char *input) {
    int whitespace_count = 0;
    int newline_count = 0;

    // Iterate through each character in the input string
    for (int i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {  // Check if the character is a whitespace (space, tab, etc.)
            whitespace_count++;
        }
        if (input[i] == '\n') {   // Check if the character is a newline
            newline_count++;
        }
    }

    // Output the results
    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);
}

int main() {
    char input[MAX_LENGTH];

    // Taking input from the user
    printf("Enter the text to analyze (press Enter to submit):\n");
    fgets(input, MAX_LENGTH, stdin);  // Read input line

    // Count whitespaces and newline characters
    count_whitespaces_and_newlines(input);

    return 0;
}
