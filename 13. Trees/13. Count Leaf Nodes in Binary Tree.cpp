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
    if(root == NULL)
        return 0;
    if(root->left == nullptr && root->right == nullptr) //base condition for checking if_leaf_node
        return 1;
        
    int LsubTreeLeafNodes = countLeaves(root->left);
    int RsubTreeLeafNodes = countLeaves(root->right);
    return LsubTreeLeafNodes + RsubTreeLeafNodes;
}
