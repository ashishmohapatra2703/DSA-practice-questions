/*We are given two sorted arrays. We need to merge these two arrays such that 
the initial numbers (after complete sorting) are in the first array and 
the remaining numbers are in the second array. Extra space allowed in O(1).
Example: 
Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}  

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}   */

//M-1 TLE
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            for(int i=0; i<n; i++)
            {
                if(arr1[i] > arr2[0])
                {
                    swap(arr1[i] , arr2[0]);
                    sort(arr2, arr2+m);
                }
            }
        }
};

 
//M-2 TLE  T.C = O(n * m)
class Solution{
    public:
        void insertInProperIndex(long long arr2[], long long &key, int &size) 
        {
            for(int j=1; j<size; j++)
            {
                if(key > arr2[j])
                {
                    arr2[j-1] = arr2[j];
                    arr2[j] = key;
                }
                else
                    break;
            }
        }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            for(int i=0; i<n; i++)
            {
                if(arr1[i] > arr2[0])
                    swap(arr1[i] , arr2[0]);
                else
                    continue;
                    
                long long key = arr2[0];
                insertInProperIndex(arr2, key, m); //1 pass of Insertion sort 
            }
        } 
};


//M-3  Efficient
//https://youtu.be/59VkIo4Pk3Y
class Solution{
public:
    void merge(long long arr1[], long long arr2[], int n, int m) 
    { 
        for(int i=n-1,j=0; i>=0&&j<=m-1; i--,j++)
        {
            if(arr1[i] > arr2[j])
                swap(arr1[i] , arr2[j]); //place smaller elements in arr1, larger in arr2
            else
                break;
        }
            
        sort(arr1, arr1+n);
        sort(arr2, arr2+m);
    }
};