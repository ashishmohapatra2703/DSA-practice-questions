#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> NGR(vector<int> arr, int n)
{
   vector<int> v;
   stack<int> st;

   for(int i=n-1; i>=0; i--) //R to L traversal in arr
   {
        if(st.size()==0)
            v.push_back(-1);
        else if(st.size()>0 && st.top()>arr[i])
            v.push_back(st.top());
        else if(st.size()>0 && st.top()<=arr[i])
        {
            while(st.size()>0 && st.top()<=arr[i])
            {
                st.pop();
            }//loop ends if st is empty or st.top()>arr[i] found
            if(st.size()==0)
                v.push_back(-1);
            else// if(st.top()>arr[i])
                v.push_back(st.top());
        }
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
        vector<int> result = NGR(arr,n);
        for(int i=0; i<n; i++)
        {
            cout<<result[i];
            if(i != n-1)
                cout<<" ";
        }
        cout<<endl;
    }
}
/*
 the complexity is still order of N only, as the second loop is subjective to a condition.
  Try to dry run the code and you will get it. In such problems where
   "the second loop is subjective to a condition" it is usually a constant factor (K) * N complexity, 
 where k can be >1 or even <1 (depends upon the each problem input) but no where near O(N^2)
 */