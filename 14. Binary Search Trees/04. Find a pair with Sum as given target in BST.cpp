/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
void InorderArray(struct Node* root, vector<int> &A)
{
    if(root==nullptr)
        return;
    
    InorderArray(root->left, A);
    A.push_back(root->data);
    InorderArray(root->right, A);
}
// root : the root Node of the given BST
// target : the target sum
bool isPairPresent(struct Node *root, int target)
{
    vector<int> A;
    InorderArray(root, A);
    
    int n = A.size();
    for(int i=0,j=n-1 ; i<j;  ) // A array is SORTED
    {
        if(A[i]+A[j]==target)
            return true;
        else if(A[i]+A[j]<target)
            i++;
        else //if(A[i]+A[j]>target)
            j--;
    }
    return false;
}