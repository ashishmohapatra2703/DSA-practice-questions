/* Example:
Input:
    2
    AB
    ABC
Output:
    (A B)(AB)
    (A B C)(A BC)(AB C)(ABC)   */
#include <iostream>
#include <vector>
using namespace std;

void PermutationWithSpaces(string op, string ip, vector<string> &perm) 
{
    if(ip.size() == 0)
    {
        perm.push_back(op);
        return;
    }
    
    string op1 = op + " " + ip[0];
    string op2 = op + ip[0];
    
    ip.erase(ip.begin()+0);
    
    PermutationWithSpaces(op1 , ip, perm);
    PermutationWithSpaces(op2 , ip, perm);
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
        op.push_back(ip[0]); //since no choice of spaces before the 1st letter
        ip.erase(ip.begin()+0); //smaller i/p according to the recursive tree
        
        vector<string> result;
        PermutationWithSpaces(op , ip, result);
        
        
        for(int i=0; i<result.size(); i++)
            cout<<"("<<result[i]<<")";
            
        cout<<endl;
    }
}