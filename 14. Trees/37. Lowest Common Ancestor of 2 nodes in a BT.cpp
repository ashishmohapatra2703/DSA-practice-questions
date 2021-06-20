/* Given a Binary Tree with all unique values and two nodes value n1 and n2. 
The task is to find the lowest common ancestor of the given two nodes. 
We may assume that either both n1 and n2 are present in the tree or none of them is present. 
Input:
n1 = 3 , n2 = 4
         5
        /
       2
     /  \
    3    4
Output: 2
Explanation: LCA of 3 and 4 is 2.  */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root == NULL)
            return NULL;
        if(root->data==n1 || root->data==n2) //base condition:- found any one of the 2 nodes
            return root;
            
        Node* inLSubT = lca(root->left, n1, n2);
        Node* inRSubT = lca(root->right, n1, n2);
        if(inLSubT!=NULL && inRSubT!=NULL)
            return root;
        if(inLSubT!=NULL)
            return inLSubT;
        else if(inRSubT!=NULL)
            return inRSubT;
        return NULL; //none of them are present
    }
};