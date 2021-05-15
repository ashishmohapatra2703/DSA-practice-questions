/* Given an integer x. The task is to find the square root of x. 
If x is not a perfect square, then return floor(√x).
Input:
x = 5
Output: 2
Explanation: Since, 5 is not perfect square, so floor of square_root of 5 is 2.

Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.    */

long long int floorSqrt(long long int x) 
{
    int low = 0;
    int high = x;
    
    while(low <= high)
    {
        long long int mid = low + (high-low)/2;
        if(x == mid*mid) 
            return mid;
        else if(x < mid*mid)
            high = mid - 1;
        else if(x > mid*mid)
            low = mid + 1;
    }
    return high;
}