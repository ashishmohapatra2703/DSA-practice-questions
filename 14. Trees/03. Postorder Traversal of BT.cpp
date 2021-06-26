/*  Input: 19 10 8 11 13
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19  */

//M-1 Recursive Way
void helper(Node* p, vector<int> &PtOT) //pass by reference
{
    if(p == nullptr)
        return;
        
    helper(p->left, PtOT);
    helper(p->right, PtOT);
    PtOT.push_back(p->data);
}

vector<int> postOrder(Node* root)
{
    vector<int> PtOT;
    helper(root, PtOT);
    return PtOT;
}


//M-2 Iterative Way
vector<int> postOrder(Node* node) 
{
    vector<int> postOT;
    stack<pair<Node*, int>> s;
        
    s.push({node, 0});
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
            s.push({currNode->right, 0});
        else if(currState==2)
            postOT.push_back(currNode->data);
    }
    return postOT;
}