// Function problem on gfg

//Not passed 
int solve(Node *p, int &res)
{
    if(p == nullptr)
        return 0;
    if(p->left == nullptr && p->right == nullptr)
        return p->data;
    
    int l = solve(p->left, res);
    int r = solve(p->right, res);
    
    int temp;
    if(p->left == nullptr && p->right == nullptr) //if leaf node
        temp = max((max(l,r)+p->data) , p->data);
    else
        temp = max(l,r)+p->data;
    
    int ans = max(temp , l+r+p->data);
    res = max(res, ans);
    
    return temp;
}

int maxPathSum(Node* root)
{
    int result = INT_MIN;
    solve(root, result);
    return result;
}

/*
int solve(Node* root,int &answer) {
    
    if(root == NULL) {
        return 0;
    }
    
    if(root -> left == NULL && root -> right == NULL) {
        return root -> data;
    }
    
    if(root -> left == NULL) {
        return (solve(root -> right,answer) + root -> data);
    }
    
    if(root -> right == NULL) {
        return (solve(root -> left,answer) + root -> data);
    }
    
    
    int ltsum = solve(root -> left,answer);
    int rtsum = solve(root -> right,answer);
    
    
    int temp = max(ltsum,rtsum) + root -> data;
    
    
    answer = max(answer,ltsum + rtsum + root -> data);
    
    return temp;
}
*/