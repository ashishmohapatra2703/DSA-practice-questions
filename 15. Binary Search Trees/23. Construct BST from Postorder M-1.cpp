/* if the given traversal is {1, 7, 5, 50, 40, 10}, 
then following tree should be constructed and root of the tree should be returned.
         10
       /   \
      5     40
     /  \      \
    1    7      50                */

Node* BuildBSTfromPost(Node* &root, int key)
{
    if(root == NULL)
        return root = new Node(key);
        
    if(key > root->data)
        root->right = BuildBSTfromPost(root->right, key);
    else if(key < root->data)
        root->left = BuildBSTfromPost(root->left, key);
    
    return root;
}

Node* constructTree (int post[], int size)
{
    Node* root = NULL;
    for(int i=size-1; i>=0; i--)    //L to R traversal if preorder[] given
        BuildBSTfromPost(root, post[i]);
    return root;
}
// t.c = O(n²)