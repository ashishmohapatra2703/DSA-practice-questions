
//Expected Time Complexity: O(Height of the BST)
//Expected Auxiliary Space: O(1).

bool search(Node* root, int x)
{
    if(root == NULL)
        return false;
    if(x == root->data)
        return true;
    
    if(x < root->data)
        search(root->left, x);
    else if(x > root->data)
        search(root->right, x);
}