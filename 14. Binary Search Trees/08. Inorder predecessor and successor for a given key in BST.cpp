void findPreSuc(Node* root, Node* &pre, Node* &suc, int key)
{
    if(root == NULL)
        return;
        
    if(key < root->key) //if key < current root value(that may be answer/ root may be Successor)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key); //we than traverse towards left subtree
    }
    else if(key > root->key)//if key > current root value(that may be answer/ root may be Predecessor)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key); //we than traverse towards right subtree
    }
    else if(key == root->key)
    {
        if(root->left) //validation
        {
            pre = root->left;
            while(pre->right != NULL)
            {
                pre = pre->right;
            }
        }
        
        if(root->right)
        {
            suc = root->right;
            while(suc->left != NULL)
            {
                suc = suc->left;
            }
        }
    }
}
/*
Input: root node, key
output: predecessor node, successor node

1. If root is NULL
      then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most 
        child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child 
        of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree */