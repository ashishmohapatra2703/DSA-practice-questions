/*Given an array of N integers, and an integer K, 
find the number of pairs of elements in the array whose sum is equal to K.

Input: N = 4, K = 6 , arr[] = {1, 5, 7, 1}
Output: 2
Explanation:  arr[0] + arr[1] = 1 + 5 = 6  and arr[1] + arr[3] = 5 + 1 = 6.

Input: N = 4, X = 2 , arr[] = {1, 1, 1, 1}
Output: 6
Explanation: Each 1 will produce sum 2 with any 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)*/

//M-1 T.C = O(n²)
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        int countPairsSumK = 0;
        for (int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[j] + arr[i] == k)
                {
                    countPairsSumK++;
                }
            }
        }
        return countPairsSumK;
    }
};

//M-2 T.C = O(n) using hashing
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        int countPairsSumK = 0;
        unordered_map<int, int> elementCount;
        
        for(int i=0; i<n; i++)
        {
            if(elementCount.find(k-arr[i]) != elementCount.end())
                countPairsSumK += elementCount[k-arr[i]];
                
            elementCount[arr[i]]++;
        }
        return countPairsSumK;
    }
};