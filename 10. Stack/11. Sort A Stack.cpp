/*Given a stack, the task is to sort it such that the top of the stack has the greatest element.
Input Stack: [ 11 2 32 3 41 ]
        41
        3
        32 
        2 
        11
Output: [ 41 32 11 3 2 ]  printed in descending order  
        41 
        32 
        11 
        3 
        2
Time Complexity : O(N²)
Auxiliary Space : O(N) recursive */

#include<iostream>
#include <stack>
using namespace std;

class SortedStack
{
    public:
        stack<int> s;
        void sort();
};
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int ele;
            cin>>ele;
            ss->s.push(ele);
        }
        ss->sort();
        printStack(ss->s);
    }
}



void InsertProperPosition(stack<int> &s, int key) //pass by reference
{
    if(s.size() == 0 || key >= s.top())
    {
        s.push(key);
        return;                      //base condition
    } 
    
    int lastele2 = s.top();
    s.pop();
    InsertProperPosition(s, key); //hypothesis
    
    s.push(lastele2);           //induction
}


/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    if(s.size() == 1)
        return;                   //base condition
        
    int lastele = s.top();
    s.pop();
    sort();                 //hypothesis
    
    InsertProperPosition(s, lastele); //induction
}