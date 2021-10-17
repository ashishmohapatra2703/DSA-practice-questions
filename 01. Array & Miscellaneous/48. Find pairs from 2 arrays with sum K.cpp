/*Given two unsorted arrays A of size N and B of size M of distinct elements, 
the task is to find all pairs from both arrays whose sum is equal to X.

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the pairs which sum to 9.*/

//M-1
//TC :- O(NlogN + MlogM)
//SC:- O(1). ignoring the vector that is required as a return val.
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        sort(A, A+N);
        sort(B, B+M);
        
        vector<pair<int,int>> pairsSumX;
        int low = 0;
        int high = M-1;
        
        while(low<=N-1 and high>=0)
        {
            int pairSum = A[low] + B[high];
            if(pairSum == X)
            {
                pairsSumX.push_back({A[low] , B[high]});
                low++;
                high--;
            }
            else if(pairSum > X)
                high--;
            else if(pairSum < X)
                low++;
        }
        return pairsSumX;
    }
};

//M-2 
/*1. Use hashing to store all first array elements in hash table. 
For elements of second array, subtract every element from x and check the result in hash table. 
If result is present, print the element and key in hash (which is an element of first array).*/
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        unordered_map<int, int> Bhash;
        for(int i=0; i<M; i++)
            Bhash[B[i]] ++;
            
        vector<pair<int,int>> pairsSumX;
        for(int i=0; i<N; i++)
        {
            if(Bhash[X - A[i]] >= 1)
                pairsSumX.push_back({A[i], X-A[i]});
        }
        
        sort(pairsSumX.begin(), pairsSumX.end());
        return pairsSumX;
    }
};