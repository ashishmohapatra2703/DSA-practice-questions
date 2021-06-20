/*Given a binary tree, find its minimum depth.
Input:
            1
          /   \
         3     2
        /
       4           
Output: 2
Explanation: Minimum depth is between nodes 1 and 2 since minimum depth is defined as  
the number of nodes along the shortest path from the root node down to the nearest leaf node.

Input:
             10
          /     \
        20       30
          \        \   
          40        60 
                   /
                  2 
Output: 3
Explanation: Minimum depth is between nodes 10,20 and 40. */

class Solution{
  public:
    /*You are required to complete this method*/
    int minDepth(Node *root) 
    {
        if(root == NULL)
            return 0;
        
        int LsubTreeHeight = minDepth(root->left);
        int RsubTreeHeight = minDepth(root->right);
        
        if(LsubTreeHeight == 0)
            return 1+RsubTreeHeight;
        else if(RsubTreeHeight == 0)
            return 1+LsubTreeHeight;
        else
            return 1 + min(LsubTreeHeight , RsubTreeHeight);
    }
};
