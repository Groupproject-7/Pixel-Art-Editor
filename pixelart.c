#include <stdio.h>
#include <stdlib.h>

// Constants for grid dimensions
#define ROWS 10
#define COLS 10

// Function prototypes
void initializeGrid(char grid[ROWS][COLS]);
void displayGrid(char grid[ROWS][COLS]);
void drawPixel(char grid[ROWS][COLS], int row, int col, char color);
void erasePixel(char grid[ROWS][COLS], int row, int col);
void fillColor(char grid[ROWS][COLS], int row, int col, char oldColor, char newColor);
void handleUserInput(char grid[ROWS][COLS]);

// Main function
int main() {
    char grid[ROWS][COLS];

    // Initialize the grid
    initializeGrid(grid);

    // Main program loop
    while (1) {
        displayGrid(grid);
        handleUserInput(grid);
    }

    return 0;
}

// Initialize the grid with blank spaces
void initializeGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

// Display the current state of the grid
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

// Draw a pixel at the specified coordinates
void drawPixel(char grid[ROWS][COLS], int row, int col, char color) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        grid[row][col] = color;
    } else {
        printf("Invalid coordinates!\n");
    }
}

// Erase a pixel by setting it to blank

void handleUserInput(char grid[ROWS][COLS]) {
    int choice;
    printf("Choose an action: \n");
    printf("1. Draw Pixel\n");
    printf("2. Erase Pixel\n");
    printf("3. Fill Color\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int row, col;
    char color;

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
