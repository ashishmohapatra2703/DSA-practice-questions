/*Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees 
is not more than one for all nodes of tree. 

        1
     /     \
   10      39       <----- A height balanced tree
  /
5
        1
     /    
   10               <----- An unbalanced tree
  /
5                                           */

//M-1 tweaking the same height function
int heightHelper(Node* node, bool &isHBalancedBT)
{
    if(node == NULL)
        return 0;
        
    int LsubTreeHeight = heightHelper(node->left, isHBalancedBT);
    int RsubTreeHeight = heightHelper(node->right, isHBalancedBT);
    
    if(abs(LsubTreeHeight - RsubTreeHeight) > 1)
        isHBalancedBT = false;
        
    return 1 + max(LsubTreeHeight , RsubTreeHeight);
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    bool isHBalancedBT = true;
    heightHelper(root, isHBalancedBT);
    return isHBalancedBT;
}




//M-2 Using the fact that
/* if a binary tree is balanced. -->

1) An empty tree is height-balanced. 
A non-empty binary tree T is balanced if:
2) Left subtree of T is balanced
3) Right subtree of T is balanced
4) The difference between heights of left subtree and right subtree is not more than 1. */

int height(Node* node)
{
    if(node == nullptr)
        return 0;
        
    int LsubTreeHeight = height(node->left);
    int RsubTreeHeight = height(node->right);
    return 1 + max(LsubTreeHeight , RsubTreeHeight);
}
// This function should return tree if passed tree  is balanced, else false. 
bool isBalanced(Node *root)
{
    if(root == nullptr)
        return true;
        
    int lh = height(root->left); //LeftsubTreeHeight
    int rh = height(root->right); //RightsubTreeHeight
    
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}


