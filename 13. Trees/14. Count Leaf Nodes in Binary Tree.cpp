/*nput:
2
3 4 2 
4 8 10 7 N 5 1 3 
Output:
2
3
Explanation:
Test Case 2:  Given Tree is 
                                 4
                               /     \
                            8       10
                          /          / \
                       7           5     1
                      /
                     3
Three leaves are 3 , 5 and 1.                */
int countLeaves(Node* root)
{
    if(root == nullptr)
        return 0;
    
    int l = countLeaves(root->left);
    int r = countLeaves(root->right);
    
    if(root->left == nullptr && root->right == nullptr)
        return l+r+1;
    else
        return l+r;
}