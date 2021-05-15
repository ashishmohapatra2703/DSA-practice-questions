//Dutch National Flag Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortarr(vector<int> &arr, int n) 
{
    int low = 0;
    int high = arr.size()-1;
    int mid = 0;
    
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low] , arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid] , arr[high]);
            high--;
        }
    }
}
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
        
        sortarr(arr, n);
        
        for (int i=0; i<n; i++) 
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}