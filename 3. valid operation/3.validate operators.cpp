#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100  // Maximum length for input

// Function to validate if the character is a valid arithmetic operator
int is_arithmetic_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to process and validate operators in the input
void process_operators(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_arithmetic_operator(input[i])) {
            printf("Operator: %c\n", input[i]);
        } else if (!isspace(input[i])) {
            printf("Invalid character detected: %c\n", input[i]);
        }
    }
}

int main() {
    char input[MAX_LENGTH];

    // Taking input from the user
    printf("Enter the code to validate arithmetic operators: ");
    fgets(input, MAX_LENGTH, stdin);  // Read input line

    // Process the input to validate operators
    process_operators(input);

    return 0;
}
