/*
{
#include <bits/stdc++.h>
using namespace std;
// A binary tree node has data, pointer to left child and a pointer to right child 
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
// Returns true if the given tree is a binary search tree (efficient version). 
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
// Driver program to test size function
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}

} 
*/
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

/////////      M-1
// In binary search tree (BST)
//• The left subtree of a node contains only nodes with keys less than the node’s key.
//• The right subtree of a node contains only nodes with keys greater than the node’s key.
//• Both the left and right subtrees must also be binary search trees.
bool check(Node *p, int min, int max)
{
    if(p == nullptr)
        return true;
    if(p->data < min || p->data > max)
        return false;
    
    check(p->left, min, p->data-1) && check(p->right, p->data+1, max); // Allow only distinct values  
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) 
{
    check(root, INT_MIN, INT_MAX);
}



/////////      M-2
/*   
- We take a variable 'prev'.
- Now whenever we're traversing any node, we check node value with previous node value
- If current node value is less than previous value, we return false, else we keep on checking. 
- We check this for all nodes in tree
*/
bool InorderCheckBST(Node* root, Node* &prev) //pass by reference
{
    if(root == nullptr)
        return true; //base condition
        
    if(InorderCheckBST(root->left, prev)==false)
        return false;
    
    if(prev && prev->data >= root->data) //invalid case (not sorted inorder traversal)
    {
        return false;
    }
    prev = root;
    
    if(InorderCheckBST(root->right, prev)==true)
        return true;
    //else if(InorderCheckBST(root->right, prev)==false)
    return false;
}
// return true if the given tree is a BST, else return false
bool isBST(Node* root) 
{
    Node *prev = nullptr;
    return InorderCheckBST(root, prev);
}