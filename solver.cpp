//===== SUDOKU GENERATOR CODE =================================================
#include "solver.h"

bool legal(int** puzzle, int n, int x, int y, int num) {
	int i, j, size = n * n;
    int rowStart = (int)(x/n) * n;
    int colStart = (int)(y/n) * n;
    for (i = 0; i < size; i++) {
        if (puzzle[x][i] == num) return false;
        if (puzzle[i][y] == num) return false;
        if (puzzle[rowStart + (i%n)][colStart + (int)(i/n)] == num)
			return false;
    }
    return true;
}

//===== CHECK UNIQUE SOLUTION ===============================================
int check(int** puzzle, int n, int x, int y, int count) {
	int i, num, size = n * n;
    if (x == size) {
        x = 0;
        if (++y == size) return (1 + count);
    }
    // Skip opened cell.
    if (puzzle[x][y] != 0)  return check(puzzle, n, x+1, y, count);
    // skip if the puzzle has more than one solution
    for (num = 1; (num <= size) && (count < 2); num++) {
        if (legal(puzzle, n, x, y, num)) {
            puzzle[x][y] = num;
            // Goto next.
            count = check(puzzle, n, x+1, y, count); 
        }
    }
    // Reset cell on go back.
    puzzle[x][y] = 0;
    return count;
}

//===== SOLVE SUDOKU ==========================================================
// Ref: http://codereview.stackexchange.com/questions/37430/sudoku-solver-in-c
// -- Fixed by: Nguyen Ba Anh
bool fillSudoku(int** puzzle, int n, int x, int y) {
	int i, size = n * n;
    if ((x < size) && (y < size)) {
        if (puzzle[x][y] != 0) {
            if ((y+1) < size) return fillSudoku(puzzle, n, x, y+1);
            else if((x+1) < size) return fillSudoku(puzzle, n, x+1, 0);
            else return true;
        } else {
            for (i = 0; i < size; i++) {
                if (legal(puzzle, n, x, y, i+1)) {
                    puzzle[x][y] = i+1;
                    if ((y+1) < size) { 
                        if (fillSudoku(puzzle, n, x, y+1)) return true;
                        else puzzle[x][y] = 0;
                    } else if ((x+1) < size) {
                        if (fillSudoku(puzzle, n, x+1, 0)) return true;
                        else puzzle[x][y] = 0;
                    } else return true;
                }
            }
        }
        return false;
    } else return true;
}
//================================= END =======================================
// June 03, 2015 - Nguyen Ba Anh
