/* Given a Binary Search Tree(BST), convert it to a Binary Tree such that 
every key of the original BST is changed to "key (plus) sum of all smaller keys in BST". */

class Solution {
public:
    void buildBSTtoSST(TreeNode* root, int &currSum)
    {
        if(root == NULL)
            return;
        
        buildBSTtoSST(root->left, currSum);
        currSum = currSum + root->data;
        root->data = currSum;
        buildBSTtoSST(root->right, currSum);
    }
    TreeNode* bstToSst(TreeNode* root) 
    {
        int currSum = 0;
        buildBSTtoSST(root, currSum); //using Inorder Traversal
        return root;
    }
};
/* When a BST is being traversed in inorder, 
for every key currently being visited, 
all keys that are already visited are all smaller keys.  */