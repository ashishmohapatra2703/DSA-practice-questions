/*Given a 2D matrix matrix, handle multiple queries of the following type:
Calculate the sum of the elements of matrix inside the rectangle defined by 
its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:
NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix 
inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[ [[[3, 0, 1, 4, 2], 
    [5, 6, 3, 2, 1], 
    [1, 2, 0, 1, 5], 
    [4, 1, 0, 1, 7], 
    [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4] ]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 
numMatrix.sumRegion(1, 1, 2, 2); // return 11 
numMatrix.sumRegion(1, 2, 2, 4); // return 12 */


/* Time Complexity : Precomputation = O(M*N), where M=rows and N=columns in the given matrix.
   Space Complexity : O(M*N), to maintain the prefixSumDP matrix.
   Query : O(1), since we are directly calculating sum from precomputed stored result.   */
class NumMatrix {
public:
    vector<vector<int>> pSum; 
    //prefixSumDP[i][j] = sum of elements in submatrix (0,0) to (i-1, j-1) 
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        pSum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        //add an extra row and column in order to prevent 
        //out-of-bounds issues at i-1 and j-1 (similar to a prefix sum array)
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                pSum[i][j] = matrix[i-1][j-1] + pSum[i][j-1] + pSum[i-1][j] - pSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        row1++; //add 1 making 1-based indexing ( to match with pSum[m+1][n+1] )
        col1++;
        row2++;
        col2++; 
        return pSum[row2][col2] - pSum[row2][col1-1] - pSum[row1-1][col2] + pSum[row1-1][col1-1];
    }
};