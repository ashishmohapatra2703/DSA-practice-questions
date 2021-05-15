/*
Input Stack:    Output:
        5           1
        4           2
        3           3
        2           4
        1           5
 */

#include <iostream>
#include <stack>
using namespace std;

void PushAtBottom(stack<int> &s, int bottomele) //pass by reference
{
    if(s.size() == 0)
    {//empty stack
        s.push(bottomele);
        return;          //base condition
    } 
    
    int topele2 = s.top();
    s.pop();
    PushAtBottom(s, bottomele); //hypothesis
    
    s.push(topele2);       //induction
}
//topele in "ReversetheStack" function is passed by value as bottomele in "PushAtBottom" function
void ReversetheStack(stack<int> &s)
{
    if(s.size() == 1)
        return;//single element stack //base condition
        
    int topele = s.top();
    s.pop();
    ReversetheStack(s);    //hypothesis
    
    PushAtBottom(s, topele); //induction
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        stack<int> s;
        int n; cin>>n;
        for(int i=0; i<n; i++)
        {
            int ele;
            cin>>ele;
            s.push(ele);   //taking i/p bottom to top
        }
        if(s.size() == 0)
            break;

        ReversetheStack(s);
        
        while (!s.empty())
        {
            cout<<s.top()<<" "; //printing o/p top to bottom
            s.pop();
        }
        cout<<endl;
    }
}
