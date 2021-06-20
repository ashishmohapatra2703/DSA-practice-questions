/* Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be  40<=>20<=>60<=>10<=>30.    */

/*  Time Complexity: O(N).
	Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.*/

// This function should return head to the DLL
class Solution
{
public: 
    void addToDLL(Node* &root, Node* &head, Node* &tail)
    {
        if(head==NULL && tail==NULL)
        {
            head = tail = root;   
        }
        else
        {
            root->left = tail;
            tail->right = root;
            tail = root;
        }
    }
    void BTtoDLL(Node* root, Node* &head, Node* &tail)
    {
        if(root==NULL)
            return;
        
        BTtoDLL(root->left, head, tail);
        addToDLL(root, head, tail);
        BTtoDLL(root->right, head, tail);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node* bToDLL(Node *root)
    {
        Node* head = NULL;
        Node* tail = NULL;
        BTtoDLL(root, head, tail);
        return head;
    }
};

//or can use "static Node* tail" inside the function