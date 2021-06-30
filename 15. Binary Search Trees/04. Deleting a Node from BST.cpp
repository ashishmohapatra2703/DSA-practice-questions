/*Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. 
If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.
Example 2:

Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
X = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after
deleting 9 will be
             1
              \
               2
                 \
                  8
                 /   \
                5     11
               /  \     \
              4    7     12                  */

class Solution {
private:
    int HeightofTree(TreeNode* node)
    {
        if(node == NULL)
            return 0;

        return 1 + max( HeightofTree(node->left) , HeightofTree(node->right) );
    }
    TreeNode* InorderPredessor(TreeNode* node)
    {
        node = node->left;
        while(node->right != NULL)
        {
            node = node->right;
        }
        return node;
    }
    TreeNode* InorderSuccessor(TreeNode* node)
    {
        node = node->right;
        while(node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return NULL;
        

        if(key == root->val)
        {
            if(root->left==NULL and root->right==NULL) //0 child 
                return NULL;  //delete node from tree
            
            else if(root->left!=NULL and root->right==NULL) //1 child
                return root = root->left;
            else if(root->left==NULL and root->right!=NULL)
                return root = root->right;
            
            else if(root->left!=NULL and root->right!=NULL) //2 child
            {
                // We can replace the Node to be Deleted with 
                // either InorderPredessor data OR InorderSuccessor data.
                // OR else Make any condition which one to choose 
                int LsubTreeHeight = HeightofTree(root->left);
                int RsubTreeHeight = HeightofTree(root->right);
                if(LsubTreeHeight >= RsubTreeHeight)
                {
                    TreeNode* inOPredecessor = InorderPredessor(root);
                    root->val = inOPredecessor->val;
                    
                    root->left = deleteNode(root->left, inOPredecessor->val);
                }
                else if(LsubTreeHeight < RsubTreeHeight)
                {
                    TreeNode* inOSuccessor = InorderSuccessor(root);
                    root->val = inOSuccessor->val;
                    
                    root->right = deleteNode(root->right, inOSuccessor->val);
                }
                return root;
            }
        }
        
        else if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        
        return root;
    }
};

/* 3 possibilities :-
• Node to be deleted is leaf: 
    Simply remove from the tree.

• Node to be deleted has only one child: 
    Copy the child to the node and delete the child

• Node to be deleted has two children: 
    Find inorder successor of the node. (which indeed have 1 child/ 0 child)
    Copy contents of the inorder successor to the node and delete the inorder successor. 
    Note that inorder predecessor can also be used.     */