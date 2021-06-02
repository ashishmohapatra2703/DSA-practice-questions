/*Given a binary tree and an integer S, check whether there is root to leaf path with its sum as S.
Input: Tree = 
            1
          /   \
        2      3
S = 4

Output: 1
Explanation: The sum of path from leaf node 3 to root 1 is 4. */

class Solution{
public:
    void hasPathSumasS(Node* root, int curr_sum, int &S, bool &sumPathFound)
    {
        if(root==NULL)
            return;
        
        curr_sum += root->data;
        if(root->left==NULL && root->right==NULL && curr_sum==S) //at a leaf node
        {
            sumPathFound = true;
            return;
        }
            
        hasPathSumasS(root->left, curr_sum, S, sumPathFound);
        hasPathSumasS(root->right, curr_sum, S, sumPathFound);
    }
    bool hasPathSum(Node *root, int S) 
    {
        int curr_sum = 0;
        bool sumPathFound = false;
        
        hasPathSumasS(root, curr_sum, S, sumPathFound);
        
        return sumPathFound;
    }
};


// M-2  more space optimization 
// as curr_sum is also passed by reference, instead of passing by value
// by handling the returning phase after recursive calls
    void hasPathSumasS(Node* root, int &curr_sum, int &S, bool &sumPathFound)
    {
        if(root==NULL)
            return;
        
        curr_sum += root->data;
        if(curr_sum==S && root->left==NULL && root->right==NULL)
        {
            sumPathFound = true;
            return;
        }
            
        hasPathSumasS(root->left, curr_sum, S, sumPathFound);
        hasPathSumasS(root->right, curr_sum, S, sumPathFound);
        
        curr_sum -= root->data;
    }
