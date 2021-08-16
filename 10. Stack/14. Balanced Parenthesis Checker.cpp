/*Given an expression string exp. Examine whether the pairs and
 the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and
 'not balanced' for exp = “[(])”                 */
#include <iostream>
#include <stack>
using namespace std;

bool ParenthesisChecker(string exp)
{
    stack<char> s;
    
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(s.empty()) //for this closing, their is NO open bracket present
                return false;
            else if(  (exp[i] == ')' && s.top() == '(')  ||
                       (exp[i] == '}' && s.top() == '{')  ||
                        (exp[i] == ']' && s.top() == '[')    )
                s.pop();
            else
                return false;
        }
    }
    
    if(! s.empty())
        return false;
    else
        return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string exp;
        cin>>exp;
        if(ParenthesisChecker(exp) == true)
            cout<< "balanced" <<endl;
        else
            cout<< "not balanced" <<endl;
    }
}