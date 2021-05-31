// Function problem on gfg

int solve(Node *p, int &res)
{
    if(p == nullptr)
        return 0;

    int l = solve(p->left, res);
    int r = solve(p->right, res);
    
    int temp = max((max(l,r)+p->data) , p->data);
    
    int ans = max(temp , l+r+p->data);
    res = max(res, ans);
    
    return temp;
}
// This function should returns sum of
// maximum sum path from any node in
// a tree rooted with given root.

int findMaxSum(Node* root)
{
    int result = INT_MIN;
    solve(root, result);
    return result;
}
