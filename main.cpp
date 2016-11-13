#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#include "generator.h"
#include "solver.h"

char* randString(int); 
void writeFile(struct sudoku**,int,int);
void setTextColor(int);

int main() {
	setTextColor(15); // WHITE
	printf("          UNIQUE SOLUTION SUDOKU GENERATOR   \n");
	printf("              NgBaAnh                        \n");
	
	while(true) {
	    srand(time(NULL));
	    printf("\n---------- 1: INPUT ----------------------------------\n\n");
	    int i, j, n, m;
	    struct sudoku** table;
	    // 1.3. Get n, m
	    printf("Sudoku width N = "); setTextColor(10); // GREEN
	    do scanf("%d", &n); 
	    while (n < 2 || n > 4);
	    int size = n * n;
	    setTextColor(15); // WHITE 
	    printf("Number of opened cells M = "); setTextColor(10); // GREEN
	    do scanf("%d", &m);
	    while (m < 0 || m > n*n*n*n); 
      
      table = (struct sudoku**)malloc(size * sizeof(struct sudoku*));
      for(i = 0; i < size; i++)
        table[i] = (struct sudoku*)malloc(size * sizeof(struct sudoku));

      setTextColor(15); // WHITE 
      printf("\n---------- 2: RANDOM A SUDOKU TABLE ------------------\n\n");
      printf("Full Sudoku table[%d][%d]: \n", size, size);
	    sudoku(table, n, 0, 0);
	    setTextColor(14); // YELLOW
	    showFull(table, n);
      
      
	    setTextColor(15); // WHITE
	    printf("\n---------- 3: FIND UNIQUE SOLUTION -------------------\n\n");
	    Sleep(20);
      int** puzzle;
      puzzle = (int**)malloc(size * sizeof(int*));
      for(i = 0; i < size; i++) puzzle[i] = (int*)malloc(size * sizeof(int));
      long tried = 0;
      do {
        hideNumbers(table,n,m);
        for(i = 0; i < size; i++)
          for(j = 0; j < size; j++) {
            if(table[i][j].mask == 1) puzzle[i][j]=table[i][j].number;
            else puzzle[i][j] = 0; // Mask=0 thi gan gia tri puzzle=0
          }
        // printf("\n"); printResult(table, n); system("cls");
        printf("\rFinding unique solution puzzle (tried %ld times)...", ++tried);
      } while (check(puzzle, n, 0, 0, 0) != 1);
      printf("\nResult: puzzle[%d][%d]:\n", size, size);
      setTextColor(13); // YELLOW
      printResult(table, n);
      
      
      setTextColor(15); // WHITE
      printf("\n---------- 4: SOLVE THE SUDOKU -----------------------\n\n");
      printf("Solving......");
      if(fillSudoku(puzzle, n, 0, 0)) {
        printf("Done!\nPuzzle[%d][%d]: \n", size, size);
        setTextColor(12); // RED
        char format[5]; 
          for(i = 0; i < size; ++i) {
              for(j = 0; j < size; ++j) {
                if(size > 10 && puzzle[i][j] < 10) strcpy(format, "0%d ");
                else strcpy(format, "%d ");
                printf(format, puzzle[i][j]);
                if((j+1)%n == 0) printf(" ");
                Sleep(10);
              }
              if((i+1)%n == 0) printf("\n");
              printf("\n");
          }
        setTextColor(15); // WHITE
      } else {
        printf("No solution > Exit.");
        return 0;
      }
		
      printf("\n---------- 5: WRITE TO FILES -------------------------\n\n");
      writeFile(table, n, m);
      
      // Release pointers
      for(i = 0; i < size; i++) { free(table[i]); free(puzzle[i]); }
      free(table); free(puzzle);
		
		// 5.3. Kiem tra dieu kien tiep tuc
	    printf("\nFnished. Again? (y/n)\n");
	    char ch = getch();
	    if(ch!='n') system("cls");
	    else break;
	}
	return 0;
}


void writeFile(struct sudoku** table, int n, int m) {
	int i, j, size = n * n;
	FILE *f, *f2;
	char path[30] = "output/"; // output folder "./output/"
	strcat(path, randString(10));
	strcat(path, (char*)".txt"); // append ".txt"
	char path2[30];
	strncpy(path2, path, 17);
	path2[17] = '\0';
	strcat(path2, (char*)"_solved.txt");
	f = fopen(path, "w+");
	f2 = fopen(path2, "w+");
	if(f != NULL && f2 != NULL) {
		fprintf(f, "%2d %2d\n", n, m);
		for(i = 0; i < size; i++) {
			for(j = 0; j < size; j++) {
				if(table[i][j].mask == 0) fprintf(f, "%2d ", 0);
				else fprintf(f, "%2d ", table[i][j].number);
				fprintf(f2, "%2d ", table[i][j].number);
			}
			fputs("\n", f);
			fputs("\n", f2);
		}	
	} else printf("Error!");
	fclose(f);
	fclose(f2);
	printf("Puzzle   : ");
	setTextColor(10); // GREEN
	puts(path); setTextColor(15); // WHITE
	printf("Solution : ");
	setTextColor(10); // GREEN
	puts(path2); setTextColor(15); // WHITE
}

char* randString(int length) {
    char charset[37] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";        
    char* randomString = NULL;
    if(length > 0) {
        randomString = (char*) malloc(sizeof(char) * (length+1));
        if(randomString) { 
            for(int n = 0; n < length; n++) {            
                int key = rand() % 36;
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
        }
    }
    return randomString;
}

void setTextColor(int color) {
   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hCon,color);
}
//================================= END =======================================
// June 03, 2015 - Nguyen Ba Anh
