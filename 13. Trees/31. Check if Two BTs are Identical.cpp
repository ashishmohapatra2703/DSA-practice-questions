/*Given two binary trees, the task is to find if both of them are identical or not. 
Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: There are two trees both having 3 nodes and 2 edges, 
both treesare identical having the root as 1,
left child of 1 is 2 and right child of 1 is 3. */

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL)  //both NULL
            return true;
        if(r1==NULL || r2==NULL)  //any one is NULL
            return false;
        if(r1->data != r2->data) //if above both conditions are not the case,
            return false;       //then check if both datas are equal or not
            
        if(isIdentical(r1->left, r2->left) == true &&
            isIdentical(r1->right, r2->right) == true)
            return true;   //recur for checking in left and right subtree
        else
            return false;
    }
};