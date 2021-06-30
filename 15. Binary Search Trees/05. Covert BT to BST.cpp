/* Given a Binary Tree, convert it to Binary Search Tree 
in such a way that keeps the original structure of Binary Tree intact.

Input:
          1
       /    \
     2       3
   /        
 4       
The converted BST will be

        3
      /   \
    2     4
  /
 1            */

class Solution{
  public:
    void inorderTraversal(Node* root, vector<int> &inOT)
    {
        if(root==NULL)
            return;
        
        inorderTraversal(root->left, inOT);
        inOT.push_back(root->data);
        inorderTraversal(root->right, inOT);
    }
    void buildBSTfromInorderT(Node* root, vector<int> &inOT, int &itr)
    {
        if(root==NULL)
            return;
        
        buildBSTfromInorderT(root->left, inOT, itr);
        root->data = inOT[itr];
        itr++;
        buildBSTfromInorderT(root->right, inOT, itr);
    }
    
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> inOT;
        inorderTraversal(root, inOT); //can collect all nodes from given BT using ANY traversal
        sort(inOT.begin(), inOT.end()); //sort them
        
        int itr=0;
        buildBSTfromInorderT(root, inOT, itr); //build BST from its inorder traversal
        return root;
    }
};

/* we traverse the binary tree by any traversal so that we get all the elements of the tree, 
then we sort the elements of binary tree, 
then we traverse the binary tree in inorder fashion and 
keep replacing the values we get after sorting. */