/*Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order,
 and a number X is given. The task is to find whether element X is present in the matrix or not.
W.C Time Complexity: O(N+M).  */

class Solution
{
public:	
	int matSearch (vector<vector <int>> &mat, int N, int M, int X)
	{
	    int i = 0;
	    int j = M-1; //start from top right corner
	    
	    while((i>=0 && i<=N-1) && (j>=0 && j<=M-1))
	    {
	        if(X == mat[i][j])
	            return true; //Element found at index (i,j)
	       
	        else if(X < mat[i][j])
	            j--;
            else if(X > mat[i][j])
                i++;
	    }
	    return false; //key not found when i and j become out of matrix indices range
	}
};