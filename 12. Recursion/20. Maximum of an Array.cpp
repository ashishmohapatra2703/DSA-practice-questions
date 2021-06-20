#include <iostream>
#include <vector>
using namespace std;

int MaximumofArr(vector<int> &v, int idx)
{
    if(idx == v.size()-1)
        return v[idx];
        
    int maxfromRestArr = MaximumofArr(v , idx+1);
    if(v[idx] > maxfromRestArr)
        return v[idx];
    else
        return maxfromRestArr;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    cout<<MaximumofArr(v , 0); //return the Maximum of elements from 0th index to last index
}