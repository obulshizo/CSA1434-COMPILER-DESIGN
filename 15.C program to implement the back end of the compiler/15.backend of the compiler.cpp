#include <stdio.h>
#include <string.h>

void generateCode(char op[], char arg1[], char arg2[], char result[]) {
    if (strcmp(op, "+") == 0)
        printf("MOV R0, %s\nADD R0, %s\nMOV %s, R0\n", arg1, arg2, result);
    else if (strcmp(op, "-") == 0)
        printf("MOV R0, %s\nSUB R0, %s\nMOV %s, R0\n", arg1, arg2, result);
    else if (strcmp(op, "*") == 0)
        printf("MOV R0, %s\nMUL R0, %s\nMOV %s, R0\n", arg1, arg2, result);
    else if (strcmp(op, "/") == 0)
        printf("MOV R0, %s\nDIV R0, %s\nMOV %s, R0\n", arg1, arg2, result);
    else if (strcmp(op, "=") == 0)
        printf("MOV %s, %s\n", result, arg1);
    else
        printf("Invalid operation!\n");
}

int main() {
    char op[10], arg1[10], arg2[10], result[10];
    int n;

    printf("Enter the number of three-address code statements: ");
    scanf("%d", &n);

    printf("Enter the three-address code (Format: result = arg1 op arg2):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %s", result, arg1, op, arg2);
        generateCode(op, arg1, arg2, result);
    }

    return 0;
}

