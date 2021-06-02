/*Example:
Input:
2
2
1 2 L 1 -1 N
6
1 2 L 1 3 R 2 -1 N 2 -1 N 3 3 L 3 -1 N
Output:
3
9 */

long int sumBT(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL) //base condition for checking if_leaf_node
        return root->key;
        
    long LsubTreeSum = sumBT(root->left);
    long RsubTreeSum = sumBT(root->right);
    
    return LsubTreeSum + root->key + RsubTreeSum;
}