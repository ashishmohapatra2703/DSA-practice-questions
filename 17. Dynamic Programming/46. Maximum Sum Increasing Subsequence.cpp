#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaximumSumOfIncreasingSubsequence(vector<int> arr,int n) 
{
    int MSIS[n];
    for(int i=0; i<n; i++)
    { 
        MSIS[i] = arr[i]; //every single element is increasing subseq. of sum arr[i]
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
    //MSIS[i] stores the Max Sum value of Incresing Sub. Seq. ending with arr[i]
        
    //Finally MaximumSumOfIncreasingSubsequence is MAXIMUM of all MSIS values 
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(MSIS[i]>max)
            max = MSIS[i];
    }
    return max;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin>>arr[i];
            
        int result = MaximumSumOfIncreasingSubsequence(arr,n);
        cout<< result <<endl;
    }
}