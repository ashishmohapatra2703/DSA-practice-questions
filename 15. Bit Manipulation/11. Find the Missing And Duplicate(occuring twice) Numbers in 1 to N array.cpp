/* Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
Find these two numbers.
Input:
N = 7
Arr[] = {3, 6, 2, 5, 1, 2, 7}
Output: 2 4
Explanation: Repeating number is 2 and smallest positive missing number is 4. */

class Solution{
public:
    int* findTwoElement(int *arr, int n) 
    {
        int xXORy = 0;
        for(int i=0; i<n; i++)
        {
             xXORy = xXORy ^ arr[i];
        }
        for(int i=1; i<=n; i++)
        {
             xXORy = xXORy ^ i;
        }
        

        int rmsbm_xXORy = (xXORy & -xXORy);
        
        int x=0;
        int y=0;
        for(int i=0; i<n; i++)
        {
            if((arr[i] & rmsbm_xXORy) == 0)
                x = x ^ arr[i];
            else if((arr[i] & rmsbm_xXORy) == rmsbm_xXORy)
                y = y ^ arr[i];
        }
        for(int i=1; i<=n; i++)
        {
            if((i & rmsbm_xXORy) == 0)
                x = x ^ i;
            else if((i & rmsbm_xXORy) == rmsbm_xXORy)
                y = y ^ i;
        }

        
        int* DupliAndMissing = new int[2];
        for(int i=0; i<n; i++)
        {
            if(arr[i] == x) // x is duplicate
            {
                DupliAndMissing[0] = x;
                DupliAndMissing[1] = y;
                break;
            }
            else if(arr[i] == y) // y is duplicate
            {
                DupliAndMissing[0] = y;
                DupliAndMissing[1] = x;
            }
        }
        return DupliAndMissing;
    }
};