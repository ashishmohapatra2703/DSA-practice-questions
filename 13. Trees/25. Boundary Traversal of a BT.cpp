/*Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node 
					ie- the leaf node you could reach when you always travel preferring the left subtree 
					over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. 
					The right-most node is the leaf node you could reach when you always travel
					preferring the right subtree over the left subtree. 
					Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 - 8 4 - 10 14 25 - 22 */

class Solution {
public:
    void LeftBoundaryNodes(Node* root, vector<int> &BT)
    {
        if(root==NULL)
            return;
        
        if(root->left!=NULL || root->right!=NULL) //if not leaf node
            BT.push_back(root->data);
            
        if(root->left)
            LeftBoundaryNodes(root->left, BT);
        else if(root->right)
            LeftBoundaryNodes(root->right, BT);
    }
    void LeafNodes(Node* root, vector<int> &BT) // *****can be done through ANY DFS (Pre/In/Post)****
    {
        if(root==NULL)
            return;
        
        LeafNodes(root->left, BT);
        if(root->left==NULL && root->right==NULL) //if leaf node
            BT.push_back(root->data); 
        LeafNodes(root->right, BT);
    }
    void RightBoundaryNodes(Node* root, vector<int> &BT) //in reverse/bottom-up manner
    {
        if(root==NULL)
            return;
        
        if(root->right)
            RightBoundaryNodes(root->right, BT);
        else if(root->left)
            RightBoundaryNodes(root->left, BT);
        
        if(root->left!=NULL || root->right!=NULL) //if not leaf node
            BT.push_back(root->data);
    }
    
    vector<int> printBoundary(Node *root)
    {
        if(root == NULL)
            return {};
            
        vector<int> BT;
        BT.push_back(root->data);
        
        if(root->left==NULL && root->right==NULL) //if only 1 node present
            return BT; //return it in base condition , so that it won't be counted again in finding leaf Nodes function
        
        LeftBoundaryNodes(root->left, BT);
        LeafNodes(root, BT);
        RightBoundaryNodes(root->right, BT);
        return BT;
    }
};



 /* 1) The root node - The root node will always be our first node in the whole boundary traversal.
 
2) The left boundary - The left most nodes of the left subtree are also included in the boundary traversal /in top-down manner, 
so we will process them next except for the leaf node as it will be processed in our next part. 
We can use recursion for this and traverse for only left child until a leaf node is encountered.
 If the left child is not present we recurse for the right child.
 
3) The leaf Nodes - The leaf nodes of the binary tree will be processed next. 
We can use a simple inorder traversal for that. 
Inorder traversal will make sure that we process leaf nodes from left to right.
 
4) The right boundary - The right most nodes of the right subtree will be processed at last in reverse order except for the leaf node 
as it is already processed in the previous part. For this, we can use recursion in a postorder manner and 
traverse for the right child only until we encounter a leaf node. If the right child is not present we will recurse for the left child. 
The postorder recursion will make sure that we traverse the right boundary in reverse order/ bottom-up manner. */

