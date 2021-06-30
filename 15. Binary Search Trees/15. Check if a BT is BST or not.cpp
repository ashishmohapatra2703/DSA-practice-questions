/////////      M-1   T.C = O(n²)
/* Check for each node in the given BT, if 
   1) node Data > InorderPredessor Data
   2) node Data < InorderSuccessor Data  */



/////////      M-2   T.C = O(n)
/*• check if inorder traversal, is sorted/ strictly increasing or not (S.C = O(n) for storing inOT)
  • better -
    while traversing inorder, check current Node value with the previous node value (static for the BT)
    keeping a static bool isBST. Finally return it. (We check this for all nodes in tree) */

//wrong method -- BEWARE
class Solution{
private: 
    void InorderCheckBST(Node* currNode, int &prevNodeData, bool &isBST)
    {
        if(currNode==NULL)
            return;
        
        InorderCheckBST(currNode->left, prevNodeData, isBST);
        if(prevNodeData >= currNode->data)
            isBST = false;
        prevNodeData = currNode->data;
        InorderCheckBST(currNode->right, prevNodeData, isBST);
    }
public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        bool isBST = true;
        int prevNodeData = INT_MIN;
        InorderCheckBST(root, prevNodeData, isBST);
        return isBST;
    }
};/* here if Input = [-2147483648] or [INT_MIN] , a single node only  
Expected Output = true
    My Output = false  :(       */

//take prevNode rather than prevNodeData for checking
class Solution{
private: 
    void InorderCheckBST(Node* currNode, Node* &prevNode, bool &isBST)
    {
        if(currNode==NULL)
            return;
        
        InorderCheckBST(currNode->left, prevNode, isBST);
        if(prevNode)
        {
            if(prevNode->data >= currNode->data)
                isBST = false;
        }
        prevNode = currNode;
        InorderCheckBST(currNode->right, prevNode, isBST);
    }
public:
    bool isBST(Node* root) 
    {
        bool isBST = true;
        Node* prevNode = NULL;
        InorderCheckBST(root, prevNode, isBST);
        return isBST;
    }
};

//another style of code (without keeping a static bool isBST)
//(same M-2 algo.)
class Solution {
private: 
    bool InorderCheckBST(TreeNode* currNode, TreeNode* &prevNode)
    {
        if(currNode==NULL)
            return true;
        
        bool check1 = InorderCheckBST(currNode->left, prevNode);
        bool check2 = (prevNode!=NULL) ? (prevNode->val < currNode->val) : true;
        prevNode = currNode;
        bool check3 = InorderCheckBST(currNode->right, prevNode);
        
        return check1 && check2 && check3;
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        TreeNode* prevNode = NULL;
        return InorderCheckBST(root, prevNode);
    }
};




/////////      M-3
/*  One compares the node value with its upper and lower limits if they are available. 
  Then one repeats the same step recursively for left and right subtrees. */

//wrong method -- BEWARE
class Solution{
private: 
    bool validateBST(Node* currNode, int minLmt, int maxLmt)
    {
        if(currNode==NULL)
            return true;
        if(minLmt > maxLmt)
            return false;
        if(currNode->data < minLmt or currNode->data > maxLmt)
            return false;
        
        return validateBST(currNode->left, minLmt, currNode->data-1) and 
               validateBST(currNode->right, currNode->data+1, maxLmt);      //BST Allow only distinct values
    }
public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return validateBST(root, INT_MIN, INT_MAX);
    }
};
//only fails, if Input = [2147483647] or [INT_MAX] , a single node only
// int overflow occurs / segmentation fault ! (run time error) 


////to check for this , use 'long' instead of int for the limits variables (Follow this :) )
/* and Let us suppose value of node is 12, interval is [12,12]
In this case, when we call left subtree, it will be [12,11] and for right, it will be [13,12].
In this case, this condition is required ~ if(minLmt > maxLmt) return false;*/
class Solution {
private: 
    bool validateBST(TreeNode* currNode, long minLmt, long maxLmt)
    {
        if(currNode==NULL)
            return true;
        if(minLmt > maxLmt)
            return false;
        if(currNode->val < minLmt or currNode->val > maxLmt)
            return false;
        
        return validateBST(currNode->left, minLmt, (long)currNode->val-1) and 
               validateBST(currNode->right, (long)currNode->val+1, maxLmt); //The left and right subtree must also be valid
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
};

//another style of code
class Solution {
private: 
    bool validateBST(TreeNode* currNode, TreeNode* minLmtNode, TreeNode* maxLmtNode)
    {
        if(currNode==NULL)
            return true;
        if( (minLmtNode!=NULL and currNode->val <= minLmtNode->val) or
            (maxLmtNode!=NULL and currNode->val >= maxLmtNode->val) )
             return false;
        
        return validateBST(currNode->left, minLmtNode, currNode) and 
               validateBST(currNode->right, currNode, maxLmtNode);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        return validateBST(root, NULL, NULL);
    }
};