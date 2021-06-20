/*Given an array of integers and two numbers k1 and k2. 
Find the sum of all elements between given two k1’th and k2’th smallest elements of the array.
nput : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6  
Output : 26          
         3rd smallest element is 10. 6th smallest element is 20.
         Sum of all element between k1 & k2 is 12 + 14 = 26
 There is the repetition of the elements.
E.g. arr[] = { 2, 3, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10} k1 = 2 , k2 = 8;
According to your approach k1smallest = 3, k2smallest = 6 ans = 3 + 3 + 4 + 4 + 5 = 19
But according to question after removing duplicates
(we have to include all the elements in the given array between these numbers with their duplicates as well)

arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}
k1smallest = 3, k2smallest = 9
ans = 4 + 4 + 5 + 6 + 7 + 8 = 34   */
//NOT passed in gfg

#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int kthSmallestElement(vector<int> arr, int k) 
{
    priority_queue<int> maxh;
    
    for(int i=0; i<arr.size(); i++)
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
        vector<int> A(n);
        for(int i=0; i<n; i++) 
            cin>>A[i];
            
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
            mp[A[i]] ++;

        vector<int> arr;
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->second >= 1)
                arr.push_back(it->first);
        }
        
        int k1;
        cin>>k1;
        int k2;
        cin>>k2;
        if(k2 < k1)
            swap(k1, k2);  //Always k1 < k2
        if(k2 > arr.size())
            k2 = arr.size();

        int k1thSmallest = kthSmallestElement(arr, k1);
        int k2thSmallest = kthSmallestElement(arr, k2);
        
        long sum = 0; //Sum of elements between k1'th and k2'th smallest elements
        for(int i=0; i<arr.size(); i++) 
        {
            if(arr[i] > k1thSmallest  && arr[i] < k2thSmallest)
            {
                sum += arr[i]*mp[arr[i]];
            }
        }
        cout<< sum <<endl;
    }
}