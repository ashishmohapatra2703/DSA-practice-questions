/* Given a Binary Tree. Check whether it is Symmetric or not, 
i.e. whether the binary tree is a Mirror image of itself or not.

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: True
Explanation: Tree is mirror image of itself i.e. tree is symmetric */

int areMirror(Node* a, Node* b) 
{
    if(a==NULL && b==NULL)  //both NULL
        return true;
    if(a==NULL || b==NULL)  //any one is NULL
        return false;
    if(a->data != b->data) //if above both conditions are not the case,
        return false;       //then check if both datas are equal or not
        
    if(areMirror(a->left, b->right) == true &&
        areMirror(a->right, b->left) == true)
        return true;   //recur for checking in left and right subtree
    else
        return false;
}
// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
    if(root==NULL) 
        return true;
            
    return areMirror(root->left , root->right);
}