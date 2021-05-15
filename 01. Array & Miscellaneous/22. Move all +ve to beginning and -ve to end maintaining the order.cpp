/* Place all negative element at the end of an unsorted array
without changing the order of positive element and negative element.

Input : arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output : 1  3  2  11  6  -1  -7  -5 

Input : arr[] = {-5, 7, -3, -4, 9, 10, -1, 11}
Output : 7  9  10  11  -5  -3  -4  -1   */

void segregateElements(int arr[],int n) //T.C = O(n) and S.C = O(n)
{
    int output[n];
    int j = 0;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
            output[j++] = arr[i];
    }
    
    if(j==0)  //array contains only -ve elements
        return; 
    if(j==n)  //array contains only +ve elements
        return;  //No need of rearrangement
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0)
            output[j++] = arr[i];
    }
    
    memcpy(arr, output, sizeof(output));
}