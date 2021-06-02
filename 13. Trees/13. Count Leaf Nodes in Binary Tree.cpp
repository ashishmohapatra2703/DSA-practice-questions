/*Input:
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
    if(root->left == NULL && root->right == NULL) //base condition for checking if_leaf_node
        return 1;
        
    int LsubTreeLeafNodesCount = countLeaves(root->left);
    int RsubTreeLeafNodesCount = countLeaves(root->right);
    return LsubTreeLeafNodesCount + RsubTreeLeafNodesCount;
}



//Similar Question --
/* Return the sum of all the leaf nodes of the given binary tree of size N.*/

// function should return the sum of all the leaf nodes of the binary tree 
int sumLeaf(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL) //base condition for checking if_leaf_node
        return root->data;
        
    int LsubTreeLeafNodesSum = sumLeaf(root->left);
    int RsubTreeLeafNodesSum = sumLeaf(root->right);
    return LsubTreeLeafNodesSum + RsubTreeLeafNodesSum;
}