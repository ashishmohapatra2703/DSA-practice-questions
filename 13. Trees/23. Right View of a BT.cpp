/*Given a Binary Tree, find Right view of it. 
Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
Right view of following tree is 1 3 7 8.
          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8              */

//M-1  T.C = O(N) & S.C = O(max. nodes at any level)
class Solution{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        if(root == NULL)
            return {};  //very imp. base condition
        
        vector<int> RVT; //right view traversal
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
                    RVT.push_back(temp->data);
                    isFirst = false;
                }
    
                if(temp->right != nullptr)
                    q.push(temp->right);      //order swapped from LVT
                if(temp->left != nullptr)    //traversing right to left at each level in queue 
                    q.push(temp->left);
            }
            else if(temp == NULL)
            {
                if(q.size() == 0)
                    return RVT;
                else if(q.size() > 0)
                {
                    q.push(NULL);
                    isFirst = true;
                }
            }
        }
    }
};



//M-2 Easier to understand (just by tweaking Level Order Traversal a little bit)
class Solution{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        if(root == NULL)
            return {};
                
        vector<int> RVT;
        queue<Node*> q;
    
        q.push(root); //first push the root
        while(! q.empty())
        {
            int levelWidth = q.size();
    
            for(int i=0; i<levelWidth; i++) //traversing horizontally nodes at each level
            {
                Node* temp = q.front();
                q.pop();
                if(i==levelWidth-1)
                    RVT.push_back(temp->data); // rightmost/last node element at each level
                    
                if(temp->left != nullptr)
                    q.push(temp->left);
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
        }
        return RVT;
    }
};
