/*Given a Binary Search Tree (with all values unique) and two node values. 
Find the Lowest Common Ancestors of the two nodes in the BST.
Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7

Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2 		*/

//M-1 	T.C = O(N)    ~ same as LCA of 2 nodes in a BT

//M-2   T.C = O(H)
//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
            
    if(n1<root->data && n2<root->data)
        return LCA(root->left, n1, n2);
    if(n1>root->data && n2>root->data) 
        return LCA(root->right, n1, n2);
    //else{ found any one of the 2 nodes as (root->data==n1 || root->data==n2)
    /*OR one lies in the left subtree and other in the right subtree
    i.e, (n1<root->data && n2>root->data) || (n2<root->data && n1>root->data)  }*/
    return root;
}
