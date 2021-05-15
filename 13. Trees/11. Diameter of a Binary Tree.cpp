/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


int solve(Node* root, int &res)
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

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) 
{
    int result = INT_MIN;
    solve(node, result);
    return result;
}
