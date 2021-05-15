/*Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, 
except for one number which will occur only once. Find the number occurring only once.
Input:
N = 5
A = {1, 1, 2, 5, 5}
Output: 2
Explanation: 
Since 2 occurs once, while other numbers occur twice, 2 is the answer. */


//T.C = O(N)
//S.C = O(1)
class Solution{
public:	
	int search(int A[], int N)
	{
	    int uniqueNum = 0;
        for(int i=0; i<N; i++)
        {
            uniqueNum = uniqueNum ^ A[i];
        }
        return uniqueNum;
	}
};



//OR
/*Find the Number Occurring Odd Number of Times
Given an array of positive integers. All numbers occur an even number of times 
except one number which occurs an odd number of times. Find the number in O(n) time & constant space.

Input : arr = {1, 2, 3, 2, 3, 1, 3}
Output : 3

Input : arr = {5, 7, 2, 7, 5, 2, 5}
Output : 5 */
class Solution{   
public:
    int getOddOccurrence(int arr[], int n) 
    {
        int oddNum = 0;
        for(int i=0; i<n; i++)
        {
            oddNum ^= arr[i];
        }
        return oddNum;
    }
};