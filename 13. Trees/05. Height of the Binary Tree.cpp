// return the Height of the given Binary Tree
int height(Node* root)
{
    int l=0,r=0;
    if(root != 0)
    {
        l = height(root->left);
        r =  height(root->right);
        if(l > r)
            return l+1;
        else
            return r+1;
    }
    return 0;
}