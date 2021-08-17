/*Input:
N = 2
Output:
5
Explanation:
A 2*2 chessboard has 5 squares.
4 1*1 squares and a 2*2 square. */

class Solution {
  public:
    long long squaresInChessBoard(long long N) 
    {
        if(N == 1)
            return 1;
            
        return N*N + squaresInChessBoard(N-1);
    }
};

//Similar Question
//Given a mxn matrix, count the number of squares in the matrix.
/*Input:
m = 4, n = 3
Output:
20
Explanation:
There are a total of 20 squares in a 4*3 matrix.
12 1*1 squares , 6 2*2 square and 2 3*3 square  */

class Solution {
  public:
    long long squaresInMatrix(int m, int n) 
    {
        if(m==0 or n==0)
            return 0;
        
        return m*n + squaresInMatrix(m - 1,n - 1);
    }
};