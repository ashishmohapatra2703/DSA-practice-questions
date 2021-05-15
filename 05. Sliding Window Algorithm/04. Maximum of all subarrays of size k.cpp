/*  Given an array arr[] of size N and an integer K.
 Find the maximum for each and every contiguous subarray of size K.
Input:
9 3
1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6    */

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> MaxOfEachSubarr;
    int i=0;
    int j=0;
    deque<int> psbl_max;
    
    while(j < n)
    {
        while( psbl_max.size()!=0 && psbl_max.back() < arr[j] )//.back() returns the last element of queue
        {
            psbl_max.pop_back();
        }
        psbl_max.push_back(arr[j]);
        
        
        if(j-i+1 < k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            MaxOfEachSubarr.push_back( psbl_max.front() );
            
            if(arr[i] == psbl_max.front())
            {
                psbl_max.pop_front();
            }
            i++;
            j++;
        }
    }
    return MaxOfEachSubarr;
}

