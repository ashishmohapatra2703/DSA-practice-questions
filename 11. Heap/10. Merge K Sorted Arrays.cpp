/*Given K sorted arrays arranged in the form of a matrix of size K*K. 
The task is to merge them into one sorted array.
Given , merge them 
Input:  k = 4
arr[][] = { {1, 5, 6, 8}, 
            {2, 4, 10, 12}, 
            {3, 7, 9, 11}, 
            {13, 14, 15, 16} } ;
Output: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16   */

//let us take , k sorted arrays of size n each
//no. of cols = N i.e, arr[i].size() at worst case
//no. of rows = K i.e, arr.size()

//M-1  Brute Force  T.C = NK.log(NK)
class Solution{
public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> mergeAll;
        
        for(int i=0; i<K; i++)
            for(int j=0; j<K; j++)
                mergeAll.push_back(arr[i][j]);

        sort(mergeAll.begin(), mergeAll.end());
        return mergeAll;
    }
};

//M-2  merging sorted arrays one by one in pair with a reference array T.C = O(N. K²)
class Solution{
public:
    vector<int> merge2SortedArrinto1(vector<int> &arr1, vector<int> &arr2, int K)
    {
        vector<int> merge;
        int i=0;
        int j=0;
        while(i<arr1.size() and j<K) //arr2.size() = K
        {
            if(arr1[i] <= arr2[j])
                merge.push_back(arr1[i++]);  
            else if(arr1[i] > arr2[j])
                merge.push_back(arr2[j++]);
        }
        
        while(i<arr1.size())
            merge.push_back(arr1[i++]);
        while(j<K)
            merge.push_back(arr2[j++]);
        
        return merge;
    }
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> mergekSortedArr;
        for(int i=0; i<K; i++)
        {
            mergekSortedArr = merge2SortedArrinto1(mergekSortedArr, arr[i], K);
        }
        return mergekSortedArr;
    }
};

//M-3 Using divide and conquer   T.C = O(N. KlogK)
//There are log k levels as in each level the k arrays are divided in half 
//and at each level the k arrays are traversed. 
//Space Complexity: O( n * k * log k). 
//In each level O( n*k ) space is required So Space Complexity is O( n * k * log k).
class Solution{
public:
    vector<int> merge2SortedArrinto1(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> merge;
        int i=0;
        int j=0;
        int n = arr1.size();
        int m = arr2.size();
        while(i<n and j<m) //arr2Size = K
        {
            if(arr1[i] <= arr2[j])
                merge.push_back(arr1[i++]);  
            else if(arr1[i] > arr2[j])
                merge.push_back(arr2[j++]);
        }
        
        while(i<n)
            merge.push_back(arr1[i++]);
        while(j<m)
            merge.push_back(arr2[j++]);
        
        return merge;
    }
    vector<int> mergeKSortedArr(vector<vector<int>> arr, int start, int end)
    {
        if(start == end) //K=1 => arr size = 1
            return arr[start];
            
        int mid = (start+end)/2;
        vector<int> arr1 = mergeKSortedArr(arr, start, mid);
        vector<int> arr2 = mergeKSortedArr(arr, mid+1, end);
        
        return merge2SortedArrinto1(arr1, arr2); //standard program , DEFINED ABOVE
    }
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {      
        return mergeKSortedArr(arr, 0, K-1);
    }
};

//M-4 Using Priority Queue / Min-Heap   T.C = O(N. KlogK)  , S.C = O(K)
//Insertion and deletion in a Min Heap requires log k time.
class triplet{
public:
    int value;
    int arrayIdx;
    int valueIdxinArr;
    triplet(int value, int arrayIdx, int valueIdxinArr)
    {
        this->value = value;
        this->arrayIdx = arrayIdx;
        this->valueIdxinArr = valueIdxinArr;
    }
};
class myComparator{
public:
    bool operator()(triplet &a, triplet &b) 
    {
        return a.value > b.value;  //for min-heap behaviour
    }
};

class Solution{
public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplet, vector<triplet>, myComparator> minh; //MIN-HEAP
        vector<int> mergeKSortedArr;
        
        for(int i=0; i<K; i++)
        {
            triplet t(arr[i][0], i, 0); //0th element of every row total K
            minh.push(t);
        }
        
        while(! minh.empty())
        {
            triplet currMin = minh.top();
            minh.pop();
            int currMinVal = currMin.value;
            int currArrayIdx = currMin.arrayIdx;
            int currValIdxinArr = currMin.valueIdxinArr;
            
            mergeKSortedArr.push_back(currMinVal);
            
            if(currValIdxinArr+1 < K) //arr[currArrayIdx.size()] = K
            {
                triplet t(arr[currArrayIdx][currValIdxinArr+1], currArrayIdx, currValIdxinArr+1);
                minh.push(t);
            }
        }
        return mergeKSortedArr;
    }
};