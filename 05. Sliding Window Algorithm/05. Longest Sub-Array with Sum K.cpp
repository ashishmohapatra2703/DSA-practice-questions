/* Given an array containing N POSITIVE integers and an integer K. Your task is to 
find the length of the longest Sub-Array with sum of the elements equal to the given value K.
For Input:
1
7 5
4 1 1 1 2 3 5
your output is: 
4       */

#include <iostream>
using namespace std;

int LongestSubArrayWithSumK(int arr[],int N, int K) 
{
    int i = 0;
    int j = 0;
    int sumofsubarr = 0;
    int window_size = 0;
    
    while(j < N)
    {
        sumofsubarr += arr[j];
            
        if(sumofsubarr < K)
        {
            j++;
        }
        else if(sumofsubarr == K)
        {
            window_size = max(window_size , j-i+1);

            j++;
        }
        else if(sumofsubarr > K)
        {
            while(sumofsubarr > K)
            {
                sumofsubarr -= arr[i];
                i++;    
            }
            j++;
        }
    }
    return window_size;  //maximum window_size having sum == K  
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int K;
        cin>>K;
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        
        int result = LongestSubArrayWithSumK(arr, n, K);
        cout<<result<<endl;
    }
}