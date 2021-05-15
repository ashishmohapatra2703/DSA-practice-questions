#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int low, int high);
/* The main function that implements QuickSort
 arr[] --> Array to be sorted, low  --> Starting index, high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


int partition (int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low+1;
   
    for(int j=low+1; j<=high; j++)
    {
        if(arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    swap(arr[low], arr[i-1]);
    return i-1;
}



/////M-2
int partition (int arr[], int low, int high)
{
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
   return j-1; //partition index
}

void quickSort(int arr[], int low, int high)
{
    if(low >= high)
        return;
    
    int PartitionIndex = partition(arr, low, high);
    //arr[PartitionIndex] is now in its sorted index.
    
    quickSort(arr, low, PartitionIndex-1);
    quickSort(arr, PartitionIndex+1, high);
}

