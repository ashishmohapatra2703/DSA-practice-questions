
int height(Node* p)
{
    if(p == nullptr)
        return 0;
        
    int l = height(p->left);
    int r = height(p->right);
    return max(l,r)+1;
}
// This function should return tree if passed tree  is balanced, else false. 
bool isBalanced(Node *root)
{
    if(root == nullptr)
        return true;
        
    int lh = height(root->left); //LeftsubTreeHeight
    int rh = height(root->right); //RightsubTreeHeight
    
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

//if a binary tree is balanced. -->

// 1) An empty tree is height-balanced. 
// A non-empty binary tree T is balanced if:
// 2) Left subtree of T is balanced
// 3) Right subtree of T is balanced
// 4) The difference between heights of left subtree and right subtree is not more than 1.
