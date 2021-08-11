//Question - 1
/*Given an integer array arr. You have to sort the integers in the array 
in ascending order by the number of 1's in their binary representation and 

Note: In case of 2 or more integers have the same number of 1's you have to sort them in ascending order.
Return the sorted array.

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: 
[0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]     */

class Solution {
public:
    static int countSetBits(int N) 
    {
        int count = 0;
        while(N != 0)
        {
            int rmsbm = (N & -N); //right-most set bit mask
            N = N - rmsbm;
            count ++;
        }
        return count;
    }
    static bool comparator(int &a, int &b)
    {
        if(countSetBits(a) == countSetBits(b))
            return a<b;
        
        return countSetBits(a) < countSetBits(b);
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(), comparator);
        return arr;
    }
};


//Question - 2
/*Given an array of integers, sort the array (in descending order) 
according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, 
sort according to their position in the original array i.e., a stable sort.

Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:  {15}, {7}, {5, 3, 9, 6}, {2, 4, 32}      */

//  https://www.geeksforgeeks.org/sort-array-according-count-set-bits/
//M-1
class Solution {
public:
    static int countSetBits(int N) 
    {
        int count = 0;
        while(N != 0)
        {
            int rmsbm = (N & -N); //right-most set bit mask
            N = N - rmsbm;
            count ++;
        }
        return count;
    }
    static bool comparator(int a, int b)
    {
        return countSetBits(a) > countSetBits(b); //descending order sorting
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, comparator);
    }
};

//M-2
class Solution {
public:
    void sortBySetBitCount(int arr[], int n)
    {
        vector<vector<int>> countHash(32);
        for(int i=0; i<n; i++)
        {
            int count = countSetBits(arr[i]); //done previously
            countHash[count].push_back(arr[i]);
        }
     
        int j = 0; 
        for(int i=31; i>=0; i--) //sorting according to count of set bits (in descending order)
        {
            for(int x: countHash[i]) //all nums having i set bits (in stable order)
                arr[j++] = x;
        }
    }
};

//M-3
class Solution {
public:
    void sortBySetBitCount(int arr[], int n)
    {
        multimap<int, int> mmap;
        for(int i=0; i<n; i++)
            mmap.insert({(-1)*countSetBits(arr[i]) , arr[i]}); // countSetBits() done previously
       
        int i = 0;
        for(auto it: mmap)
            arr[i++] = it.second;
    }
};