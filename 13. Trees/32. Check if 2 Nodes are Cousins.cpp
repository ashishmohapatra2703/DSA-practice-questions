/* Given the binary Tree and the two nodes say ‘a’ and ‘b’, 
determine whether the two nodes are cousins of each other or not.
Two nodes are cousins of each other if they are at same level and have different parents.
     6
   /   \
  3     5
 / \   / \
7   8 1   3
Say two node be 7 and 1, result is TRUE.
Say two nodes are 3 and 5, result is FALSE.
Say two nodes are 7 and 5, result is FALSE.      */


void storeParentofAllNodes(Node* root, Node* parent, unordered_map<Node*, Node*> &mp) //using DFS (pre-order)
{
    if(root==NULL)
        return;
            
    mp[root] = parent;
    storeParentofAllNodes(root->left, root, mp);
    storeParentofAllNodes(root->right, root, mp);
}
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
    unordered_map<Node*, Node*> mp;
    storeParentofAllNodes(root, NULL, mp);
    
    queue<Node*> q;

    q.push(root); //first push the root
    while(! q.empty())
    {
        int levelWidth = q.size();
        Node* Node_a = NULL;
        Node* Node_b = NULL;
    
        for(int i=0; i<levelWidth; i++) //traversing horizontally nodes at each level
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == a)
                Node_a = temp;
            else if(temp->data == b)
                Node_b = temp;
                
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
        
        if(Node_a!=NULL && Node_b!=NULL) //check after traversing each level
        {                             //if both the nodes found in that level
            if(mp[Node_a] != mp[Node_b])
                return true;
        }
        if(Node_a!=NULL || Node_b!=NULL) //if only 1 of the node found in the level
        {   
            Node_a = NULL;
            Node_b = NULL;
        }
    }
    return false;
}