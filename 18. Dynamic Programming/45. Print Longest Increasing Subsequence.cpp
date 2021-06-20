//////////////////////////////////// M-1 //Best 
#include <iostream>
#include <vector>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> arr,int n) 
{
    vector<vector<int>> LIS(n); 
    //LIS[i] stores the actual longest increasing sub-sequence
    //starting from arr[0] ENDING with arr[i]
    
    LIS[0].push_back(arr[0]); //LIS[0] = {arr[0]}
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            //LIS[i] = {Max(LIS[j])} + arr[i] where j < i and arr[j] < arr[i]
            if(arr[j] < arr[i])
            {
                if(1+LIS[j].size() >= LIS[i].size())
                {
                    LIS[i] = LIS[j];
                }
            }
        } 
        LIS[i].push_back(arr[i]); //LIS[i] ends with arr[i] 
    }
    
    //Final LIS = having MAX length of all increasing sub-sequences of arr
    vector<int> maxlenLIS = LIS[0]; 
    for(int i=1; i<n; i++)
    {
        if(LIS[i].size() >= maxlenLIS.size()) 
            maxlenLIS = LIS[i];
    }
    
    return maxlenLIS;
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
            
        vector<int> result = longestIncreasingSubsequence(arr,n);
        for(int i=0; i<result.size(); i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
}



//////////////////////////////////// M-2
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> arr,int n) 
{
    int *LIS = new int[n];
    int *indLIS = new int[n];
    
    for(int i=0; i<n; i++)
    { 
        LIS[i] = 1; //every single element is increasing subseq. of length 1
    }
    for(int i=0; i<n; i++)
    { 
        indLIS[i] = 0; 
    }
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j] < arr[i])
            {
                if(1+LIS[j] >= LIS[i])
                {
                    LIS[i] = 1+LIS[j]; //same as LIS[i] = max(LIS[i] , 1+LIS[j]);
                    indLIS[i] = j;//ending at arr[i], prev. element in inc. subseq. was at the jth index of arr
                }
            }
        }
    }
    //LIS[i] stores the lenLIS ending with arr[i]
    
    int lenLIS = 0;  //overall lenLIS of arr = MAX of all elements of LIS[i]
    int indxlenLIS = 0; //index of that max. element
    for(int i=0; i<n; i++)
    {
        if(LIS[i] > lenLIS)
            lenLIS = LIS[i];
        if(LIS[i] > LIS[indxlenLIS])
            indxlenLIS = i;
    }
    //now, lenLIS == length of longest Increasing Subsequence of arr[]  //LISvec.size()

    vector<int> LISvec;
    for(int i=0; i<lenLIS; i++)
    {
        LISvec.push_back(arr[indxlenLIS]);
        indxlenLIS = indLIS[indxlenLIS];
    }
    reverse(LISvec.begin(), LISvec.end());

    return LISvec; //Constructed longest Increasing Subsequence of arr[]
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
            
        vector<int> result = longestIncreasingSubsequence(arr,n);
        for(int i=0; i<result.size(); i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
}
*/