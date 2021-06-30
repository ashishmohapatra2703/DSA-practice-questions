/*Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4 Inorder traversal of the above treewill be 1 2 3 4 6.
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).

The function returns the root of the BST (currently rooted at 'root') 
after inserting a new Node with value 'Key' into it.  */

//Function to insert a node in a BST.
Node* insert(Node* root, int Key)
{
    if(root == NULL)
    {
        return new Node(Key);
    }

    if(Key == root->data)
        return root; //return the (unchanged) node pointer
    else if(Key < root->data)
        root->left = insert(root->left, Key);
    else if(Key > root->data)
        root->right = insert(root->right, Key);

    return root;
}
//A new key is always inserted at leaf node's child