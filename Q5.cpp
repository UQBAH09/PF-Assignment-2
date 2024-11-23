#include <stdio.h>

int main(void) {
    int numElements;
    printf("Enter number of elements in the array: ");
    scanf("%d", &numElements);
    
    int values[numElements]; // Array to hold the input values
    for (int i = 0; i < numElements; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &values[i]);
    }
    
    // Horizontal Histogram
    printf("\nHorizontal Histogram");
    for (int i = 0; i < numElements; i++) {
        printf("\nValue %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
    }

    // Vertical Histogram
    printf("\n\nVertical Histogram\n");
    int maxValue = 0;
    
    // Find the maximum value in the array
    for (int i = 0; i < numElements; i++) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }

    // Print the vertical histogram
    for (int i = 0; i < maxValue; i++) {
        for (int j = 0; j < numElements; j++) {
            if ((maxValue - i) <= values[j]) {
                printf("* "); // Print asterisk if value is present
            } else {
                printf("  "); // Print space if no value
            }
        }
        printf("\n");
    }

    // Print the values at the bottom
    for (int i = 0; i < numElements; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}

