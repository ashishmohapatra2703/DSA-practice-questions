/* Examples:
Input : ab
Output : AB Ab ab aB

Input : ABC
Output : abc Abc aBc ABc abC AbC aBC ABC  */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PermutationWithCases(string op, string ip, vector<string> &perm) 
{
    if(ip.size() == 0)
    {
        perm.push_back(op);
        return;
    }
    
    string op1 = op;
    op1.push_back(tolower(ip[0]));
    string op2 = op;
    op2.push_back(toupper(ip[0]));
    
    ip.erase(ip.begin()+0);
    
    PermutationWithCases(op1 , ip, perm);
    PermutationWithCases(op2 , ip, perm);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string ip;
        cin>>ip;
        string op;
        
        vector<string> result;
        PermutationWithCases(op , ip, result);
        
        for(int i=0; i<result.size(); i++)
            cout<<result[i]<<" ";
            
        cout<<endl;
    }
}