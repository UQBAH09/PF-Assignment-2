#include <stdio.h>
#include <string.h>


// Move player left functions
void left(char map[5][5], int p[2]) {
    if (p[1] > 0) {
        if (map[p[0]][p[1] - 1] == 'X') {
            printf("Invalid move. Bumped into a wall.\n");
        } else {
            if (map[p[0]][p[1] - 1] == 'I') {
                printf("You collected an item!\n");
            }
            map[p[0]][p[1]] = ' ';
            map[p[0]][p[1] - 1] = 'P';
            p[1]--;
        }
    } else {
        printf("Invalid move. Hit the wall.\n");
    }
}

// Move player right functions
void right(char map[5][5], int p[2]) {
    if (p[1] < 4) {
        if (map[p[0]][p[1] + 1] == 'X') {
            printf("Invalid move. Bumped into a wall.\n");
        } else {
            if (map[p[0]][p[1] + 1] == 'I') {
                printf("You collected an item!\n");
            }
            map[p[0]][p[1]] = ' ';
            map[p[0]][p[1] + 1] = 'P';
            p[1]++;
        }
    } else {
        printf("Invalid move. Hit the wall.\n");
    }
}

// Move player up functions
void up(char map[5][5], int p[2]) {
    if (p[0] > 0) {
        if (map[p[0] - 1][p[1]] == 'X') {
            printf("Invalid move. Bumped into a wall.\n");
        } else {
            if (map[p[0] - 1][p[1]] == 'I') {
                printf("You collected an item!\n");
            }
            map[p[0]][p[1]] = ' ';
            map[p[0] - 1][p[1]] = 'P';
            p[0]--;
        }
    } else {
        printf("Invalid move. Hit the wall.\n");
    }
}

// Move player down functions
void down(char map[5][5], int p[2]) {
    if (p[0] < 4) {
        if (map[p[0] + 1][p[1]] == 'X') {
            printf("Invalid move. Bumped into a wall.\n");
        } else {
            if (map[p[0] + 1][p[1]] == 'I') {
                printf("You collected an item!\n");
            }
            map[p[0]][p[1]] = ' ';
            map[p[0] + 1][p[1]] = 'P';
            p[0]++;
        }
    } else {
        printf("Invalid move. Hit the wall.\n");
    }
}

// Display the current state of the map
void displayMap(char map[5][5]) {
    printf("\nCurrent Map:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf(" %c ", map[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char map[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int p[2] = {4, 4};
    char mov = ' ';

    displayMap(map);

    // Main game loop
    while (mov != 'Q') {
        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &mov);

        // Handle movement based on user input
        switch (mov) {
            case 'A':
                left(map, p);
                break;
            case 'D':
                right(map, p);
                break;
            case 'S':
                down(map, p);
                break;
            case 'W':
                up(map, p);
                break;
            case 'Q':
                printf("Quitting the game. Goodbye!\n");
                break;
            default:
                printf("Invalid move. Please use W, A, S, D, or Q.\n");
                continue; // Skip to the next iteration if invalid input
        }

        displayMap(map); // Show updated map after movement
    }

    return 0;
}

