/*Given an array and a number k where k is smaller than the size of the array, 
we need to find the k’th smallest element in the given array. 

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 4
Output: 10      */


int partition(int arr[], int low, int high)
{
    //Randomly pick a pivot element (index between l and h).
    //swap the element at randomly generated index with the last element, 
   //and finally call the standard partition process which uses last element as pivot.
   int randomindex = rand()%(high-low+1) + low; //2 lines of optimization 
   swap(arr[randomindex], arr[high]);
   int pivot = arr[high];
   
   int i = low;
   int j = low;
   
   while(i <= high)
   {
       if(arr[i] > pivot)
       {
           i++;
       }
       else if(arr[i] <= pivot)
       {
           swap(arr[i], arr[j]);
           i++;
           j++;
       }
   }
   return j-1; 
}

int kthSmallest(int arr[], int l, int r, int k) //to find element at (k-1)th sorted index
{
    //if(l == r)
    //    return arr[l];

    int pi = partition(arr, l, r); //partitioning index / return the sorted index of the pivot
        
    if(k-1 == pi)
        return arr[pi];
      
    else if(k-1 > pi)
        return kthSmallest(arr, pi+1, r, k);
    else if(k-1 < pi)
        return kthSmallest(arr, l, pi-1, k);
}