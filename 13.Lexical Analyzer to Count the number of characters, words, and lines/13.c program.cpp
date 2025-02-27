#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int char_count = 0, word_count = 0, line_count = 0;
    int in_word = 0;

    printf("Enter text (Press Ctrl+D to end input on Linux/Mac or Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {
        char_count++;  

        if (ch == '\n') {
            line_count++;  
        }

        if (isspace(ch)) {
            in_word = 0;  
        } else if (!in_word) {
            in_word = 1;
            word_count++;  
        }
    }

  
    printf("\nCharacters: %d\n", char_count);
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);

    return 0;
}

