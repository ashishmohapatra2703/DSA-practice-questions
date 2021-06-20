#include<bits/stdc++.h>
using namespace std;

class _stack
{
    stack<int> s;
    int minEle;
    public :
        int getMin();
        int pop();
        void push(int);
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        _stack *a = new _stack();
        while(q--)
        {
            int qt;
            cin>>qt;
            if(qt==1)
            {
                //push
                int att;
                cin>>att;
                a->push(att);
            }
            else if(qt==2)
            {
                //pop
                cout<<a->pop()<<" ";
            }
            else if(qt==3)
            {
                //getMin
                cout<<a->getMin()<<" ";
            }
        }
        cout<<endl;
    }
}



/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.size()==0)
        return -1;
        
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.size()==0)
    {
        return -1;
    }
    else if(s.top() >= minEle)
    {
        int ans = s.top();
        s.pop();
        return ans;
    }
    else if(s.top() < minEle) //checking for flag i.e., s.top() actually contains currupt value of minEle
    {
        int ans = minEle;
        minEle = 2*minEle - s.top();
        s.pop();
        return ans;
    }
    return -1;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.size()==0)
    {
        s.push(x);
        minEle = x;
    }
    else if(x >= s.top() && x >= minEle) //x >= minEle condition bcz top can contain converted flag one
    {
        s.push(x);
        //No changing of min_ele here
    }
    else if(x < minEle)
    {
        s.push(2*x - minEle);
        minEle = x;
    }
    else if(x < s.top())
    {
        s.push(x);
    }
}

/*
i/p :-
3
6
1 2 1 3 2 3 1 1 3 
7
1 96 1 46 3 1 35 3 1 51 2
28
1 77 2 2 2 3 3 3 2 2 2 1 89 1 18 3 1 25 1 71 3 3 3 2 3 2 1 6 3 3 2 1 83 1 65 2

o/p :-
3 2 1 
46 35 51 
77 -1 -1 -1 -1 -1 -1 -1 -1 18 18 18 18 71 18 25 6 6 6 65 
*/