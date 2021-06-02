/*Given a Binary Tree, find diameter of it.
The diameter of a tree is the 
number of nodes on the longest path between any two nodes in the tree. */

class Solution
{
    public:
    int heightHelper(Node* root, int &diameter)
    {
        if(root == NULL)
            return 0;
            
        int LsubTreeHeight = heightHelper(root->left, diameter);
        int RsubTreeHeight = heightHelper(root->right, diameter);
        
        diameter = max(diameter , 1+ LsubTreeHeight+ RsubTreeHeight);
            
        return 1 + max(LsubTreeHeight,RsubTreeHeight);
    }
    //Function to return the diameter of a Binary Tree.
    int diameter(Node* root)
    {
        int diameterofBT = INT_MIN;
        heightHelper(root, diameterofBT);
        return diameterofBT;
    }
};
/* why we return height here????
-- for finding the diameter we want left and right heights.
Also we can find the height of tree, if we know the heights of left and right child.
But we can't directly tell the diameter of tree, even if we know thr diameter of left and right child */


// M-2
/*int solve(Node* root, int &res)
{
    if (root == nullptr)
        return 0;
    
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    
    int temp = 1 + max(l,r);
    
    int ans = max(temp , 1+l+r);
    res = max(res , ans);
    
    return temp;
}

// Computes the diameter of binary tree with given root.  
int diameter(Node* node) 
{
    int result = INT_MIN;
    solve(node, result);
    return result;
} */