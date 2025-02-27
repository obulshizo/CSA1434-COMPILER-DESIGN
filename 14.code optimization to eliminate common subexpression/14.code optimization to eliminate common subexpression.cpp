#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char expr[50];  
    char result[10]; 
} Expression;

Expression expressions[MAX];
int exprCount = 0;


int findCommonSubexpression(char *expr) {
    for (int i = 0; i < exprCount; i++) {
        if (strcmp(expressions[i].expr, expr) == 0) {
            return i;  
        }
    }
    return -1;
}


void optimizeCode() {
    printf("\nOptimized Code:\n");
    
    for (int i = 0; i < exprCount; i++) {
        int index = findCommonSubexpression(expressions[i].expr);
        
        if (index < i) { 
            printf("%s = %s\n", expressions[i].result, expressions[index].result);
        } else {
            printf("%s = %s\n", expressions[i].result, expressions[i].expr);
        }
    }
}

int main() {
    int n;
    char expr[50], result[10];

    printf("Enter the number of expressions: ");
    scanf("%d", &n);
    getchar(); 

    printf("Enter expressions (e.g., t1 = a + b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s = %[^\n]", result, expr); 
        getchar(); 

        strcpy(expressions[exprCount].result, result);
        strcpy(expressions[exprCount].expr, expr);
        exprCount++;
    }

    optimizeCode(); 

    return 0;
}

