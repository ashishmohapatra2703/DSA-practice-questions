/*Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), 
the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

Your Task:
You need to complete the two functions:
SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not.
printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation.

Time Complexity: O(9^(N²)) */

class Solution {
public:
    bool checkPresenceInRow(int &row, int &option, int grid[N][N])
    {
        for(int j=0; j<N; j++)
        {
            if(grid[row][j] == option)
                return false;
        }
        return true;
    }
    bool checkPresenceInCol(int &col, int &option, int grid[N][N])
    {
        for(int i=0; i<N; i++)
        {
            if(grid[i][col] == option)
                return false;
        }
        return true;
    }
    bool checkPresenceInSubMatrix(int &row, int &col, int &option, int grid[N][N])
    {
        int subMatRowStart;
        int subMatRowEnd;
        int subMatColStart;
        int subMatColEnd;
        for(int i=0; i<N; i+=3) //i ~ 0,3,6
        {
            if(row>=i && row<=i+2)
            {
                subMatRowStart = i; //[subMatRowStart, subMatRowEnd] ~ [0,2] or [3,5] or [6,8]
                subMatRowEnd = i+2;
                break;
            }
        }
        for(int j=0; j<N; j+=3) //j ~ 0,3,6
        {
            if(col>=j && col<=j+2)
            {
                subMatColStart = j; //[subMatColStart, subMatColEnd] ~ [0,2] or [3,5] or [6,8]
                subMatColEnd = j+2;
                break;
            }
        }
        
        for(int i=subMatRowStart; i<=subMatRowEnd; i++)
        {
            for(int j=subMatColStart; j<=subMatColEnd; j++)
            {
                if(grid[i][j] == option)
                    return false;
            }
        }
        return true;
    }
    bool isValidToPlace(int &row, int &col, int &option, int grid[N][N])
    {
        if(checkPresenceInRow(row, option, grid) &&
           checkPresenceInCol(col, option, grid) &&
           checkPresenceInSubMatrix(row, col, option, grid))
           return true;
          
        return false;
    }
    void changeIndicesToNewPosition(int &row, int &col)
    {
        if(col <= 7) //not at the right-most edge
        {
            row = row;
            col = col+1;
        }
        else if(col == 8)
        {
            row = row+1;
            col = 0;
        }
    }
    void changeIndicesBackToPreviousPosition(int &row, int &col)
    {
        if(col == 0)
        {
            row = row-1;
            col = 8;
        }
        else if(col >= 1)
        {
            row = row;
            col = col-1;
        }
    }
    bool sodokuSolver(int &row, int &col, int grid[N][N])
    {
        if(row==N)
            return true;
        
        
        if(grid[row][col] != 0)
        {
            changeIndicesToNewPosition(row, col);
            if(sodokuSolver(row, col, grid))    return true;
            changeIndicesBackToPreviousPosition(row, col);
        }
        else if(grid[row][col] == 0)
        {
            for(int option=1; option<=9; option++)
            {
                if(isValidToPlace(row, col, option, grid) == true)
                {
                    grid[row][col] = option; //making tentative assignment 
                    changeIndicesToNewPosition(row, col);
                    if(sodokuSolver(row, col, grid))    return true; //if success, return true  
                    changeIndicesBackToPreviousPosition(row, col);
                    grid[row][col] = 0;    //failure, undo & try again
                }
            }
        }
        return false;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    {
        int r = 0;
        int c = 0;
        return sodokuSolver(r, c, grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};