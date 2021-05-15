#include<iostream> 
using namespace std; 
  
int BinarySearch(int arr[], int low, int high, int key) 
{
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            high = mid-1;
        else if(key > arr[mid])
            low = mid+1;
    }
    return -1;
}

int findPos(int arr[], int key) 
{ 
    int low = 0;
    int high = 1; 
    while (key > arr[high]) 
    { 
        low = high;  
        high = high * 2;   
    } 
    //loop terminates when key <= arr[high]
    //NOW Classical B.S applied as arr[low] <= key <= arr[high]
    return BinarySearch(arr, low, high, key); 
} 
  
int main() 
{ 
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170, 220, 260, 400, 520, 980}; 
    int key;
    cin>>key;
    
    int ans = findPos(arr, key); 
    if (ans==-1) 
        cout << "Element not found"; 
    else
        cout << "Element found at index " << ans;
} 