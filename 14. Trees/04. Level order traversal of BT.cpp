/*  Given a binary tree, find its level order traversal.
  Level order traversal of a tree is breadth-first traversal for the tree.
Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N      */

class Solution{
public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)   //Node* root is passed in function call
    {
        if(node == NULL)
            return {};
            
        vector<int> LOT;
        queue<Node*> q;

        q.emplace(node); //first push the root        
        while(! q.empty())
        {
            Node* temp = q.front();
            q.pop();
            LOT.push_back(temp->data);
            
            if(temp->left != nullptr)
                q.emplace(temp->left);
            
            if(temp->right != nullptr)
                q.emplace(temp->right);
        }
        return LOT;
    }
};


/***********     If asked for LOT to store line by line/ level by level    ***********/
/* For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $.

          1
       /     \
     2        3
   /   \      /  \
  4     5    6    7
   \
    8 
vector<vector<int>> LOT = { {1}, {2,3}, {4,5,6,7}, {8} }           */

vector<vector<int>> levelOrder(Node* node)
{
    if(node == NULL)
        return {};
            
    vector<vector<int>> LOT;
    queue<Node*> q;

    q.push(node); //first push the root
    while(! q.empty())
    {
        int levelWidth = q.size();
        vector<int> levelNodes(levelWidth);
        
        for(int i=0; i<levelWidth; i++) //traversing horizontally nodes at each level
        {
            Node* temp = q.front();
            q.pop();
            levelNodes[i] = temp->data; // or can use push_back to vector<int> levelNodes
                
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
        LOT.push_back(levelNodes);
    }
    return LOT;
}



///// Similar Question using LOT ---  Max Level Sum in a BT
/* Given a Binary Tree having positive and negative nodes. 
Find the maximum sum of a level in the given Binary Tree.
Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6

Output: 6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6          */

class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) 
    {
        if(root == NULL)
            return -1;
            
        int maxLevelSum = INT_MIN;
        queue<Node*> q;
    
        q.push(root); //first push the root
        while(! q.empty())
        {
            int levelWidth = q.size();
            int LevelSum = 0;
            
            for(int i=0; i<levelWidth; i++) //traversing horizontally nodes at each level
            {
                Node* temp = q.front();
                q.pop();
                LevelSum += temp->data;
                    
                if(temp->left != nullptr)
                    q.push(temp->left);
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
            maxLevelSum = max(maxLevelSum, LevelSum);
        }
        return maxLevelSum;
    }
};


//// Similar Question using LOT --  Find Level with Maximum width/ Max. horizontal nodes
/* Given a Binary tree. 
Find the level in binary tree which has the maximum number of nodes.
Input:
      2
    /    \ 
   1      3
 /   \     \
4    6      8
     / 
    5
Output: 2
Explanation: The level 2 with nodes 4, 6 and 8 is the level with maximum number of nodes.  */

// Return the level (0-indexed) with maximum number of nodes.
int maxNodeLevel(Node *root)
{
    if(root == NULL)
        return -1;
            
    queue<Node*> q;
    
    q.push(root); //first push the root
    int level = 0;
    int maxWidth = 0;
    int maxWidthLevel = -1;
    
    while(! q.empty())
    {
        int levelWidth = q.size();
        if(levelWidth > maxWidth)
        {
            maxWidth = levelWidth;
            maxWidthLevel = level;
        }
        
        for(int i=0; i<levelWidth; i++) //traversing horizontally nodes at each level
        {
            Node* temp = q.front();
            q.pop();
                
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        level++;
    }    
    return maxWidthLevel;
    //return maxWidth; //if asked maximum width of BT
}



//// Similar Question using LOT --  depth of the deepest odd level leaf
/* Given a binary tree, find the depth of the deepest odd level leaf node in a binary tree. 
If there is no leaf at odd level then return 0.
Consider that level starts with 1.
Depth of a leaf node is number of nodes on the path from root to leaf (including both leaf and root).
Input: 
          1
        /    \
       2      3
      / \    / \
     4   5  6   7
Output: 3
Explanation: In the above tree 4,5,6 and 7 are odd level leaf nodes at depth 3.So the answer is 3. */
//M-1
class Solution{
public:
    int depthOfOddLeaf(Node *root)
    {
        queue<Node*> q;
        int depthofOddLevelLeaf = 0;
        int depthofDeepestOddLevelLeaf = 0;
        
        q.push(root); //first push the root
        int level = 1;
        while(! q.empty())
        {
            int levelWidth = q.size();
            
            for(int i=0; i<levelWidth; i++) //traversing horizontally nodes at each level
            {
                Node* temp = q.front();
                q.pop();
                    
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
                if(temp->left == NULL && temp->right == NULL && level%2 != 0)
                {
                    depthofOddLevelLeaf = level;
                    depthofDeepestOddLevelLeaf = max(depthofDeepestOddLevelLeaf, depthofOddLevelLeaf);
                }
            }
            level++;
        }    
        return depthofDeepestOddLevelLeaf;
    }
};
//M-2 -- using DFS
class Solution{
    void depthCal(Node *root, int level, int &res)
    {
        if(root)
        {
            if(root->left == NULL and root->right == NULL and level % 2 == 1)
            {
                res = max(res, level);
            }
            
            depthCal(root->left,  level + 1, res);
            depthCal(root->right, level + 1, res);
        }
    }
    public:
    int depthOfOddLeaf(Node *root)
    {
        int level = 1;
        int res   = 0;
        depthCal(root, level, res);
        return res;
    }
};