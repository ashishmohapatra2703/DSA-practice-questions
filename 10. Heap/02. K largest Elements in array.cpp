/*Given an array Arr of N positive integers, find K largest elements from the array. 
 The output elements should be printed in decreasing order.
Input:   N = 7, K = 3
		Arr[] = {1, 23, 12, 9, 30, 2, 50}
Output:  50 30 23
Explanation: 3 Largest element in the array are 50, 30 and 23.   */

vector<int> kLargest(int arr[], int n, int k) 
{
	priority_queue<int, vector<int>, greater<int>> minh; //MIN-HEAP
	for(int i=0; i<n; i++)
	{
	    minh.push(arr[i]);
	        
        if(minh.size() > k)
            minh.pop();
	}
	    
	vector<int> ans;
	while(! minh.empty())
	{
	    ans.push_back(minh.top());
	    minh.pop();  //reheapify after every pop
	}
	reverse(ans.begin(), ans.end());  //reverse sorted order
	return ans;
}