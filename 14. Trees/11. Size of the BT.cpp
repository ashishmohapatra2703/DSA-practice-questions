/*Given a binary tree of size N, you have to count number of nodes in it. 
For example, count of nodes in below tree is 4.
        1
     /    \
   10      39
  /
5 								*/

/* Computes the number of nodes in a tree. */
int getSize(Node* node)
{
    if(node == NULL)
        return 0;
        
    int LsubTreeSize = getSize(node->left);
    int RsubTreeSize = getSize(node->right);
    return 1 + LsubTreeSize + RsubTreeSize;
}