/*Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.

Input: 
n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5. */

class Solution{
public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> unionArr; //worst case when all distinct
        
        int i=0;
        int j=0;
        
        while(i<n && j<m)
        {
            while(i!=n-1  &&  arr1[i] == arr1[i+1])
                i++;      //ignore duplicates in the same array
            while(j!=m-1  &&  arr2[j] == arr2[j+1])
                j++;
                
            if(arr1[i] < arr2[j])
                unionArr.push_back(arr1[i++]);
            else if(arr1[i] == arr2[j]) //copy one & ++ both pointers
            {
                unionArr.push_back(arr1[i]);
                i++;
                j++;  
            }
            else if(arr1[i] > arr2[j])
                unionArr.push_back(arr2[j++]);
        }
        
        //for remaining elements in either arrays
        while(i<n)
        {
            while(i!=n-1  &&  arr1[i] == arr1[i+1])
                i++;

            unionArr.push_back(arr1[i++]);
        }
        while(j<m)
        {
            while(j!=m-1  &&  arr2[j] == arr2[j+1])
                j++;

            unionArr.push_back(arr2[j++]);
        }
        
        return unionArr;
    }
};