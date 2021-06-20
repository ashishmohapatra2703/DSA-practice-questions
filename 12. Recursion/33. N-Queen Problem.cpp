/*The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard 
such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. 
Each solution contains distinct board configurations of the n-queens’ placement, 
where the solutions are a permutation of [1,2,3..n] in increasing order, here 
the number in the ith place denotes that the ith-column queen is placed in the row with that number. 

Input:		 { 0,  1,  0,  0}   &  { 0,  0,  1,  0}
4            { 0,  0,  0,  1}      { 1,  0,  0,  0}
             { 1,  0,  0,  0}      { 0,  0,  0,  1}
             { 0,  0,  1,  0}      { 0,  1,  0,  0}
Output:
[2 4 1 3 ] [3 1 4 2 ]  */

class Solution 
{
public:
    bool isSafeToPlaceTheQueen(int &n, vector<vector<bool>> &QueeninChessBoard, int &row, int &col)
    {
        for(int i=row-1,j=col-1; i>=0&j>=0; i--,j--)
        {
            if(QueeninChessBoard[i][j] == true)
                return false;
        }
        for(int i=row-1,j=col; i>=0; i--)
        {
            if(QueeninChessBoard[i][j] == true)
                return false;
        }
        for(int i=row-1,j=col+1; i>=0&j<n; i--,j++)
        {
            if(QueeninChessBoard[i][j] == true)
                return false;
        }
        return true;
    }

    void placeNQueens(vector<vector<bool>> &queensPosition, 
                        int row, int &n, 
                        vector<int> config, vector<vector<int>> &allConfigs)
    {
        if(row == n)
        {
            allConfigs.push_back(config);
            return;
        }
        
        for(int col=0; col<n; col++) //row->levels and column->options
        {
            if(isSafeToPlaceTheQueen(n, queensPosition, row, col) == true)
            {
                queensPosition[row][col] = true;
                
                config.push_back(col+1); //to print based on 1-based index
                placeNQueens(queensPosition, row+1, n, config, allConfigs);
                config.pop_back();
                
                queensPosition[row][col] = false;
            }
        }
    }

    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<bool>> queensPosition( n , vector<bool> (n, false));
        
        vector<vector<int>> allConfigs;
        vector<int> config; //empty
        
        placeNQueens(queensPosition, 0, n, config, allConfigs);
        
        return allConfigs;
    }
};