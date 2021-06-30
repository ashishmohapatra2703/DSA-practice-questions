/*Given a Binary Tree, find maximum and minimum elements in it.

Input: 
          70
        /    \
       60     80
      /  \    / 
     55  65  75 

Output: 80 55   */

class Solution{
public:
    int findMax(Node *root) //rightmost node
    {
        while(root->right != NULL)
            root = root->right;
            
        return root->data;
    }
    int findMin(Node *root) //leftmost node
    {
        while(root->left != NULL)
            root = root->left;
            
        return root->data;
    }
};