/* Given a BST and an integer K. Find the Kth Smallest element in the BST. 
Input:
      2
    /   \
   1     3
K = 2
Output: 2

Input:
        2
      /  \
     1    3
K = 5
Output: -1 		*/

//T.C = O(N) worst case at skewed BST condition
class Solution{
  public:
    void inorderTraversalUptoKth(Node* root, int &K, int &kthSmallestEle)
    {
        if(root==NULL)
            return;
        if(K < 0)
            return;
            
        inorderTraversalUptoKth(root->left, K, kthSmallestEle);
        K--;
        if(K==0)
        {
            kthSmallestEle = root->data;
            return;
        }
        inorderTraversalUptoKth(root->right, K, kthSmallestEle);
    }
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int K)
    {
        int kthSmallestEle = -1; //if no such element exists, return -1
        inorderTraversalUptoKth(root, K, kthSmallestEle);
        return kthSmallestEle;
    }
};
