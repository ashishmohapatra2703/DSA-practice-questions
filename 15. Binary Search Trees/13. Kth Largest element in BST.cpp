/*Given a Binary search tree. Your task is to complete the function which will 
return the Kth largest element without doing any modification in Binary Search Tree.
Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Input:
       9
        \ 
          10
K = 1
Output: 10*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution{
public:
    void reverseInorderTraversalUptoKth(Node* root, int &K, int &kthLargestEle)
    {
        if(root==NULL)
            return;
        if(K < 0)
            return;
            
        reverseInorderTraversalUptoKth(root->right, K, kthLargestEle);
        K--;
        if(K==0)
        {
            kthLargestEle = root->data;
            return;
        }
        reverseInorderTraversalUptoKth(root->left, K, kthLargestEle);
    }
    
    int kthLargest(Node *root, int K)
    {
        int kthLargestEle = -1; //if no such element exists, return -1
        reverseInorderTraversalUptoKth(root, K, kthLargestEle);
        return kthLargestEle;
    }
};