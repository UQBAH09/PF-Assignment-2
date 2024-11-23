#include <stdio.h>
#include <string.h>
#include <math.h>

// Convert binary to decimal
int BinaryToDecimal(int num) {
    int deci = 0;
    for (int i = 0; num > 0; i++) {
        deci += (num % 10) * pow(2, i);
        num /= 10;
    }
    return deci;
}

// Convert decimal to binary
int DecimalToBinary(int num) {
    int binary = 0;
    for (int i = 0; num > 0; i++) {
        binary += (num % 2) * pow(10, i);
        num /= 2;
    }
    return binary;
}

// Convert decimal to hexadecimal
void DecimalToHexadecimal(int num) {
    int hex[50], count = 0;
    
    for (int i = 0; num > 0; i++) {
        hex[i] = num % 16;
        num /= 16;
        count++;
    }

    // Print hexadecimal in reverse order
    for (int i = count - 1; i >= 0; i--) {
        if (hex[i] < 10) {
            printf("%d", hex[i]);
        } else {
            printf("%c", 'A' + (hex[i] - 10));
        }
    }
}

// Convert character to number (for hexadecimal)
int charToNum(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'F') return 10 + (ch - 'A');
    return -1; // Invalid character
}

// Convert hexadecimal string to decimal
void HexadecimalToDecimal(char hexNum[]) {
    int deci = 0;

    for (int i = strlen(hexNum) - 1; i >= 0; i--) {
        int value = charToNum(hexNum[i]);
        if (value == -1) {
            printf("Invalid hexadecimal number.\n");
            return;
        }
        deci += value * pow(16, strlen(hexNum) - 1 - i);
    }
    printf("%d\n", deci);
}

// Convert binary to hexadecimal
void BinaryToHexadecimal(int num) {
    int decimal = BinaryToDecimal(num);
    DecimalToHexadecimal(decimal);
}

// Convert hexadecimal string to binary
void HexadecimalToBinary(char hexNum[]) {
    int deci = 0;

    for (int i = strlen(hexNum) - 1; i >= 0; i--) {
        int value = charToNum(hexNum[i]);
        if (value == -1) {
            printf("Invalid hexadecimal number.\n");
            return;
        }
        deci += value * pow(16, strlen(hexNum) - 1 - i);
    }
    printf("%d\n", DecimalToBinary(deci));
}

// Main function to execute conversion options
int main(void) {
    int choice;
    printf("Select an option:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            int num;
            printf("Enter binary number: ");
            scanf("%d", &num);
            printf("The decimal value of %d is %d.\n", num, BinaryToDecimal(num));
            break;
        }
        case 2: {
            int num;
            printf("Enter decimal number: ");
            scanf("%d", &num);
            printf("The binary value of %d is %d.\n", num, DecimalToBinary(num));
            break;
        }
        case 3: {
            int num;
            printf("Enter decimal number: ");
            scanf("%d", &num);
            printf("The hexadecimal value of %d is ", num);
            DecimalToHexadecimal(num);
            printf("\n");
            break;
        }
        case 4: {
            char hexnum[50];
            printf("Enter hexadecimal number: ");
            getchar(); // Clear newline character from buffer
            fgets(hexnum, sizeof(hexnum), stdin);
            hexnum[strcspn(hexnum, "\n")] = '\0'; // Remove newline character
            printf("The decimal value of %s is ", hexnum);
            HexadecimalToDecimal(hexnum);
            break;
        }
        case 5: {
            int num;
            printf("Enter binary number: ");
            scanf("%d", &num);
            printf("The hexadecimal value of %d is ", num);
            BinaryToHexadecimal(num);
            printf("\n");
            break;
        }
        case 6: {
            char hexnum[50];
            printf("Enter hexadecimal number: ");
            getchar(); // Clear newline character from buffer
            fgets(hexnum, sizeof(hexnum), stdin);
            hexnum[strcspn(hexnum, "\n")] = '\0'; // Remove newline character
            printf("The binary value of %s is ", hexnum);
            HexadecimalToBinary(hexnum);
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }
}

