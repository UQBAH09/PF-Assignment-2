#include <stdio.h>

// Function to determine the optimal number of matchsticks to pick
int matchsticks(int totalMatchsticks) {
    if (totalMatchsticks % 5 != 0) {
        return totalMatchsticks % 5;
    }
    return -1;
}

int main(void) {
    int totalMatchsticks;
    printf("Enter number of matchsticks: ");
    scanf("%d", &totalMatchsticks);
    
    printf("%d\n", matchsticks(totalMatchsticks));
    
    return 0;
}

