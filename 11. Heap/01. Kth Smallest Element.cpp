//////////////////////// M-1 (using MAX-HEAP)
// Time complexity = O(n.logk)
#include <iostream>
#include <queue>
using namespace std;

int kthSmallestElement(int* arr, int n, int k) 
{
    priority_queue<int> maxh;
    
    for(int i=0; i<n; i++)
    {
        maxh.push(arr[i]);

        if(maxh.size()>k)
            maxh.pop();
    }
    return maxh.top();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        int k;
        cin>>k;
        
        int ans = kthSmallestElement(arr, n, k);
        cout<< ans <<endl;
    }
}


///////////////// M-2

/* nth_element() is an STL algorithm which rearranges the list in such a way such that the element at 
//the nth position is the one which should be at that position if we sort the list.

//template 
void nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
first: Random-access iterator to the first element in the list.
last: Random-access iterator to the last element in the list.
nth: Random-access iterator pointing to the position in the list, 
which should be sorted.
If it points to end, then this function will do nothing.

Time Complexity of std::nth_element() =  O(n)    */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        int k;
        cin>>k;
        
        nth_element(arr.begin(), arr.begin()+k-1 , arr.end()); 
        cout<< arr[k-1] <<endl;
    }
}


//////////// M-3  [Quick Select - Randomised] Avg. case T.C = O(n)
//User function template for C++
// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

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