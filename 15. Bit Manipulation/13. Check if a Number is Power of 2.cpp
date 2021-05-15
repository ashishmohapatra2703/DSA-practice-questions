/*Given a non-negative integer N. The task is to check if N is a power of 2. 
More formally, check if N can be expressed as 2x for some x. */


// Function to check if given number n is a power of two.
bool isPowerofTwo(long long n)
{
    if(n == 0)
        return false;
    return ((n & (n-1)) == 0) ? true : false;
}