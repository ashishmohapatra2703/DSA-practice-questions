/*Given a Binary Tree, find the maximum sum path from a leaf to root. 
For example, in the following tree, there are three leaf to root paths
 8->-2->10, -4->-2->10 and 7->10. 
 The sums of these three paths are 16, 4 and 17 respectively.
  The maximum of them is 17 and the path for maximum is 7->10.
                 10
               /    \
             -2      7
            /   \     
           8    -4 				 */

void maxRootToPathSum(Node* root, int curr_sum, int &max)
{
    if(root==NULL)
        return;
        
    curr_sum += root->data;
    if(root->left==NULL && root->right==NULL && curr_sum>max) //at a leaf node
    {
        max = curr_sum;
    }
           
    maxRootToPathSum(root->left, curr_sum, max);
    maxRootToPathSum(root->right, curr_sum, max);
}
bool maxSum(Node *root) 
{
    int curr_sum = 0;
    int maxSum = INT_MIN;
        
    maxRootToPathSum(root, curr_sum, maxSum);
        
    return maxSum;
}