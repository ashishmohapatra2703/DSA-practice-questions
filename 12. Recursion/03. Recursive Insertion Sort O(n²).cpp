#include <iostream>
#include <vector>
using namespace std;

void InsertProperPosition(vector<int> &v, int key)
{
    if(v.size() == 0 || key >= v[v.size()-1])
    {
        v.push_back(key);
        return;                      //base condition
    } 
    
    int lastele2 = v[v.size()-1];
    v.pop_back();
    InsertProperPosition(v, key); //hypothesis
    
    v.push_back(lastele2);           //induction
}
void SortArray(vector<int> &v)
{
    if(v.size() == 1)
        return;                   //base condition
        
    int lastele = v[v.size()-1];
    v.pop_back();
    SortArray(v);                 //hypothesis
    
    InsertProperPosition(v, lastele); //induction
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    SortArray(v);
    
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
}