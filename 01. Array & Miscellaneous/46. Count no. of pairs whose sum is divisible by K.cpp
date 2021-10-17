/*Given an array A[] and positive integer K, the task is to 
count total number of pairs in the array whose sum is divisible by K.

Input :  A[] = {2, 2, 1, 7, 5, 3, 4, 12} , K = 4
Output : 6
Explanation : There are six pairs possible whose sum is divisible by '4' i.e., 
(2, 2), (1, 7), (7, 5), (1, 3), (5, 3), (4,12)*/

class Solution{
public:
    //Take the mod of each element i.e, A[i] = A[i]%K;
    //now Question is reduced to how many distinct pairs sum to k

    int countKdivPairs(int A[], int n, int K)
    {
        int countPairsmodK0 = 0;
        unordered_map<int, int> modKCount;
        
        for(int i=0; i<n; i++)
        {
            int modK = A[i]%K;
            int toGetPair = (modK==0) ? 0 : K-modK;
            
            if(modKCount.find(toGetPair) != modKCount.end())
                countPairsmodK0 += modKCount[toGetPair];
                
            modKCount[modK]++;
        }
        return countPairsmodK0;
    }
    /*     (a+b) % K = 0
        => a %K + b %K = K %K;
        => b %K = K %K - a %K;
        => b %K = (K - a %K) %K;
    */
};