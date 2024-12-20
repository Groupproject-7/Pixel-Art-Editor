#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void initializeGrid(char grid[ROWS][COLS]);
void displayGrid(char grid[ROWS][COLS]);
void drawPixel(char grid[ROWS][COLS], int row, int col, char color);
void erasePixel(char grid[ROWS][COLS], int row, int col);
void fillColor(char grid[ROWS][COLS], int row, int col, char oldColor, char newColor);
void handleUserInput(char grid[ROWS][COLS]);

int main() {
    char grid[ROWS][COLS];
    
    initializeGrid(grid);
    
    while (1) {
        displayGrid(grid);
        handleUserInput(grid);
    }
    
    return 0;
}

void initializeGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

void displayGrid(char grid[ROWS][COLS]) {
    printf("\nPixel Art Editor (10x10 Grid)\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("|%c", grid[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

void drawPixel(char grid[ROWS][COLS], int row, int col, char color) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        grid[row][col] = color;
    } else {
        printf("Invalid coordinates!\n");
    }
}

void erasePixel(char grid[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        grid[row][col] = ' ';
    } else {
        printf("Invalid coordinates!\n");
    }
}

void fillColor(char grid[ROWS][COLS], int row, int col, char oldColor, char newColor) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] != oldColor || oldColor == newColor) {
        return;
    }
    
    grid[row][col] = newColor;
    
    fillColor(grid, row + 1, col, oldColor, newColor);
    fillColor(grid, row - 1, col, oldColor, newColor);
    fillColor(grid, row, col + 1, oldColor, newColor);
    fillColor(grid, row, col - 1, oldColor, newColor);
}

void handleUserInput(char grid[ROWS][COLS]) {
    int choice;
    printf("Choose an action: \n");
    printf("1. Draw Pixel\n");
    printf("2. Erase Pixel\n");
    printf("3. Fill Color\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    
    int row, col;
    char color;

    while (1)
    {
        // check the choice the integer or other else
        if (scanf("%d", &choice) != 1)
        {
            // for clearing invalid input
            while (getchar() != '\n');
            printf("\nInvalid input!");

            printf("\n");
        }
        else if (choice == 1 || choice == 2||choice==3||choice==4)
        {
            break; 
        }
        else
        {
            printf("\n\nInvalid choice!");

        }

        printf("\nEnter your choice: ");
    }

    printf("\n");
    
    switch (choice) {
        case 1:
            printf("Enter row, column, and color (e.g., 2 3 @): ");
            scanf("%d %d %c", &row, &col, &color);
            drawPixel(grid, row, col, color);
            break;
        case 2:
            printf("Enter row and column to erase (e.g., 2 3): ");
            scanf("%d %d", &row, &col);
            erasePixel(grid, row, col);
            break;
        case 3:
            printf("Enter row, column, and new color to fill (e.g., 2 3 #): ");
            scanf("%d %d %c", &row, &col, &color);
            fillColor(grid, row, col, grid[row][col], color);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}
