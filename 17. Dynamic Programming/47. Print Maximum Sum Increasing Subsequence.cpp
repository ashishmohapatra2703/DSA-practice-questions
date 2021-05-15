#include <iostream>
#include <vector>
using namespace std;

int sumof(vector<int> L)
{
    int sum = 0;
    for(int i=0; i<L.size(); i++)
    {
        sum += L[i];
    }
    return sum;
}
vector<int> MaximumSumIncreasingSubsequence(vector<int> arr,int n) 
{
    vector<vector<int>> MSIS(n); 
    //MSIS[i] stores the actual Maximum Sum increasing sub-sequence
    //starting from arr[0] ENDING with arr[i]
    
    MSIS[0].push_back(arr[0]); //MSIS[0] = {arr[0]} //base condition
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            //L[i] = {MaxSum(L[j])} + arr[i] where j < i and arr[j] < arr[i] 
            if(arr[j] < arr[i])
            {
                if(sumof(MSIS[j]) > sumof(MSIS[i]))
                {
                    MSIS[i] = MSIS[j];
                }
            }
        } 
        MSIS[i].push_back(arr[i]); //MSIS[i] ends with arr[i] 
    }
    
    //Final MaxSumIncSub.Seq. = having MAX Summation of all the increasing sub-sequences of arr
    vector<int> MaxSumIS = MSIS[0]; 
    for(int i=1; i<n; i++)
    {
        if(sumof(MSIS[i]) >= sumof(MaxSumIS)) 
            MaxSumIS = MSIS[i];
    }
    
    return MaxSumIS;
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
            
        vector<int> result = MaximumSumIncreasingSubsequence(arr,n);
        for(int i=0; i<result.size(); i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
}