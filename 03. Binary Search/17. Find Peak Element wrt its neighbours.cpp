/*Given an unsorted array of integers. Find a peak element in it.
 An array element is a peak if it is NOT smaller than its neighbours. 
 For corner elements, we need to consider only one neighbour.

Input: array[]= {5, 10, 20, 15}
Output: 20
The element 20 has neighbours 10 and 15,
both of them are less than 20.

Input: array[] = {10, 20, 15, 2, 23, 90, 67}
Output: 20 or 90
The element 20 has neighbours 10 and 15, 
both of them are less than 20, similarly 90 has neighbous 23 and 67.    */
//B.S on answer concept 

int peakElement(int arr[], int n)
{
    int low = 0;
    int high = n-1;
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(mid>=1 && mid<=n-2)
        {
            if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]) //An array element is peak if it is not smaller than its neighbours
                return mid;
        }
        if(mid==0) //For corner elements, consider only one neighbour
        {
            if(arr[mid] >= arr[mid+1])
                return mid;
        }
        if(mid==n-1)
        {
            if(arr[mid] >= arr[mid-1])
                return mid;
        }
        

        else if(arr[mid+1] > arr[mid])
            low = mid + 1;
        else if(arr[mid-1] > arr[mid])
            high = mid - 1;
        //go for that segment which have greater neighbour
        //for which arr[mid] couldn't become peak
    }
    return -1;
}