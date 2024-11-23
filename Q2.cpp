#include <stdio.h>
#include <string.h>

void analyzeFrequency(char slogan[]) {
    char repeated[50] = {0};
    int repeatedNum[50] = {0};
    int len = 0;
    int isRepeated;

    for (int i = 0; slogan[i] != '\0'; i++) {
        isRepeated = 0;

        // Check if the character has already been counted
        for (int x = 0; x < len; x++) {
            if (slogan[i] == repeated[x]) {
                isRepeated = 1;
                break;
            }
        }

        // If not repeated, count its occurrences
        if (!isRepeated) {
            int count = 0;
            for (int j = 0; slogan[j] != '\0'; j++) {
                if (slogan[j] == slogan[i]) {
                    count++;
                }
            }

            repeated[len] = slogan[i];
            repeatedNum[len] = count;
            len++;
        }
    }

    // Print results in the expected format
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("'%c': %d", repeated[i], repeatedNum[i]);
        if (i != len - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main(void) {
    int n;
    printf("Enter the number of slogans: ");
    scanf("%d", &n);
    getchar();

    char slogans[n][50];
    for (int i = 0; i < n; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogans[i], sizeof(slogans[i]), stdin);
        slogans[i][strcspn(slogans[i], "\n")] = '\0';
    }

    for (int i = 0; i < n; i++) {
        printf("\"%s\": ", slogans[i]);
        analyzeFrequency(slogans[i]);
    }

    return 0;
}

