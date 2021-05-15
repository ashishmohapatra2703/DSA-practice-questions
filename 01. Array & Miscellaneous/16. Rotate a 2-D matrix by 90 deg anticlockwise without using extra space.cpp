/*Input: N = 4
Arr[][] = {{1,  2,  3,  4}
           {5,  6,  7,  8}
           {9, 10, 11, 12}
           {13, 14, 15, 16}}
Output:
 4  8 12 16 
 3  7 11 15 
 2  6 10 14 
 1  5  9 13
Explanation: The given matrix is rotated by 90 degree in anti-clockwise direction.  */

class Solution{
public:	
	void rotateMatrix(vector<vector<int>> &arr, int n) //pass by reference
	{
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<i; j++) //for each row inner loop up to diagonal 
	        {
	            //OR just cout<<arr[j][n-1-i]<<"  "; //if only Rotated Matrix to be printed
	            
	            swap( arr[i][j] , arr[j][i] );
	        }
	    }
	    //Transposed and then interchanging of rows
	    
	    for(int row=0;  row<n/2;  row++)
	    {
	        swap( arr[row] , arr[n-1-row] ); 
	    }
	}
};