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