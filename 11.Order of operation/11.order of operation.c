#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN 100  // Maximum length of expression

// Function prototypes
double evaluateExpression(char* expr, int* index);
double parseNumber(char* expr, int* index);
double performOperation(double left, double right, char operator);

// Function to evaluate a number (integer or floating-point)
double parseNumber(char* expr, int* index) {
    double num = 0, factor = 1;
    int negative = 0;

    // Check for negative numbers
    if (expr[*index] == '-') {
        negative = 1;
        (*index)++;
    }

    // Read integer part
    while (isdigit(expr[*index])) {
        num = num * 10 + (expr[*index] - '0');
        (*index)++;
    }

    // Read decimal part
    if (expr[*index] == '.') {
        (*index)++;
        while (isdigit(expr[*index])) {
            num = num + (expr[*index] - '0') * (factor *= 0.1);
            (*index)++;
        }
    }

    return negative ? -num : num;
}

// Function to perform basic arithmetic operations
double performOperation(double left, double right, char operator) {
    switch (operator) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return right != 0 ? left / right : NAN;  // Avoid division by zero
        case '^': return pow(left, right);
        default: return 0;
    }
}

// Function to evaluate expressions with parentheses and operators
double evaluateExpression(char* expr, int* index) {
    double values[MAX_LEN];
    char operators[MAX_LEN];
    int valTop = -1, opTop = -1;

    while (expr[*index] != '\0' && expr[*index] != ')') {
        if (isspace(expr[*index])) {
            (*index)++;  // Skip spaces
            continue;
        }

        if (isdigit(expr[*index]) || expr[*index] == '-') {
            values[++valTop] = parseNumber(expr, index);
        } else if (expr[*index] == '(') {
            (*index)++;
            values[++valTop] = evaluateExpression(expr, index);
        } else if (strchr("+-*/^", expr[*index])) {
            while (opTop >= 0 &&
                   ((operators[opTop] == '^' && expr[*index] == '^') || 
                    (strchr("*/", operators[opTop]) && strchr("*/", expr[*index])) || 
                    (strchr("+-", operators[opTop]) && strchr("+-", expr[*index])))) {
                double right = values[valTop--];
                double left = values[valTop--];
                values[++valTop] = performOperation(left, right, operators[opTop--]);
            }
            operators[++opTop] = expr[*index];
            (*index)++;
        } else if (expr[*index] == ')') {
            (*index)++;
            break;
        } else {
            printf("Invalid character encountered: %c\n", expr[*index]);
            exit(1);
        }
    }

    while (opTop >= 0) {
        double right = values[valTop--];
        double left = values[valTop--];
        values[++valTop] = performOperation(left, right, operators[opTop--]);
    }

    return values[0];
}

int main() {
    char expression[MAX_LEN];
    printf("Enter a mathematical expression: ");
    fgets(expression, MAX_LEN, stdin);
    expression[strcspn(expression, "\n")] = 0;  // Remove newline

    int index = 0;
    double result = evaluateExpression(expression, &index);
    
    if (isnan(result)) {
        printf("Error: Division by zero\n");
    } else {
        printf("Result: %.6lf\n", result);
    }

    return 0;
}

