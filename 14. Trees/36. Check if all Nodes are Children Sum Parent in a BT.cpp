//Similar to "Check if a BT is Sum Tree" question

/*Given a Binary Tree. Check whether For every node, 
data value must be equal to sum of data values in left and right children. 
Consider data value as 0 for NULL children.
Input:
        10
     /     \
    8       2
   / \     /
  3   5   2 
Output: 1         */

int ParentAsChildSum(Node* root, bool &isSum)
{
    if(root == NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
        
    int LchildData = ParentAsChildSum(root->left, isSum);
    int RchildData = ParentAsChildSum(root->right, isSum);
        
    if(root->data != LchildData + RchildData)
        isSum = false;
        
    return root->data; //changed this 1 line from "Check if a BT is Sum Tree" problem
}
//Function to check whether all nodes of a tree have the value 
//equal to the sum of their child nodes.
int isSumProperty(Node *root)
{
    bool isSum = true;
    ParentAsChildSum(root, isSum);
    return isSum;
}