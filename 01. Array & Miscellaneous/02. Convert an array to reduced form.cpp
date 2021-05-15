//Given an array with n distinct elements, convert the given array to a reduced form 
//where all elements are in range from 0 to n-1. The order of elements is same, i.e., 
//0 is placed in place of smallest element, 1 is placed for second smallest element, … n-1 is placed for largest element

/////////////////////////////////////////////////////////////// M-1 O(n)
#include <iostream>
#include <vector>
using namespace std;

vector<int> ReducedForm(vector<int> A, int n)
{
    // A =[3 2 7 10 9] , n=5
    //ind=[0 1 2 3 4]
    vector<int> H(1001 , 0);
    for(int i=0; i<n; i++)
    {
        H[A[i]] ++;
    }
    //H = [0 0 1 1 0 0 0 1 0 1 1 ..]
    //ind=[0 1 2 3 4 5 6 7 8 9 10 ..]
    int order = 0;
    for(int i=0; i<1001; i++)
    {
        if(H[i] != 0)
        {
            H[i] = order;
            order++;
        }
    }
    //H = [0 0 0 1 0 0 0 2 0 3 4 ..]
    //ind=[0 1 2 3 4 5 6 7 8 9 10 ..]
    for(int i=0; i<n; i++)
    {
        A[i] = H[A[i]];
    }
    // A =[1 0 2 4 3] 
    //ind=[0 1 2 3 4]
    return A;
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

        vector<int> result = ReducedForm(A, n);
        for(int i=0; i<n; i++) 
            cout<<result[i]<<" ";
            
        cout<<endl;
    }
}

////////////////////////////////////////////////////////////// M-2 using map O(logn)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> ReducedForm(vector<int> A, int n)
{
    // A =[3 2 7 10 9] , n=5
    //ind=[0 1 2 3 4]
    map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        mp[A[i]] ++;
    }
    //mp[3]=1 , mp[2]=1 , mp[7]=1 , mp[10]=1 , mp[9]=1
    int order = 0;
    for(auto it=mp.begin(); it!=mp.end(); it++) //map access the data in sorted order
    {
        it->second = order;
        order++;
    }
    //mp[2]=0 , mp[3]=1 , mp[7]=3 , mp[9]=4 , mp[10]=5
    for(int i=0; i<n; i++)
    {
        auto it = mp.find(A[i]);
        A[i] = it->second;
    }
    // A =[1 0 2 4 3] 
    //ind=[0 1 2 3 4]
    return A;
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

        vector<int> result = ReducedForm(A, n);
        for(int i=0; i<n; i++) 
            cout<<result[i]<<" ";
            
        cout<<endl;
    }
}

/////////////////////////////////// M=3 using sorting of A[]