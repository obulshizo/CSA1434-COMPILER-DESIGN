#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100  // Maximum length for identifiers or constants

// Function to identify if a string is an identifier
int is_identifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_') return 0;  // Must start with letter or underscore
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') return 0;  // Can only contain letters, digits, or underscores
    }
    return 1;
}

// Function to identify if a string is a number (integer or float)
int is_number(char *str) {
    int dot_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) return 0;  // More than one dot is invalid
        } else if (!isdigit(str[i])) {
            return 0;  // Must be a digit or a single dot for floating-point
        }
    }
    return 1;  // Valid number
}

// Function to print the type of token
void print_token(char *token) {
    if (is_identifier(token)) {
        printf("Identifier: %s\n", token);
    } else if (is_number(token)) {
        printf("Constant: %s\n", token);
    } else if (strchr("+-*/%=<>&|^!", token[0])) {
        printf("Operator: %s\n", token);
    } else {
        printf("Unknown token: %s\n", token);
    }
}

// Function to handle comments and unnecessary spaces
void process_input(char *input) {
    char token[MAX_LENGTH];
    int j = 0;  // Index for storing tokens
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            continue;  // Skip spaces, tabs, and newlines
        }

        // Handle single-line comments
        if (input[i] == '/' && input[i + 1] == '/') {
            while (input[i] != '\n' && input[i] != '\0') {
                i++;
            }
            continue;
        }

        // Handle multi-line comments
        if (input[i] == '/' && input[i + 1] == '*') {
            i += 2;  // Skip "/*"
            while (!(input[i] == '*' && input[i + 1] == '/')) {
                i++;
            }
            i += 2;  // Skip "*/"
            continue;
        }

        // Extract token characters
        if (isalnum(input[i]) || input[i] == '_') {
            token[j++] = input[i];
        } else {
            if (j > 0) {
                token[j] = '\0';
                print_token(token);
                j = 0;  // Reset token buffer
            }

            // If it's an operator or punctuation mark
            if (strchr("+-*/%=<>&|^!;", input[i])) {
                token[0] = input[i];
                token[1] = '\0';
                print_token(token);
            }
        }
    }

    // Print the last token if it exists
    if (j > 0) {
        token[j] = '\0';
        print_token(token);
    }
}

int main() {
    char input[MAX_LENGTH];
    
    printf("Enter the code to analyze:\n");
    fgets(input, MAX_LENGTH, stdin);  // Read the input
    
    process_input(input);  // Process the input and identify tokens
    
    return 0;
}
