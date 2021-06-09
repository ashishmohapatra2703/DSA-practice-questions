/* Given a character array a[] representing a prefix expression. 
The task is to build an Expression Tree for the expression and 
then print the infix and postfix expression of the built tree.

Input: a[] = "*+ab-cd"
Output: The Infix expression is:
a + b * c – d
The Postfix expression is:
a b + c d – *							*/

bool isOperator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^') 
        return true;
    else
        return false;
}
et* buildExprT(char prefix[], int &itr)
{
    if(itr >= strlen(prefix))
        return NULL;
    
    et* root = new et(prefix[itr]); //create a node
    itr++;
    
    if(isOperator(root->value) == true)
    {
        root->left = buildExprT(prefix, itr);  //Node-L-R  ~ PreOrder form
        root->right = buildExprT(prefix, itr);
        return root;
    }
    else //if operand
    {
        return root;
    }
}
//function to construct expression tree
et* constructTree(char prefix[])
{
    return buildExprT(prefix, 0);
}