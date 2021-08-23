/* Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.

Input 1:
 A = [4, 2, 2, 6, 4]  and B = 6
Output 1:  4
Explanation 1:
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Input 2:
 A = [5, 6, 7, 8, 9]  and B = 5
Output 2:  2
Explanation 2:
 The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]  */

int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    int countSubArrXORK = 0;
        
    unordered_map<int, int> prefixXORCount; //storing the no. of subarrays with XOR of all its elements = prefixXOR
    int prefixXOR = 0;
        
    for(int i=0; i<n; i++)
    {
        prefixXOR ^= A[i];

        if(prefixXOR == B)
            countSubArrXORK ++;
        if(prefixXORCount.find(prefixXOR^B) != prefixXORCount.end())
            countSubArrXORK += prefixXORCount[prefixXOR^B];
                
        prefixXORCount[prefixXOR]++;
    }
    return countSubArrXORK;
}
