//the order in which one parenthesize the product affects the
//number of simple arithmetic operations needed to compute the product, or the efficiency.
//  Print the minimum number of multiplications needed to multiply the chain.
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int dp[101][101]; //global declaration//acor. to constraints of i&j ,i.e, size of the arr[]

int MCM(int arr[], int i, int j)
{
    if(i>=j)
        return 0; //base condition //think of the invalid i/p
    if(dp[i][j] != -1)
        return dp[i][j];

    int minopertn = INT_MAX;
    for(int k=i; k<=j-1; k++) //option-1 movement of k
    {
        int tempans = MCM(arr, i ,k) + MCM(arr, k+1 ,j) + (arr[i-1]*arr[k]*arr[j]);
        //break into adding 2 function calls with proper boundary conditions and add with 3rd term
        if(tempans < minopertn)
            minopertn = tempans;
    }
    return dp[i][j] = minopertn;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int minoperations = MCM(arr, 1 , n-1); //find proper i and j values for main functuon call
        cout<< minoperations <<endl;
    }
}
