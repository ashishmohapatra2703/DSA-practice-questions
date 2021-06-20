#include <iostream>
#include <vector>
using namespace std;

void ReverseArray(vector<int> &v, int idx)
{
    if(idx == v.size())
        return;
        
    ReverseArray(v , idx+1);
    cout<<v[idx]<<" ";
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    ReverseArray(v , 0); //Display reversed array elements from 0th index to last index
}