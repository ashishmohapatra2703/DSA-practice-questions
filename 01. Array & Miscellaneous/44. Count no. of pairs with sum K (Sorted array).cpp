/*You are given an array Arr of size N. 
You need to find all pairs in the array that sum to a number K. 
If no such pair exists then output will be -1. 
The elements of the array are distinct and are in sorted order.

Note: (a,b) and (b,a) are considered same. 
Also, an element cannot pair with itself, i.e., (a,a) is invalid.

Input: n = 7  arr[] = {1, 2, 3, 4, 5, 6, 7}  K = 8
Output: 3
Explanation: We find 3 such pairs that sum to 8 (1,7) (2,6) (3,5) */

class Solution{
  public:
    int Countpair(int arr[], int n, int sum)
    {
        int countPairsSumK = 0;
        int low = 0;
        int high = n-1;
        
        while(low < high)
        {
            int pairSum = arr[low] + arr[high];
            
            if(pairSum == sum)
            {
                countPairsSumK ++;
                low++;
                high--;
            }
            else if(pairSum > sum)
                high--;
            else if(pairSum < sum)
                low++;
        }
        
        return (countPairsSumK==0) ? -1 : countPairsSumK;
    }
};