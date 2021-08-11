/* https://www.geeksforgeeks.org/sort-an-array-according-to-absolute-difference-with-given-value/
  https://www.geeksforgeeks.org/sort-array-according-absolute-difference-given-value-using-constant-extra-space/

Given an array of n distinct elements and a number x, 
arrange array elements according to the absolute difference with x, 
i. e., element having minimum difference comes first and so on, using constant extra space. 

Note : If two or more elements are at equal distance 
arrange them in same sequence as in the given array.

Input  : arr[] = {11, 6, 3, 10, 4, 12}  x = 8
Output : arr[] = {6, 10, 11, 4, 12, 3}
Explanation : 
|11 - 8| = 3
|6 - 8|  = 2
|3 - 8|  = 5
|10 - 8| = 2
|4 - 8|  = 4
|12 - 8| = 4      // sorting relative array - 2,2,3,4,4,5
So according to the difference with X, elements are arranged as 6, 10, 11, 4, 12, 3  */

//M-1
class Solution {
public:
    void sortABS(int A[],int N, int k)
    {
        stable_sort(A, A+N, [k](int a, int b) {return abs(a-k) < abs(b-k);} );
    }
};

//M-2  TLE in gfg
class Solution {
public:
    void sortABS(int A[],int N, int k)
    {
        multimap<int, int> mmap;
        for(int i=0 ; i<N; i++)
            mmap.insert({ abs(A[i]-k), A[i] });
 
        int i = 0;
        for(auto it: mmap)
            A[i++] = it.second ;
    }
};