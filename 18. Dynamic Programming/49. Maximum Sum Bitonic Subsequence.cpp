#include <iostream>
#include <algorithm>
using namespace std;

int MaximumSumofBitonicSubsequence(int arr[],int n) 
{
    int MSIS[n];
    for(int i=0; i<n; i++)
    { 
        MSIS[i] = arr[i];
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if((arr[j] < arr[i]))
            {
                if(arr[i]+MSIS[j] > MSIS[i])
                {
                    MSIS[i] = arr[i]+MSIS[j];
                }
            }
        }
    }
    //MSIS[i] stores the Max Sum of Incre. Sub Seq.-- ending with arr[i]
    //overall MSIS of arr = max(MSIS[i])
    
    int MSDS[n];
    for(int i=0; i<n; i++)
    { 
        MSDS[i] = arr[i];
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if((arr[j] < arr[i]))
            {
                if(arr[i]+MSDS[j] > MSDS[i])
                {
                    MSDS[i] = arr[i]+MSDS[j];
                }
            }
        }
    }
    //MSDS[i] stores the Max Sum of Decre. Sub Seq.-- starting from arr[i]
    //overall MSDS of arr = max(MSDS[i])
    
    int MSBS[n];
    for(int i=0; i<n; i++)
    { 
        MSBS[i] = MSIS[i]+MSDS[i]-arr[i];
    }
    //MSBS[i] stores the Max Sum of Bitonic. Sub Seq. having bitonic point at arr[i]
    
    //overall Max Sum of Bitonic. Sub Seq. of arr = max(LBS[i])
    int maxsum = 0;
    for(int i=0; i<n; i++)
    {
        maxsum = max(maxsum, MSBS[i]);
    }
    return maxsum;
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
            
        int result = MaximumSumofBitonicSubsequence(arr, n);
        cout<< result <<endl;
    }
}
