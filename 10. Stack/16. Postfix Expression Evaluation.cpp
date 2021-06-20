#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return false; //operators
    else 
        return true; //operands
}
int PostfixEvaluation(string postfix)
{
    stack<int> s;

    for(int i=0; postfix[i] != '\0'; i++)
    {
        if( isOperand(postfix[i])==true )
        {
            s.push(postfix[i]-'0'); //if operand, convert to int & only push to stack
        }
        else//if operator, pop 2 operand & perform operation then push that result into stack
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            //1st pop is right opreand and 2nd pop is left operand in a operation
            int result; 
            if(postfix[i] == '+')
                result = operand1 + operand2;
            else if(postfix[i] == '-')
                result = operand1 - operand2;
            else if(postfix[i] == '*')
                result = operand1 * operand2;
            else if(postfix[i] == '/')
                result = operand1 / operand2;
            
            s.push(result);
        }
    }
    return s.top();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string postfix;
        cin>>postfix;
        int ans = PostfixEvaluation(postfix);
        cout<< ans <<endl;
    }
}