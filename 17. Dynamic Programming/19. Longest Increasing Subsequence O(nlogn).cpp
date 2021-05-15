//T.C = O(nlogn)
//S.C = O(n)
//https://youtu.be/nf3YG4CnTbg
#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int> A,int n) 
{
    if(n==0)  //A.size() is n
        return 0; 

    vector<int> t(n); //last element of (index+1 = len size of largest subsequence)
    t[0] = A[0];

    int len = 1; //smallest size of increasing subsequence is 1
    for(int i=1; i<n; i++)
    {
        // new smallest value 
        if(A[i] < t[0]) //prev. larger value to be discarded 
            t[0] = A[i]; //0th index gives last value/value of len=1 subsequence
        // t[i] extends largest subsequence 
        else if(A[i] > t[len-1])
        {
            t[len] = A[i];
            len++;
        }
        // t[i] will become last value of an existing subsequence or 
        // Throw away larger elements in all LIS, 
        // to make room for upcoming greater elements than t[i]
        // (and also, t[i] would have already appeared in one of LIS, identify the location and replace it) 
        else
        {
            int low=0;
            int high=len-1;
            int mid;
            int k;
            while(low <= high)
            {
                mid = (low+high)/2;
                if(t[mid] < A[i])
                {
                    low = mid+1;
                }
                else //(t[mid] >= A[i])
                {
                    k = mid;
                    high = mid-1;
                }
            }
            t[k] = A[i]; //here k will be inserted accor. to the sorted order of t array
        }
    }
    return len;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int result = longestIncreasingSubsequence(arr,n);
    cout<< result <<endl;
    return 0;
}