# unique-solution-sudoku-generator
A console program written in C that give a sudoku puzzle which has only one solution.

Basic idea:
+ Give a sudoku width N (N=3 --> sudoku 9x9, N=4 --> sudoku 16x16).
+ Give a number of already opened cells M.
+ Based on {N,M} (regular: {3,27} --> 81 cells with 27 cells opened), the program will try to find a sudoku puzzle that has only one solution by looping, applied try-and-wrong method.
+ If a puzzle is found, it will save into a file.

Notes: 
+ this program uses some features in windows.h to color the texts and make some pause/delay actions, but the core algorithm is still OK for other platform.
+ this program has not been optimized. the program cannot give an answer if N > 4 (sudoku width larger than 16).
+ if N=3, M has to be larger than 25, or you will wait forever (the lower M will force the program hard to find a unique solution). The same for N=4, M>125

# SAMPLE RUN ON 9x9 SUDOKU
          UNIQUE SOLUTION SUDOKU GENERATOR
              NgBaAnh

---------- 1: INPUT ----------------------------------

Sudoku width N = 3
Number of opened cells M = 27

---------- 2: RANDOM A SUDOKU TABLE ------------------

Full Sudoku table[9][9]:
3 6 4  5 1 9  2 7 8
1 7 8  2 3 4  6 5 9
2 5 9  8 7 6  3 4 1

9 3 2  4 6 8  7 1 5
5 1 6  9 2 7  8 3 4
8 4 7  3 5 1  9 2 6

7 8 1  6 4 2  5 9 3
6 2 3  1 9 5  4 8 7
4 9 5  7 8 3  1 6 2


---------- 3: FIND UNIQUE SOLUTION -------------------

Finding unique solution puzzle (tried 9269 times)...
Result: puzzle[9][9]:
- - -  - 1 -  2 7 -
- - 8  - - -  6 5 9
- - 9  8 - -  - - 1

9 - -  4 - -  - - -
- 1 6  9 - -  8 - -
- - -  - 5 -  - 2 -

- 8 -  - - -  - - -
6 2 -  1 9 5  4 - -
- - -  - - 3  1 - -


---------- 4: SOLVE THE SUDOKU -----------------------

Solving......Done!
Puzzle[9][9]:
3 6 4  5 1 9  2 7 8
1 7 8  2 3 4  6 5 9
2 5 9  8 7 6  3 4 1

9 3 2  4 6 8  7 1 5
5 1 6  9 2 7  8 3 4
8 4 7  3 5 1  9 2 6

7 8 1  6 4 2  5 9 3
6 2 3  1 9 5  4 8 7
4 9 5  7 8 3  1 6 2


---------- 5: WRITE TO FILES -------------------------

Puzzle   : output/TI2QD1T43Y.txt
Solution : output/TI2QD1T43Y_solved.txt

Fnished. Again? (y/n)

--------------------------------
Process exited after 77.55 seconds with return value 0
Press any key to continue . . .

# SAMPLE RUN ON 16x16 SUDOKU
          UNIQUE SOLUTION SUDOKU GENERATOR
              NgBaAnh

---------- 1: INPUT ----------------------------------

Sudoku width N = 4
Number of opened cells M = 130

---------- 2: RANDOM A SUDOKU TABLE ------------------

Full Sudoku table[16][16]:
03 07 06 08  05 14 10 09  13 02 01 15  11 12 16 04
13 16 15 10  12 11 01 02  07 09 14 04  08 06 05 03
12 04 14 09  13 03 06 16  08 10 05 11  01 15 02 07
11 05 01 02  08 15 07 04  06 03 16 12  13 10 14 09

10 13 05 03  15 06 11 07  02 16 09 08  14 01 04 12
01 08 09 11  03 05 02 14  04 06 12 13  07 16 15 10
14 12 16 07  04 08 09 10  03 01 15 05  02 11 13 06
04 06 02 15  01 13 16 12  10 14 11 07  09 05 03 08

16 15 07 04  09 12 08 01  05 13 06 03  10 02 11 14
09 01 08 06  16 10 05 03  11 12 02 14  04 13 07 15
05 03 12 13  11 02 14 15  09 07 04 10  16 08 06 01
02 10 11 14  06 07 04 13  16 15 08 01  03 09 12 05

06 14 13 12  02 01 03 08  15 11 07 09  05 04 10 16
15 02 04 01  10 09 13 06  14 05 03 16  12 07 08 11
08 09 03 05  07 16 15 11  12 04 10 02  06 14 01 13
07 11 10 16  14 04 12 05  01 08 13 06  15 03 09 02


---------- 3: FIND UNIQUE SOLUTION -------------------

Finding unique solution puzzle (tried 3 times)...
Result: puzzle[16][16]:
-- -- 06 --  -- 14 10 --  13 02 -- 15  -- -- -- 04
-- 16 15 --  12 -- -- 02  07 09 -- 04  -- -- 05 03
12 -- 14 --  13 03 06 --  -- -- 05 --  01 -- -- --
-- -- 01 02  08 15 07 04  06 -- 16 12  -- -- -- 09

10 -- 05 --  15 06 11 --  -- 16 09 08  -- -- 04 --
-- 08 -- 11  03 -- -- --  -- -- -- 13  07 16 15 --
-- 12 -- 07  -- 08 -- 10  -- 01 15 --  02 11 -- --
-- -- 02 15  -- -- 16 --  10 -- 11 07  09 -- 03 08

-- 15 -- 04  -- 12 -- --  05 13 06 --  10 02 -- --
09 01 08 --  -- -- 05 --  -- 12 02 14  04 -- 07 15
-- 03 12 --  11 02 -- 15  09 -- -- 10  16 -- 06 01
-- -- 11 14  -- -- -- 13  -- 15 -- 01  03 -- 12 05

-- -- -- --  02 01 -- 08  15 11 -- --  05 04 10 --
-- 02 -- --  -- -- 13 06  14 05 03 16  -- 07 08 --
-- 09 03 --  -- -- -- 11  -- -- 10 --  -- 14 -- 13
-- -- 10 16  14 -- -- 05  -- -- 13 --  -- -- -- --


---------- 4: SOLVE THE SUDOKU -----------------------

Solving......Done!
Puzzle[16][16]:
03 07 06 08  05 14 10 09  13 02 01 15  11 12 16 04
13 16 15 10  12 11 01 02  07 09 14 04  08 06 05 03
12 04 14 09  13 03 06 16  08 10 05 11  01 15 02 07
11 05 01 02  08 15 07 04  06 03 16 12  13 10 14 09

10 13 05 03  15 06 11 07  02 16 09 08  14 01 04 12
01 08 09 11  03 05 02 14  04 06 12 13  07 16 15 10
14 12 16 07  04 08 09 10  03 01 15 05  02 11 13 06
04 06 02 15  01 13 16 12  10 14 11 07  09 05 03 08

16 15 07 04  09 12 08 01  05 13 06 03  10 02 11 14
09 01 08 06  16 10 05 03  11 12 02 14  04 13 07 15
05 03 12 13  11 02 14 15  09 07 04 10  16 08 06 01
02 10 11 14  06 07 04 13  16 15 08 01  03 09 12 05

06 14 13 12  02 01 03 08  15 11 07 09  05 04 10 16
15 02 04 01  10 09 13 06  14 05 03 16  12 07 08 11
08 09 03 05  07 16 15 11  12 04 10 02  06 14 01 13
07 11 10 16  14 04 12 05  01 08 13 06  15 03 09 02


---------- 5: WRITE TO FILES -------------------------

Puzzle   : output/429CI0TBTV.txt
Solution : output/429CI0TBTV_solved.txt

Fnished. Again? (y/n)

--------------------------------
Process exited after 18.67 seconds with return value 0
Press any key to continue . . .