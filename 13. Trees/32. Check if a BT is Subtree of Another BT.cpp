/*Given two binary trees with head reference as T and S having at most N nodes. 
The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1  					*/

/*M-1: Traverse the tree T in preorder fashion. For every visited node in the traversal, 
if this root as current node of BT == root node of subtree
see if the subtree rooted with this node is identical to S. */

// worst case T.C = O(mn) where m and n are number of nodes in given two trees.

class Solution{  //TLE in gfg
  public:
    bool isIdenticalTrees(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL)  //both NULL
            return true;
        if(r1==NULL || r2==NULL)  //any one is NULL
            return false;
        if(r1->data != r2->data) //if above both conditions are not the case,
            return false;       //then check if both datas are equal or not
            
        if(isIdenticalTrees(r1->left, r2->left) == true &&
            isIdenticalTrees(r1->right, r2->right) == true)
            return true;   //recur for checking in left and right subtree
        else
            return false;
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S)  //////////////////// using DFS
    {
        if(S==NULL)
            return true;
        if(T==NULL)
            return false;
        if(T->data == S->data)
        {
            if(isIdenticalTrees(T, S) == true)
                return true;
        }
        
        if(isSubTree(T->left, S)==true || isSubTree(T->right, S)==true)
            return true;
        else
            return false;
    }
    ////////////////////////// OR using BFS (for traversal in bigger tree)
    bool isSubTree(Node* T, Node* S) 
    {
        if(S==NULL)
            return true;
        if(T==NULL)
            return false;
            
        queue<Node*> q;

        q.push(T); //first push the root        
        while(! q.empty())
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == S->data)
            {
                if(isIdenticalTrees(temp, S) == true)
                    return true;
            }
            
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        return false;
    }
};

//M-2 (Using serialization and pattern matching)