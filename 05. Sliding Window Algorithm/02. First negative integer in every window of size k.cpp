/* Given an array and a positive integer k, 
find the first negative integer for each and every window(contiguous subarray) of size k.
Input:
2
5
-8 2 3 -6 10
2
8
12 -1 -7 8 -15 30 16 28
3

Output:
-8 0 -6 -6
-1 -1 -7 -15 -15 0   */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> FirstNegEveryWindowSizeK(vector<int> arr, int n, int k) 
{
    vector<int> op;
    queue<int> neg; //or list can also be used
    int i = 0;
    int j = 0;
    
    while(j<n)
    {
        if(arr[j] < 0)
            neg.emplace(arr[j]);
    
        if(j-i+1 < k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            if(neg.empty() == true)
                op.push_back(0);
            else
                op.push_back(neg.front());
                
            if(arr[i] < 0  &&  arr[i] == neg.front())
                neg.pop();
                            
            i++;
            j++;
        }
    }
    return op;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) 
            cin>>arr[i];
        int k;
        cin>>k;
        
        vector<int> result = FirstNegEveryWindowSizeK(arr, n, k);
        
        for(int i=0; i<result.size(); i++) // result.size() is n-k+1
            cout<<result[i]<<" ";
        cout<<endl;
    }
}