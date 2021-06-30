/* Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST).
[ 	Height balanced BST means a binary tree in which the depth of the 
	two subtrees of every node never differ by more than 1. ]

Input: nums = {1, 2, 3, 4}
Output: {3, 2, 1, 4}
Explanation: 
The preorder traversal of the following 
BST formed is {3, 2, 1, 4}:
     3
    /  \
   2    4
 /
1 			*/

//M-1
class Solution{
private:
    class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data)
        {
            this->data = data;
            left = right = NULL;
        }
    };
public:
    void preorderT(Node* root, vector<int> &preOT)
    {
        if(root==NULL)
            return;
        
        preOT.push_back(root->data);
        preorderT(root->left, preOT);
        preorderT(root->right, preOT);
    }
    
    //Algo.: make the middle element as root and recursively build left and right subtree.
    Node* buildBST(vector<int> &nums, int low, int high)
    {
        if(low>high)
            return NULL;
            
        int mid = (low+high)/2;
        Node* root = new Node(nums[mid]);
        
        root->left = buildBST(nums, low, mid-1);
        root->right = buildBST(nums, mid+1, high);
        return root;
    }

    vector<int> sortedArrayToBST(vector<int>& nums) //nums[] = inOT (sorted array)
    {
        int low = 0;
        int high = nums.size()-1;
        Node* BSTroot = buildBST(nums, low, high);
        
        vector<int> preOT;
        preorderT(BSTroot, preOT);
        return preOT; //returns the preorder traversal of height balanced BST.
    }
};



//M-2 Better :)
class Solution {
public:
    void buildBST(vector<int> &nums, int low, int high, vector<int> &preOT)
    {
        if(low>high)
            return;
            
        int mid = (low+high)/2;
        preOT.push_back(nums[mid]); //preOT ~ Node-L-R    inOT ~ L-Node-R
        
        buildBST(nums, low, mid-1, preOT);
        buildBST(nums, mid+1, high, preOT);
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) //nums[] = inOT (sorted array)
    {
        int low = 0;
        int high = nums.size()-1;
        
        vector<int> preOT;
        buildBST(nums, low, high, preOT);
        return preOT;
    }
};