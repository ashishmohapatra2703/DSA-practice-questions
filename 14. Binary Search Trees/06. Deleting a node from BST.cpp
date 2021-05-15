/*Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. 
If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.
Example 2:

Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
X = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after
deleting 9 will be
             1
              \
               2
                 \
                  8
                 /   \
                5     11
               /  \     \
              4    7     12                  */

int HeightofSubTree(Node* p)
{
    if(p == NULL)
        return 0;
        
    int l = HeightofSubTree(p->left);
    int r = HeightofSubTree(p->right);
    return max(l,r)+1;
}
Node* InorderSuccessor(Node* p)
{
    while(p->left != NULL)
    {
        p = p->left;
    }
    return p;
}
Node* InorderPredessor(Node* p)
{
    while(p->right != NULL)
    {
        p = p->right;
    }
    return p;
}
// Return the root of the modified BST after deleting the node with value X
Node* deleteNode(Node *root,  int X)
{
    if(root == NULL) //if any node with data X is found
        return NULL;
    if(root->data == X && root->left == NULL && root->right == NULL) //No child //if leaf node is to be deleted
    {
        delete root;
        return NULL;
    }
    
    
    if(X < root->data)
        root->left = deleteNode(root->left, X);
    else if(X > root->data)
        root->right = deleteNode(root->right, X);
    else if(X == root->data)
    {
        if(HeightofSubTree(root->right) > HeightofSubTree(root->left))
        {
            root->data = (InorderSuccessor(root->right))->data;
            root->right = deleteNode(root->right, (InorderSuccessor(root->right))->data); 
        }
        else if(HeightofSubTree(root->right) <= HeightofSubTree(root->left))
        {
            root->data = (InorderPredessor(root->left))->data;
            root->left = deleteNode(root->left, (InorderPredessor(root->left))->data); 
        }
        return root;
    }
}
// We can replace the Node to be Deleted with either InorderPredessor data OR InorderSuccessor data.
// OR else Make any condition which one to choose 