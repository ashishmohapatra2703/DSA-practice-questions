/* Given a Binary Tree, print Left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
      2       3
     / \     / \
    4   5   6   7
    \
     8                                 */

//M-1  T.C = O(N) & S.C = O(max. nodes at any level)

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    if(root == NULL)
        return {};  //very imp. base condition
        
    vector<int> LVT; //left view traversal
    queue<Node*> q;
    bool isFirst = true;
    
    q.push(root);
    q.push(NULL); //NULL to be placed "after each level" is traversed
    while(! q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        if(temp != NULL)
        {
            if(isFirst == true)
            {
                LVT.push_back(temp->data);
                isFirst = false;
            }

            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
        else if(temp == NULL)
        {
            if(q.size() == 0)
                return LVT;
            else if(q.size() > 0)
            {
                q.push(NULL);
                isFirst = true;
            }
        }
    }
}


//M-2 Easier to understand (just by tweaking Level Order Traversal a little bit)
vector<int> leftView(Node *root)
{
    if(root == NULL)
        return {};
            
    vector<int> LVT;
    queue<Node*> q;

    q.push(root); //first push the root
    while(! q.empty())
    {
        int levelWidth = q.size();

        for(int i=0; i<levelWidth; i++) //traversing horizontally nodes at each level
        {
            Node* temp = q.front();
            q.pop();
            if(i==0)
                LVT.push_back(temp->data); // leftmost/first node element at each level
                
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
    }
    return LVT;
}