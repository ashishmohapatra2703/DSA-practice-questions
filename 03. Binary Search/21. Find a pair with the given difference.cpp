/*//M-1
The simplest method is to run two loops, the outer loop picks the first element (smaller element) and
 the inner loop looks for the element picked by outer loop plus n.
 Time complexity of this method is O(n^2).
//M-2
Hashing can also be used to solve this problem. Create an empty hash table HT. 
Traverse the array, use array elements as hash keys and enter them in HT. 
Traverse the array again look for value diff + arr[i] in HT.
//M-3
 The first step is to sort the array in ascending order. Once the array is sorted,
 traverse the array from left to right, and for each element arr[i], 
 binary search for (arr[i] + diff)   in arr[i+1..n-1]. If the element is found, return the pair.
Both first and second steps take O(nLogn). So overall complexity is O(nLogn).    */
#include <iostream>
#include <algorithm>
using namespace std;

bool BinarySearch(int arr[], int low, int high, int key) 
{
    while(low <= high)
    {
        int mid = low + (high-low)/2; 
        if(key == arr[mid])
            return true; //mid is the index of key found
        else if(key < arr[mid])
            high = mid-1;
        else if(key > arr[mid])
            low = mid+1;
    }
    return false; //key not found unsuccessful search
}

bool ifPairExistsWithGivenDiff(int arr[], int n, int diff) 
{
    sort(arr, arr+n);
    
    for(int i=0; i<=n-2; i++)
    {
        //b-a = diff  => b = a+diff    //here a is in left side and b in right side
        int tofind = arr[i] + diff;
        
        if(BinarySearch(arr, i+1, n-1, tofind))
            return true; //pair Found is 'arr[i]' AND B.S index of 'tofind' 
    }
    return false;
}     //T.C = O(n.logn) + O(n.logn) 

/*  M-4
The second step of the above algorithm can be improved to O(n). The first step remain same. 
The idea for second step is take two index variables i and j, initialize them as 0 and 1 respectively. 
Now run a linear loop. 
If arr[j] – arr[i] is smaller than n, we need to look for greater arr[j], so increment j.
If arr[j] – arr[i] is greater than n, we need to look for greater arr[i], so increment i. */
#include <iostream>
#include <algorithm>
using namespace std;

bool ifPairExistsWithGivenDiff(int arr[], int n, int diff) 
{
    sort(arr, arr+n);
    
    int i = 0;
    int j = 1;
    
    while(i<=j && j<n)
    {
        if(arr[j]-arr[i] == diff && i!=j)
            return true;  //pair found is {arr[i] and arr[j]}
        else if(arr[j]-arr[i] > diff)
            i++;
        else if(arr[j]-arr[i] < diff)
            j++;
    }
    return false;
}  //T.C = O(n.logn) + O(n) 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int diff;
        cin>>diff;
        int arr[n];
        for(int i=0; i<n; i++) 
            cin>>arr[i];
            
        if(ifPairExistsWithGivenDiff(arr, n, diff))
            cout<<"1"<<endl;
        else
            cout<<"-1"<<endl;
    }
}
