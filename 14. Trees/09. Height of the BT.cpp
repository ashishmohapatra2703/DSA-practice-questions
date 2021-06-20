// return the Height of the given Binary Tree
// height  = Max. Depth of B.T


int height(struct Node* node)
{
    if(node == NULL)
        return 0;
        
    int LsubTreeHeight = height(node->left);
    int RsubTreeHeight = height(node->right);
    return 1 + max(LsubTreeHeight , RsubTreeHeight);
}