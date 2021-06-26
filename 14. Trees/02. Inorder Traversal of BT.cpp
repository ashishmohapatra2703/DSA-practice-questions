/*Input:
        10
     /      \ 
    20       30 
  /    \    /
 40    60  50
Output: 40 20 60 10 50 30   */

//M-1 Recursive Way
void helper(Node* p, vector<int> &IOT) //pass by reference
{
    if(p == nullptr)
        return;
        
    helper(p->left, IOT);
    IOT.push_back(p->data);
    helper(p->right, IOT);
}
// Return a vector containing the inorder traversal of the tree
vector<int> inOrder(Node* root)
{
    vector<int> IOT;
    helper(root, IOT);
    return IOT;
}


//M-2 Iterative Way
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        vector<int> inOT;
        stack<pair<Node*, int>> s;
        
        s.push({root, 0});
        while(! s.empty())
        {
            pair<Node*, int> currPair = s.top();
            s.pop();
            Node* currNode = currPair.first;
            int currState = currPair.second;
            
            if(currNode==NULL or currState==3)
                continue;
            
            s.push({currNode, currState+1});
            
            if(currState==0)
                s.push({currNode->left, 0});
            else if(currState==1)
                inOT.push_back(currNode->data);
            else if(currState==2)
                s.push({currNode->right, 0});
        }
        return inOT;
    }
};