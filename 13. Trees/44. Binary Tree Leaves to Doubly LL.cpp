/* Given a Binary Tree of size N, 
extract all its leaf nodes to form a Doubly Link List strating from the left most leaf. 
Modify the original tree to make the DLL thus removing the leaf nodes from the tree. 
Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :       and        
        1
      /   \                  Doubly Link List : 
     2     3                 4 <-> 5 <-> 6 <-> 7
Explanation: 
The leaf nodes are modified to form the DLL in-place. Thus their links are removed from the tree. */

void addToDLL(Node* &root, Node* &head, Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        head = tail = root;   
    }
    else
    {
        root->left = tail;
        tail->right = root;
        tail = root;
    }
}
Node* BTLeavestoDLL(Node* root, Node* &head, Node* &tail)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL) //if leaf node
    {
        addToDLL(root, head, tail);
        return NULL; //breaking the link from its parent tree node
    }
        
    root->left = BTLeavestoDLL(root->left, head, tail);
    root->right = BTLeavestoDLL(root->right, head, tail);
    return root;
}
// return the head of the DLL and remove those node from the tree as well.
Node* convertToDLL(Node *root)
{
    Node* head = NULL;
    Node* tail = NULL;
    BTLeavestoDLL(root, head, tail);
    return head;
}