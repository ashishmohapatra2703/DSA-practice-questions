#include<iostream> 
using namespace std; 
  
int FirstOccurrenceofKeyBS(int arr[], int low, int high, int key) 
{
    int firstindex = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2; 
        if(key == arr[mid])
        {
            firstindex = mid; //found a index of the key
            high = mid-1; //further search in left
        }
        else if(key < arr[mid])
            high = mid-1;
        else if(key > arr[mid])
            low = mid+1;
    }
    return firstindex;
}

int indexOfFirstOne(int arr[], int key) 
{ 
    int low = 0;
    int high = 1; 
    while (key > arr[high]) 
    { 
        low = high;  
        high = high * 2;   
    } 
    //loop terminates when key <= arr[high]
    //NOW Classical 1st occurrenec B.S applied as arr[low] <= key <= arr[high]
    return FirstOccurrenceofKeyBS(arr, low, high, key); 
} 

int main() 
{ 
    int arr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
    int key = 1;
    cout << "Index = " << indexOfFirstOne(arr, key); 
} 