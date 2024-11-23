#include <stdio.h>
#include <string.h>

// Function to sort a string using bubble sort
void sortString(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i + 1; str[j] != '\0'; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main(void) {
    int numTransactions;
    printf("Enter number of elements in the array: ");
    scanf("%d", &numTransactions);
    getchar();

    char transactions[numTransactions][50], sortedTransactions[numTransactions][50];
    int isGrouped[numTransactions];

    // Input transactions
    for (int i = 0; i < numTransactions; i++) {
        printf("Enter element %d: ", i + 1);
        fgets(transactions[i], sizeof(transactions[i]), stdin);

        // Remove the newline character
        for (int j = 0; transactions[i][j] != '\0'; j++) {
            if (transactions[i][j] == '\n') {
                transactions[i][j] = '\0';
                break;
            }
        }

        // Copy transaction to sortedTransactions
        for (int j = 0; transactions[i][j] != '\0'; j++) {
            sortedTransactions[i][j] = transactions[i][j];
        }
        sortedTransactions[i][strlen(transactions[i])] = '\0';
    }

    // Sort each transaction string
    for (int i = 0; i < numTransactions; i++) {
        sortString(sortedTransactions[i]);
        isGrouped[i] = 0; // Initialize grouping status
    }

    // Group scrambled transactions
    printf("\nScrambled\n");
    for (int i = 0; i < numTransactions; i++) {
        if (isGrouped[i] == 0) {
            printf("[\"%s\"", transactions[i]);
            isGrouped[i] = 1;

            // Check for other transactions that are scrambled (anagrams)
            for (int j = i + 1; j < numTransactions; j++) {
                if (strcmp(sortedTransactions[i], sortedTransactions[j]) == 0 && isGrouped[j] == 0) {
                    printf(", \"%s\"", transactions[j]);
                    isGrouped[j] = 1;
                }
            }
            printf("]");
            if (i != numTransactions - 1) {
                printf(", ");
            }
        }
    }
    printf("\n");

    return 0;
}

