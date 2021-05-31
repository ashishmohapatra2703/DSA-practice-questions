/*Given a Binary Tree, print the diagonal traversal of the binary tree.
Consider lines of slope -1 passing between nodes. 
Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14  3 6 7 13  1 4  */

//M-1 DFS Pre-Order Recursive + Hashing
void diagonalTraversal(Node* node, int distace, map<int, vector<int>> &mp)
{
    if(node==NULL)
        return;
      
    mp[distace].push_back(node->data);  
    diagonalTraversal(node->left, distace+1, mp);
    diagonalTraversal(node->right, distace, mp);
}
vector<int> diagonal(Node *root)
{
    vector<int> diagT;
    map<int, vector<int>> mp;
    
    diagonalTraversal(root, 0, mp);
    
    for(auto it: mp)
    {
        for(int nodeData: it.second)
        {
            diagT.push_back(nodeData);
        }
    }
    return diagT;
}
//To get the same order as in the output traverse the tree same as we do in pre-order traversal.



//M-2 Iterative (Using Queue)
/*we are starting from root and printing items from root till the last right of root and 
whenever we are finding that a item has left child we are adding it to queue .*/
vector<int> diagonal(Node *root)
{
    vector<int> diagT;
    queue<Node*> q;
    
    q.push(root);
    while (! q.empty())
    {
        Node* temp = q.front();
        q.pop();
        while(temp != NULL)
        {
            if(temp->left != NULL)
                q.push(temp->left);

            diagT.push_back(temp->data);
            temp = temp->right;
        }
    }
    return diagT;
}