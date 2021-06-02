/* Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, 
its value is equal to the sum of its left subtree's value and its right subtree's value. 
Else return 0.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
A leaf node is also considered a Sum Tree.

Input:
    3
  /   \    
 1     2

Output: 1
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, 
which is the value of the root node. Therefore,the given binary tree is a sum tree.

Input:
          22
        /    \
      6       5
     / \     / \ 
    4   2   1   4

Output: 1     */

// M-1 Prefer this :)
// Should return true if tree is Sum Tree, else false
class Solution{
public:
    int SumTree(Node* root, bool &isSumT)
    {
        if(root == NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->data;
        
        int LsubTreeSum = SumTree(root->left, isSumT);
        int RsubTreeSum = SumTree(root->right, isSumT);
        
        if(root->data != LsubTreeSum + RsubTreeSum)
            isSumT = false;
        
        return LsubTreeSum + root->data + RsubTreeSum;
    }
    bool isSumTree(Node* root)
    {
        bool isSumT = true;
        SumTree(root, isSumT);
        return isSumT;
    }
};


//M-2 
class Solution{
public:
    int SumTree(Node* root)
    {
        if(root == NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->data;
        
        int LsubTreeSum = SumTree(root->left);
        if(LsubTreeSum == -1)
            return -1;
        int RsubTreeSum = SumTree(root->right);
        if(RsubTreeSum == -1)
            return -1;
        
        if(root->data != LsubTreeSum + RsubTreeSum)
            return -1;
        
        return LsubTreeSum + root->data + RsubTreeSum;
    }
    bool isSumTree(Node* root)
    {
        if(SumTree(root) == -1)
            return false;
        return true;
    }
};