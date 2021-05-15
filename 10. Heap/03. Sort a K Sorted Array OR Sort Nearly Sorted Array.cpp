/* Given an array of n elements, where each element is at most k away from its target position, 
 devise an algorithm that sorts in O(n log k) time.   
For e.g,let us consider k=2, element at index 7 in the sorted array, can be at indexes 5,6,7,8,9 in the given array
    Input : arr[] = {6, 5, 3, 2, 8, 10, 9}     k = 3 
    Output : arr[] = {2, 3, 5, 6, 8, 9, 10}    */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Sort_KSortedArray(vector<int> arr, int n, int k) 
{
    vector<int> sort;
    
    priority_queue<int, vector<int>, greater<int>> minh; //MIN-HEAP
	for(int i=0; i<n; i++)
	{
	    minh.push(arr[i]);
	        
        if(minh.size() > k)
        {
            sort.push_back(minh.top());
            minh.pop();
        }
	}
	
	while(! minh.empty())
	{
	    sort.push_back(minh.top());
	    minh.pop();  //reheapify after every pop
	}
	return sort;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int k; cin>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) 
            cin>>arr[i];
        
        vector<int> sort = Sort_KSortedArray(arr, n, k);
        for(int i=0; i<n; i++)
            cout<<sort[i]<<" ";
        cout<<endl;
    }
}