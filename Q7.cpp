#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a 6x5 puzzle filled with random characters
void generatePuzzle(char puzzle[5][5]) {
    srand(time(0));
    char studentID[] = "0614";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            puzzle[i][j] = 'A' + (rand() % 26);
        }
    }

	for (int i = 0; i < 4; i++) {
        puzzle[4][i] = studentID[i];
    }
    puzzle[4][4] = 'A' + (rand() % 26);
}

// Function to display the puzzle
void displayPuzzle(char puzzle[5][5]) {
    printf("Generated Puzzle:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// Function to search for a word horizontally (left to right)
int searchLR(int coordinates[], char word[], char puzzle[5][5]) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (coordinates[1] + i >= 5 || puzzle[coordinates[0]][coordinates[1] + i] != word[i]) {
            return -1; 
        }
    }
    return 1;
}

// Function to search for a word vertically (top to down)
int searchUD(int coordinates[], char word[], char puzzle[5][5]) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (coordinates[0] + i >= 5 || puzzle[coordinates[0] + i][coordinates[1]] != word[i]) {
            return -1; 
        }
    }
    return 1;
}

// Function to find a word in the puzzle and update the score
void found(char word[], char puzzle[5][5], int *score) {
    int found = 0;
    
    // If the word length exceeds the puzzle's dimensions
    if (strlen(word) > 5) {
        (*score)--;
        printf("%s is not present. Score %d\n", word, *score);
        return;
    }
    
    // Search for the word in the puzzle
    for (int i = 0; i < 5 && !found; i++) {
        for (int j = 0; j < 5 && !found; j++) {
            if (puzzle[i][j] == word[0]) {
                int coordinates[] = {i, j};

                // Check for horizontal and vertical matches
                if (searchLR(coordinates, word, puzzle) == 1 || searchUD(coordinates, word, puzzle) == 1) {
                    (*score)++;
                    printf("%s is present. Score %d\n", word, *score);
                    found = 1;
                }
            }
        }
    }

    if (!found) {
        (*score)--;
        printf("%s is not present. Score %d\n", word, *score);
    }
}

int main(void) {
    char puzzle[5][5];
    
    generatePuzzle(puzzle);
    displayPuzzle(puzzle);
    
    char word[50];
    int score = 0;
    
    while (1) {
        printf("Search str: ");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0';
        
        if (strcmp(word, "END") == 0) {
            break;
        }

        found(word, puzzle, &score);
    }
    
    printf("\nFinal Score: %d\n", score);
    return 0;
}

