/*Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2    */

//M-1 Recursive Way
void helper(Node* p, vector<int> &PrOT) //pass by reference
{
    if(p == nullptr)
        return;
       
    PrOT.push_back(p->data); 
    helper(p->left, PrOT);
    helper(p->right, PrOT);
}
// Return a vector containing the preorder traversal of the tree
vector <int> preorder(Node* root)
{
    vector<int> PrOT;
    helper(root, PrOT);
    return PrOT;
}


//M-2 Iterative Way
vector<int> preOrder(Node* root)
{
    vector<int> preOT;
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
            preOT.push_back(currNode->data);
        else if(currState==1)
            s.push({currNode->left, 0});
        else if(currState==2)
            s.push({currNode->right, 0});
    }
    return preOT;
}