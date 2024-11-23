#include <stdio.h>
#include <string.h>

char* reduceStr(const char* word, int* rem) {
    static char minWord[50];
    int count = 0;
    *rem = 0;

    char lastChar = '\0';

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] != lastChar) {
            minWord[count++] = word[i]; // Add the current character
            lastChar = word[i]; // Update lastChar
        } else {
            (*rem)++; // Count duplicates
        }
    }
    minWord[count] = '\0';

    return minWord;
}

int main(void) {
    int num;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);
    getchar();

    char word[num][50];
    int remove[num];

    for (int i = 0; i < num; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(word[i], sizeof(word[i]), stdin);
        word[i][strcspn(word[i], "\n")] = '\0';
    }

    printf("[");
    for (int i = 0; i < num; i++) {
        char* minWord = reduceStr(word[i], &remove[i]); // Get the minimized word
        printf("\"%s\":%d", minWord, remove[i]); // Print word and removed count
        if (i < num - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
