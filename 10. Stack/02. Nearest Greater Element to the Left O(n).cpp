#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> NGL(vector<int> arr, int n)
{
   vector<int> v;
   stack<int> st;

   for(int i=0; i<n; i++) //L to R traversal in arr
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
   return v; //no reverse req.
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
        vector<int> result = NGL(arr,n);
        for(int i=0; i<n; i++)
        {
            cout<<result[i];
            if(i != n-1)
                cout<<" ";
        }
        cout<<endl;
    }
}
