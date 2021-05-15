/*  Given a binary tree, find its level order traversal.
  Level order traversal of a tree is breadth-first traversal for the tree.
Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N      */

vector<int> levelOrder(Node* node)  //Node* root is passed in function call
{
    vector<int> LOT;
    queue<Node*> q;
    
    LOT.push_back(node->data);
    q.emplace(node);
    
    while(!q.empty())
    {
        Node* t = q.front();
        q.pop();
        
        if(t->left != nullptr)
        {
            LOT.push_back(t->left->data);
            q.emplace(t->left);
        }
        
        if(t->right != nullptr)
        {
            LOT.push_back(t->right->data);
            q.emplace(t->right);
        }
    }
    return LOT;
}