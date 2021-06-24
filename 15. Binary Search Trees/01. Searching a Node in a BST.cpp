/*Given a Binary Search Tree and a node value X, 
find if node with value X is present in the BST or not. 

Input:
         2
          \
          81
        /    \
      42      87
    /   \       \
   45   66      90
x = 87
Output: 1
Explanation: As 87 is present in the given nodes , so the output will be 1.   */
//Expected Time Complexity: O(Height of the BST)
//Expected Auxiliary Space: O(1).

//Function to search a node in BST.
bool search(Node* root, int x)
{
    if(root == NULL)
        return false;
        
    if(x == root->data)
        return true;
    if(x < root->data)
        return search(root->left, x);
    else if(x > root->data)
        return search(root->right, x);
}
