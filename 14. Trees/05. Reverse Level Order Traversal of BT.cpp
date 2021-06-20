/*Given a binary tree of size N, find its reverse level order traversal. 
ie- the traversal must begin from the last level.
Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10  */

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> rLOT;
    queue<Node*> q;

    q.emplace(root); //first push the root        
    while(! q.empty())
    {
        Node* temp = q.front();
        q.pop();
        rLOT.push_back(temp->data);
            
        if(temp->right != nullptr)
            q.emplace(temp->right);   //order swapped from LOT        
        if(temp->left != nullptr)     //traversing right to left at each level in queue 
            q.emplace(temp->left);
    }
    reverse(rLOT.begin(), rLOT.end());
    return rLOT;
}