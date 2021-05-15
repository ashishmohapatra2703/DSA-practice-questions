/* You are given an unsorted array with both positive and negative elements. 
You have to find the smallest positive number missing from the array 
Input:  {2, 3, 7, 6, 8, -1, -10, 15}
 Output: 1

 Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
 Output: 4

 Input: {1, 1, 0, -1, -2}
 Output: 2 							*/

// M-1   t.c = O(n.logn)
int missingNumber(int arr[], int n) 
{ 
    sort(arr, arr+n);
    int K = 1; //flag
    for(int i=0; i<n; i++)
    {
        if(arr[i] == K)
        {
            K++;
        }
    }
    return K;
} 

// M-1   t.c = O(n)  &  s.c = O(n)  
int missingNumber(int arr[], int n) 
{ 
    int hash[1000001] {0};
    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0) //only positive numbers
        {
            hash[arr[i]] ++;
        }
    }
    
    for(int i=1; i<1000001; i++)
    {
        if(hash[i] == 0)
            return i;
    }
}