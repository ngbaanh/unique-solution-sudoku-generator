//===== SUDOKU GENERATOR HEADER ===============================================
#ifndef generator_h
#define generator_h
struct sudoku {
	int number; // Cell Value.
	int mask; // Cell Visible Mask: 1-Show, 0-Hide.
};

int sudoku(struct sudoku**,int,int,int);
void hideNumbers(struct sudoku**,int,int);
void printResult(struct sudoku**,int);
void showFull(struct sudoku**,int);
#endif
//===== END HEADER ============================================================
