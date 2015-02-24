#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    state = INIT;
    grid = new char*[height];
    visible = new char*[height];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        visible[i] = new char[width];
    }
    char letter = 'A';
    // Guarantee pairs of characters in the grid
    for (int i = 0; i < height; i++) {
		int pos0, pos1;
		pos0 = 0;
		pos1 = 0;
        for (int j = 0; j < width; j++) {
            grid[i][j] = letter;           
            visible[i][j] = '_';
			pos1++;
            if (pos0 + pos1 > 1) {
                letter++;
				pos1 = 0;
                if (letter > 'Z') {
                    letter = 'A';
                }
            }
        }
    }
    // Seed random number generator with time
    srand(time(0));
    // Randomize
   
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            swap(grid[i][j], grid[rand() % height][rand() % width]);
        }
    }
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
    return true;
}
bool Model::matched(int row, int column) {
    return true;
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
    // If the row and column are not valid, break out and don't do anything
    if (!valid(row, column)) { return; }
	
	int initR, initC, secR, secC;
    visible[row][column] = grid[row][column];
	switch (state) {
		case INIT:				
			state = FIRST;
			break;
		case FIRST:
			
			initR = lastRow.back();
			initC = lastColumn.back();
			visible[initR][initC] = grid[initR][initC];
			
			if (visible[initR][initC] == visible[row][column]){
				
				state = INIT;
				break;
			}
			else{
				state = NO_MATCH;
			}
			break;
		case NO_MATCH:
		
			secR = lastRow.back();
			secC = lastColumn.back();
			lastRow.pop_back();
			lastColumn.pop_back();
			initR = lastRow.back();
			initC = lastColumn.back();
			lastRow.pop_back();
			lastColumn.pop_back();			
			visible[initR][initC] = '_';
			visible[secR][secC] = '_';
			state = FIRST;
			break;
	}
	
	lastRow.push_back(row);
	lastColumn.push_back(column);
}
// If everything is visible, then it's game over
bool Model::gameOver() {
    // Assume the game is over
    bool isOver = true;
    // Loop through the grid and see if any element is not visible
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (visible[i][j] == '_') {
                isOver = false;
            }
        }
    }
    
    if (isOver) {
        // Set a nice game over message
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                visible[i][j] = '_';
            }
        }
        visible[2][3] = 'Y';
        visible[2][4] = 'O';
        visible[2][5] = 'U';
        visible[4][3] = 'W';
        visible[4][4] = 'I';
        visible[4][5] = 'N';
    }
    return isOver;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
