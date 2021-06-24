class Solution{
public:
    int findMax(Node *root)
    {
        if (root == nullptr)
            return INT_MIN;

        return max({root->data, findMax(root->left), findMax(root->right)});
    }
    int findMin(Node *root)
    {
        if (root == nullptr)
            return INT_MAX;

        return min({root->data, findMin(root->left), findMin(root->right)});
    }
};