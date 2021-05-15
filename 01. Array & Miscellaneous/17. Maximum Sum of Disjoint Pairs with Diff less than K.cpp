/*Given an array of integers A[] and a number k. You can pair two number of array 
if difference between them is strictly less than k. The task is to find 
maximum possible sum of such disjoint pairs. Sum of P pairs is sum of all 2P numbers of pairs.

Input  : A[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
Output : 62
Then disjoint pairs with difference less than K are,
(3, 5), (10, 12), (15, 17)	
max sum which we can get is 3 + 5 + 10 + 12 + 15 + 17 = 62
Note that an alternate way to form disjoint pairs is,
(3, 5), (9, 12), (15, 17), but this pairing produces less sum.

Input  : A[] = {5, 15, 10, 300}, k = 12
Output : 25  				*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> DisjointPairsDiffLessthanK(vector<int> arr, int n, int K) 
{
    sort(arr.begin(), arr.end());
    
    vector<pair<int,int>> v;
    
    int i = n-1; //moving from highest element at the right
    while(i >= 1)
    {
        if((arr[i] - arr[i-1]) < K)
        {
            v.push_back( {arr[i] , arr[i-1]} );
            i = i-2; //since we have to take disjoint pairs
        }
        else //(arr[i] - arr[i-1]) > K //that means 2nd elements corresponding to arr[i] 
        { //will NOT be found at further left as the difference will increase
            i--;
        }
    }
    return v;
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
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        int K;
        cin>>K;
        
        vector<pair<int,int>> pairs = DisjointPairsDiffLessthanK(arr, n, K);
        
        int maxsum = 0;
        for(int i=0; i<pairs.size(); i++)
        {
            maxsum += (pairs[i].first + pairs[i].second);
        }
        cout<< maxsum <<endl;
    }
}