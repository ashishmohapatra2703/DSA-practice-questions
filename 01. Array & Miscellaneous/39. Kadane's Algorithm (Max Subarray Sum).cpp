/* maximum sum of the contiguous sub-array
   i/p : {-2, -3, 4, -1, -2, 1, 5, -3}
   o/p: 7  i.e,  {4, -1, -2, 1, 5}       */
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int Kadanes_Algorithm(int arr[], int n) 
{
    int max_end_here = 0;
    int max_so_far = INT_MIN; //overall Global Max SubArray Sum
        
    for(int i=0; i<n; i++)
    {
        max_end_here += arr[i];
        max_end_here = max(max_end_here, arr[i]);    
        max_so_far = max(max_so_far, max_end_here);
    }
    return max_so_far;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
            
        int MaxSubArraySum = Kadanes_Algorithm(arr, n);
        cout<< MaxSubArraySum <<endl;
    }
}