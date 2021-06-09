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



///// Similar Question ---  Max Level Sum in a BT
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
