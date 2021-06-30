/*Given a Binary Search Tree (BST) and a range l-h(inclusive), 
count the number of nodes in the BST that lie in the given range.
The values smaller than root go to the left side
The values greater and equal to the root go to the right side

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3       Explanation: 5 10 40 are the node in the range

Input:
     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the given range.    */

//M-1 simply counting
void countNodesinRange(Node* root, int &l, int &h, int &count)
{
    if(root==NULL)
        return;
    
    if(root->data >= l && root->data <= h)
        count++;
        
    countNodesinRange(root->left, l, h, count);
    countNodesinRange(root->right, l, h, count);
}
//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
    int count = 0;
    countNodesinRange(root, l, h, count);
    return count;
}


//M-2 efficient approach for BST
void countNodesinRange(Node* root, int &l, int &h, int &count)
{
    if(root==NULL)
        return;
    
    if(root->data>=l && root->data<=h)
        count++;
        
    if(root->data > l) //e.g, l=30 , h=60 and root->data=100 //only explore left subtree
        countNodesinRange(root->left, l, h, count);
    if(root->data < h)  //e.g, l=30 , h=60 and root->data=15 //only explore right subtree
        countNodesinRange(root->right, l, h, count);
}