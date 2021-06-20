#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> iNGL(vector<int> arr, int n)
{
   vector<int> v;
   stack<pair<int,int>> st;

   for(int i=0; i<n; i++) //L to R traversal in arr
   {
        if(st.size()==0)
            v.push_back(-1);
        else if(st.size()>0 && st.top().first>arr[i])
            v.push_back(st.top().second);
        else if(st.size()>0 && st.top().first<=arr[i])
        {
            while(st.size()>0 && st.top().first<=arr[i])
            {
                st.pop();
            }//loop ends if st is empty or st.top()>arr[i] found
            if(st.size()==0)
                v.push_back(-1);
            else// if(st.top()>arr[i])
                v.push_back(st.top().second);
        }
        st.push({arr[i],i});//pushing a pair i.e, NGL element and its index
   }
   return v; //no reverse req. //vector v gives the "index of NGL" of each arr[i]
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
        vector<int> result = iNGL(arr,n);
        for(int i=0; i<n; i++)
        {
            cout<< (i-result[i]) <<" "; //i-v[i]
        }
        cout<<endl;
    }
}
