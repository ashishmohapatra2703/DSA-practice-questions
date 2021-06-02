/*Given a Binary Tree of size N and an integer K. 
Print all nodes that are at distance k from root (root is considered at distance 0 from itself). 
Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.
          1
       /     \
     2        3
   /         /  \
  4          5   6 
   \
    8                                       */


//M-1  USING BFS (processing level by level)
// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
    if(root == NULL)
        return {};
            
    vector<int> KLevelOT;
    queue<pair<Node*, int>> q;
    int level = 0;
    
    q.push({root, level}); //first push the root and level 0
    while(! q.empty())
    {
        int levelWidth = q.size();
    
        for(int i=0; i<levelWidth; i++)
        {
            pair<Node*, int> tempPair = q.front();
            q.pop();
            Node* tempNode = tempPair.first;
            level = tempPair.second;
            
            if(level==k)
                KLevelOT.push_back(tempNode->data); //traversing all horizontal nodes at K level from root
            else if(level>k)
                return KLevelOT; //so that we won't process for level next to Kth (time optimization) :)


            if(tempNode->left != nullptr)
                q.push({tempNode->left, level+1});
            if(tempNode->right != nullptr)
                q.push({tempNode->right, level+1});
        }
    }
    return KLevelOT;
}


//M-2 USING DFS
void KdistancefromRoot(Node* root, int level, int &K, vector<int> &KlevelNodes)
{
    if(root==NULL)
        return;
    if(level == K)
    {
        KlevelNodes.push_back(root->data);
        return; //so that we won't go further deep after level K (time optimization)
    }
    
    KdistancefromRoot(root->left, level+1, K, KlevelNodes);
    KdistancefromRoot(root->right, level+1, K,  KlevelNodes);
}
// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> KlevelNodes;
    KdistancefromRoot(root, 0, k, KlevelNodes);
    return KlevelNodes;
}