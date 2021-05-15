#include <iostream>
#include <vector>
using namespace std;

void TransposeOfMatrix(vector<vector<int>> &mat, int n) //pass by reference
{
    for(int i=0; i<n; i++)
	{
        for(int j=0; j<i; j++) //for each row inner loop up to diagonal 
        {
            swap( mat[i][j] , mat[j][i] );
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> mat (n , vector<int>(n));
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
            }
        }
        
        TransposeOfMatrix(mat, n);
        
        //Printing the Transpose of given 2-D Matrix
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
}