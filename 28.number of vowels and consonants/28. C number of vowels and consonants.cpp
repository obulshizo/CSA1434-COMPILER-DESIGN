#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int vowel_count = 0, consonant_count = 0;
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = tolower(sentence[i]);
        
        if (ch >= 'a' && ch <= 'z') {  // Check if it's a letter
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowel_count++;
            else
                consonant_count++;
        }
    }

    printf("Vowels: %d\n", vowel_count);
    printf("Consonants: %d\n", consonant_count);

    return 0;
}

