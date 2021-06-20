/* Given a full binary expression tree 
consisting of basic binary operators (+ , – ,*, /) and some integers, 
Your task is to evaluate the expression tree.
Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 
Output: 100
Explanation:  ((5 * 4) + (100 - 20)) = 100 		*/

//M-1 
class Solution{
public:
    int convertStringtoInt(string str) 
    { 
        int num = 0;
        for(int i=0; str[i]!='\0'; i++) 
        {
            num = num*10 + (str[i]-48); 
        }
        return num;
    }
    
    bool isOperator(string x)
    {
        if(x=="+" || x=="-" || x=="*" || x=="/") 
            return true;
        else
            return false;
    }
    int evaluatepostfixExpr(vector<string> &postfix)
    {
        stack<int> st;
        
        for(int i=0; i<postfix.size(); i++)
        {
            if(isOperator(postfix[i]) == false) //if operand, convert to int & push to stack only
                st.push(convertStringtoInt(postfix[i]));
            
            else if(isOperator(postfix[i]) == true) //if operator, pop 2 operand & perform operation then push that result into stack
            {
                int numR = st.top();
                st.pop();
                int numL = st.top();
                st.pop();
                
                if(postfix[i] == "+")
                    st.push(numL+numR);
                else if(postfix[i] == "-")
                    st.push(numL-numR);
                else if(postfix[i] == "*")
                    st.push(numL*numR);
                else if(postfix[i] == "/")
                    st.push(numL/numR);
            }
        }
        return st.top();
    }
    
    void getpostfixExpr(node* root, vector<string> &postfix) //using postOrder Traversal
    {
        if(root==NULL)
            return;
        
        getpostfixExpr(root->left, postfix);
        getpostfixExpr(root->right, postfix);
        
        postfix.push_back(root->data);
    }
    
    
    /*You are required to complete below method */
    int evalTree(node* root) 
    {
        vector<string> postfix;
        getpostfixExpr(root, postfix); //{"5", "4", "*", "100", "20", "-", "+"}
        return evaluatepostfixExpr(postfix);
    }
};




//M-2 
class Solution{
public:
    int convertStringtoInt(string str) 
    { 
        int num = 0;
        for(int i=0; str[i]!='\0'; i++) 
        {
            num = num*10 + (str[i]-48); 
        }
        return num;
    }
    
    /*You are required to complete below method */
    int evalTree(node* root) 
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return convertStringtoInt(root->data); //or can use stoi(root->data) built-in C++ function
        
        if(root->data == "+")
            return evalTree(root->left) + evalTree(root->right);
        else if(root->data == "-")
            return evalTree(root->left) - evalTree(root->right);
        else if(root->data == "*")
            return evalTree(root->left) * evalTree(root->right);
        else if(root->data == "/")
            return evalTree(root->left) / evalTree(root->right);
    }
};