/*Given the root of a Binary Search Tree (BST), 
convert it to a Greater Tree such that, every key of the original BST is changed to 
the "original key (plus) sum of all keys greater than the original key in BST".

Input: Root of following BST
               4
            /     \
           1        6
          /	\	   / \
         0   2    5   7
              \        \
               3        8
       
Output: The given BST is converted to following Binary Tree
               30
            /     \
           36      21
          /	\	   / \
        36   35   26  15
              \        \
               33       8	  */

class Solution {
public:
    void buildBSTtoGST(TreeNode* root, int &currSum)
    {
        if(root == NULL)
            return;
        
        buildBSTtoGST(root->right, currSum);
        currSum = currSum + root->data;
        root->data = currSum;
        buildBSTtoGST(root->left, currSum);
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        int currSum = 0;
        buildBSTtoGST(root, currSum); //using reverse-Inorder Traversal
        return root;
    }
};


//Similar Question --
/*if asked Given a BST, transform it into greater sum tree 
where each node contains "sum of all nodes greater than that node". 
Output would be : 
               26
            /     \
           35      15
          /	\	   / \
        36   33   21  8
              \        \
               30       0	  */

//only changes from the above program :-
        currSum = currSum + root->data;
        root->data = currSum - root->data;