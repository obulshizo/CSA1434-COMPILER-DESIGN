#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Function prototypes
int parse_expr(char *expr, int *index);
int parse_term(char *expr, int *index);
int parse_factor(char *expr, int *index);
int parse_number(char *expr, int *index);

// Function to check if the current character is a number
int is_number(char c) {
    return isdigit(c);
}

// Function to check if the current character is a valid operator (+, -, *, /)
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to parse a number (a sequence of digits)
int parse_number(char *expr, int *index) {
    if (!is_number(expr[*index])) {
        return 0; // Not a number
    }

    // Consume the number
    while (isdigit(expr[*index])) {
        (*index)++;
    }

    return 1;
}

// Function to parse a factor
int parse_factor(char *expr, int *index) {
    // If the current character is a number, parse it
    if (parse_number(expr, index)) {
        return 1;
    }
    // If the current character is '(', we expect an expression inside parentheses
    else if (expr[*index] == '(') {
        (*index)++; // Consume '('
        if (parse_expr(expr, index)) {
            if (expr[*index] == ')') {
                (*index)++; // Consume ')'
                return 1;
            }
        }
    }
    return 0; // Invalid factor
}

// Function to parse a term (which is a sequence of factors and operators)
int parse_term(char *expr, int *index) {
    if (!parse_factor(expr, index)) {
        return 0; // Invalid term
    }

    // After the first factor, there can be more '*' or '/' operators with factors
    while (is_operator(expr[*index]) && (expr[*index] == '*' || expr[*index] == '/')) {
        (*index)++; // Consume the operator
        if (!parse_factor(expr, index)) {
            return 0; // Invalid term
        }
    }
    return 1;
}

// Function to parse an expression (which is a sequence of terms and operators)
int parse_expr(char *expr, int *index) {
    if (!parse_term(expr, index)) {
        return 0; // Invalid expression
    }

    // After the first term, there can be more '+' or '-' operators with terms
    while (is_operator(expr[*index]) && (expr[*index] == '+' || expr[*index] == '-')) {
        (*index)++; // Consume the operator
        if (!parse_term(expr, index)) {
            return 0; // Invalid expression
        }
    }
    return 1;
}

// Function to check if the input string matches the grammar
int validate_grammar(char *expr) {
    int index = 0;

    // Parse the expression
    if (parse_expr(expr, &index) && expr[index] == '\0') {
        return 1; // Expression is valid
    }
    return 0; // Expression is not valid
}

int main() {
    char expr[MAX_LENGTH];

    // Input expression
    printf("Enter the expression: ");
    fgets(expr, MAX_LENGTH, stdin);

    // Remove trailing newline if present
    expr[strcspn(expr, "\n")] = '\0';

    // Validate the expression
    if (validate_grammar(expr)) {
        printf("The expression is valid as per the grammar.\n");
    } else {
        printf("The expression is invalid as per the grammar.\n");
    }

    return 0;
}
