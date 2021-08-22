/*Given an array of integers of size N, for all, i's [1, N], 
the task is to find the minimum subarray sum in the subarray [i, N].

Input:  [3, -1, -2]
Output: [-3, -3, -2]
Explanation:
1. i = 1, subarray is [3, -1, -2], all possible subarrays are [3], [-1], [-2], [3, -1], [-1, -2], [3, -1, -2]. Minnimum sum is -3 [-1, -2].
2. i = 2, subarray is [-1, -2], all possible subarrays are [-1], [-2], [-1, -2]. Minnimum sum is -3 [-1, -2].
3. i = 3, subarray is [-2], all possible subarrays are [-2]. Minnimum sum is -2[-2].*/

//M-1
#include <iostream>
#include <climits>
using namespace std;

int MinSubArraySum(int arr[], int &istart, int &n) 
{
    int min_end_here = 0;
    int min_so_far = INT_MAX; //overall Global Min SubArray Sum
        
    for(int i=istart; i<n; i++)
    {
        min_end_here += arr[i];
        min_end_here = min(min_end_here, arr[i]);
        min_so_far = min(min_so_far, min_end_here);
    }
    return min_so_far;
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
        for(int i=0; i<n; i++) 
            cin>>arr[i];
            
        for(int i=0; i<n; i++)
        {
            int ans = MinSubArraySum(arr, i, n);
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}



//M-2 optimized
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    int size;
	    cin>>size;
	    int arr[size];
	    for(int j=0;j<size;j++)
	        cin>>arr[j];


	    int res[size];
	    res[size-1]=arr[size-1];

	    int minimum=arr[size-1];
	    int num=arr[size-1];

	    for(int k=size-2;k>=0;k--)
	    {
	       num=min(arr[k],num+arr[k]);
	       minimum=min(minimum,num);
	       res[k]=minimum;
	    }

	    for(int m=0;m<size;m++)
	        cout<<res[m]<<" ";
	    cout<<endl;
	}
	return 0;
}