//===== SUDOKU GENERATOR CODE =================================================
#include "generator.h"
#include <stdio.h>
#include <windows.h>

//== Main generating function ===================================
// Input:
// -- table[][]: Sudoku data array.
// -- n: sudoku width, n is often equals 3.
// -- x, y: row and col indexes.
// Output:
// -- table[][]: Sudoku data array.
// -- logic: true / false (for recursion)
bool sudoku(struct sudoku** table, int n, int x, int y) {
	// 1. Delcare some vars
	int i, j; // loop indexes.
	int size = n*n; // sudoku width.
	
	// 2. Mask Array
	int* maskArray = (int*)malloc(size*sizeof(int*));
	// Mark 1 as the POSIBLE value.
	for (i = 0; i < size; i++) maskArray[i] = 1;
    
	// 3. Find and mark 0 as IMPOSIBLE values.
    for (i = 0; i < y; i++) maskArray[table[x][i].number - 1] = 0;
    for (i = 0; i < x; i++) maskArray[table[i][y].number - 1] = 0;
    for (i = (n * (int)(x/n)); i < (n * (int)(x/n) + n); i++)
        for (j = (n * (int)(y/n)); j < y; j++)
            maskArray[table[i][j].number - 1] = 0;
    
	// 4. Group all possible values into a new array
    // 4.1. Declare and allocate a new array
    int k = 0;
    for (i = 0; i < size; i++) k += maskArray[i]; // ount
    int* randArray;
    randArray = (int*)malloc(k * sizeof(int*));
    // 4.2. Assign those values into this array.
    j = 0; // reset j for a new loop
    for (i = 0; i < size; i++) {
        if (maskArray[i] == 1) { // Neu the position i is a possible value
            randArray[j] = i + 1; // Do assign
            j++; // go to the next position
        } else continue;
    }
    
	// 5. Compute the next cell position.
    int newX, newY;
    if (x == size-1) {
        newY = y + 1;
        newX = 0;
    } else {
        newY = y;
        newX = x + 1;
    }	
	
	// 6. Take random possible values into current cell.
    while (k > 0) { // And try all of them.
        int index = rand() % k; 
        table[x][y].number = randArray[index];
        for (i = index; i < (k-1); i++) randArray[i] = randArray[i+1];
        k--;
		
		// Stop if at the last cell.
		if ((x == size-1) && (y == size-1)) {
        free(randArray); free(maskArray);
        return true; 
    }
        
    // Or go to the next cell
    if (sudoku(table, n, newX, newY)) {
       free(randArray); free(maskArray);
       return true;
    }
    }
    
	// 7. Release memory.
    free(randArray); free(maskArray);
    return false;
}

//===== PRINT THE RESULT ======================================================
void printResult(struct sudoku** table, int n) {
	int i, j, size = n * n;
    char format[5], format2[5]; // formatters
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
        	if (size > 10) { // if cell number has 2 digits
        		strcpy(format2, "-- ");
        		// add 0 if the number < 10
        		if (table[i][j].number < 10) strcpy(format, "0%d ");
        		else strcpy(format, "%d ");
			} else { // if the number has only 1 digit
				strcpy(format, "%d ");
				strcpy(format2, "- ");
			}
	        if (table[i][j].mask == 0) printf(format2); // mask=0
	        else printf(format, table[i][j].number); // mask=1
	        if ((j+1)%n == 0) printf(" "); // Print blanks among block columns
	        Sleep(10); // 10 milisecond.
        }
        if ((i+1)%n == 0) printf("\n"); // Print blanks among block rows
        printf("\n"); // Next line.
    }
}

//===== PRINT FULL SOLVED SUDOKU PUZZLE =======================================
void showFull(struct sudoku** table, int n) {
	int size = n * n;
    int i, j;
    char format[5];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
        	if (size > 10 && table[i][j].number < 10) strcpy(format, "0%d ");
        	else strcpy(format, "%d ");
	        printf(format, table[i][j].number);
	        if ((j+1)%n == 0) printf(" ");
	        Sleep(10);
        }
        if ((i+1) % n == 0) printf("\n");
        printf("\n");
    }
}

//===== CHANGE MASKS OF SUDUKU STRUCT ========================================
// Input:
// -- table[][]: sudoku puzzle
// -- n: width
// -- m: number of opened cells.
void hideNumbers(struct sudoku **table, int n, int m) {
    int i, j, x, y, size = n * n;
    // 1. Set mask=0 for all cells.
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
        	table[i][j].mask = 0;
        }
    }
    // 2. Randomly change open m cells.
    for (i = 0; i < m; i++) {
    	do {
    		x = rand() % size;
    		y = rand() % size;
    	} while (table[x][y].mask == 1); // if this cell was changed before.
    	table[x][y].mask = 1; // Set mask=1 for cell(x,y)
    }
}
//================================= END =======================================
// June 03, 2015 - Nguyen Ba Anh
