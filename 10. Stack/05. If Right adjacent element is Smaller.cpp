//Given an integer array of size N. For each element in the array, check whether the right adjacent //element (on the next immediate position) of the array is smaller.
//If next element is smaller, print that element.   If not, then print -1.

//M=1 Can easily be done with comparisons in traversal (in array elements)
//M-2 using stack
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> ImmediateSmallertoRight(vector<int> arr, int n)
{
   vector<int> v;
   stack<int> st;

   for(int i=n-1; i>=0; i--) //L to R traversal in arr
   {
        if(st.size()==0)
            v.push_back(-1);
        else if(st.size()>0 && st.top()<arr[i])
            v.push_back(st.top());
        else if(st.size()>0 && st.top()>=arr[i])
            v.push_back(-1);
            
        st.push(arr[i]);
   }
   reverse(v.begin(),v.end());
   return v;
}

int main()
{
    int t;
    cin>>t;
    for(int t_itr=0; t_itr<t; t_itr++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        vector<int> result = ImmediateSmallertoRight(arr,n);
        for(int i=0; i<n; i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
}