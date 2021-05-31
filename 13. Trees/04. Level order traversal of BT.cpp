/*  Given a binary tree, find its level order traversal.
  Level order traversal of a tree is breadth-first traversal for the tree.
Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N      */

class Solution
{
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