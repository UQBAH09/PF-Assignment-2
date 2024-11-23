#include <stdio.h>

int main(void) {
    int num[5];
    
    for (int i = 0; i < 5; i++) {
        printf("element - %d : ", i);
        scanf("%d", &num[i]);
    }
    
    int min = 9999, min2 = 9999;
    
    for (int i = 0; i < 5; i++) {
        if (num[i] < min) {
            min2 = min;
            min = num[i];
        } else if (num[i] < min2 && num[i] != min) {
            min2 = num[i];
        }
    }
    
    printf("The Second smallest element in the array is : %d\n", min2);
    return 0;
}

