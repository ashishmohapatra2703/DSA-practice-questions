#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char x)
{
    if(x=='(' || x==')' || x=='^' || x=='*' || x=='/' || x=='+' || x=='-')
        return false; //operators
    else 
        return true; //operators
}
int outstackPreced(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0; 
        
    return -1;
}
// outstackPreced of ')' == instackPreced of '(' == 0
int instackPreced(char x)
{
    if(x=='+' || x=='-')
        return 2; //L to R associativity  outstackPrecd < instackPrecd
    else if(x=='*' || x=='/')
        return 4; //L to R associativity  outstackPrecd < instackPrecd
    else if(x=='^')
        return 5; //R to L associativity  outstackPrecd > instackPrecd
    else if(x=='(')
        return 0;
    //No instackPrecd for ')'
    return -1;
}

string InfixToPostix(string infix) 
{
    stack<char> s;
    string postfix = ""; 
    
    int i=0;
    while(infix[i] != '\0')
    {
        if( isOperand(infix[i]) ) //for operand -> send to postfix & move
        {
            postfix.push_back(infix[i]); 
            i++;
        }
        else //for operator
        {
            if( (s.empty()==true) || (outstackPreced(infix[i]) > instackPreced(s.top()))  )
            {
                s.push(infix[i]); //push to stack only if s.top() have lesser precedence & move
                i++;
            }
            else if( (outstackPreced(infix[i]) < instackPreced(s.top())) )
            {
                postfix.push_back(s.top()); 
                s.pop();
                //Stay at that index, unless & until s.top() have equal or lesser precedence
                //pop & append to postfix (Don't increment i)
            }
            else if( (outstackPreced(infix[i]) == instackPreced(s.top())) )
            {
                //dont add to postfix
                s.pop();
                i++;
                //Applies only to ')'     // ')' is never pushed in stack
                //so that when it encounters '(' in stack
                //just pop out '(' and move
            }
        }
    }
    //lastly empty the stack , appending all to postfix
    while(!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }
    
    return postfix;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string infix;
        cin>>infix;
        
        string postfix = InfixToPostix(infix);
        cout<< postfix <<endl;
    }
}