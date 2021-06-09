/* Inorder traversal of expression tree produces infix version of given postfix expression 
(same with postorder traversal it gives postfix expression) */

bool isOperator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^') 
        return true;
    else
        return false;
}
et* buildExprT(char postfix[], int &itr)
{
    if(itr < 0)
        return NULL;
    
    et* root = new et(postfix[itr]);
    itr--;
    
    if(isOperator(root->value) == true)
    {
        root->right = buildExprT(postfix, itr); //L-R-Node  ~ PostOrder form
        root->left = buildExprT(postfix, itr);
        return root;
    }
    else
    {
        return root;
    }
}
//function to construct expression tree
et* constructTree(char postfix[])
{
    int len = strlen(postfix)-1; //n-1
    return buildExprT(postfix, len);
}