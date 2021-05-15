//Given an array of positive integers. The task is to print the maximum length of Bitonic subsequence. 
//A subsequenceof array is called Bitonic if it is first increasing, then decreasing.

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int lenLongestBitonicSubsequence(int arr[],int n) 
{
    int *LIS = new int[n];
    for(int i=0; i<n; i++)
    { 
        LIS[i] = 1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if((arr[j] < arr[i]))
            {
                LIS[i] = max(LIS[i] , 1+LIS[j]);
            }
        }
    }
    //LIS[i] stores the lenLIS -- starting from arr[0] ending with arr[i]
    //overall lenLIS of arr = max(LIS[i])
    
    int *LDS = new int[n];
    for(int i=0; i<n; i++)
    { 
        LDS[i] = 1;
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if((arr[j] < arr[i]))
            {
                LDS[i] = max(LDS[i] , 1+LDS[j]);
            }
        }
    }
    //LDS[i] stores the lenLDS -- starting from arr[i] ending with arr[n-1]
    //overall lenLDS of arr = max(LDS[i])
    
    int *LBS = new int[n];
    for(int i=0; i<n; i++)
    { 
        LBS[i] = LIS[i]+LDS[i]-1;
    }
    //LBitoS[i] stores the lenLBitoS having bitonic point at arr[i]
    
    int lenLBS = INT_MIN;
    for(int i=0; i<n; i++)
    {
        lenLBS = max(lenLBS , LBS[i]);
    }
    //overall lenLBS of arr = max(LBS[i])
    return lenLBS;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0; i<n; i++)
            cin>>arr[i];
            
        int result = lenLongestBitonicSubsequence(arr, n);
        cout<< result <<endl;
    }
}

/*
arr[i] = 2 -1 4 3 5 -1 3 2

LIS[i] = 1  1 2 2 3  1 2 2 
LDS[i] = 2  1 3 2 3  1 2 1 
LBS[i] = 2  1 4 3 5  1 3 2   // LBS[i] = LIS[i]+LDS[i]-1

lenLBS = 5 
*/
