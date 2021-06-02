/* Given a Binary Tree of size N , where each node can have positive or negative values. 
Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. 
The values of leaf nodes are changed to 0.  [ Modification of the given tree in-place ]
Input: 
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5
Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0
Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree) */

class Solution {
public:
    int tranformToSumT(Node* root)
    {
        if(root == NULL)
            return 0;
        
        int originalNodeData = root->data;
        int LsubTreeSum = tranformToSumT(root->left);
        int RsubTreeSum = tranformToSumT(root->right);
        
        root->data = LsubTreeSum + RsubTreeSum; //root will show -> what it can get from its below L and R
        
        return originalNodeData + LsubTreeSum + RsubTreeSum; //telling the caller that this is what we can manage as an entire tree:
        //OR return originalNodeData + root->data;
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        tranformToSumT(node);
    }
};