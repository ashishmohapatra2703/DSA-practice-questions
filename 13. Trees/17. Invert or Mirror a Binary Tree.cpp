//function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


// Time Complexity: O(N).
// Auxiliary Space: O(Height of the Tree).
/* Should convert tree to its mirror */
void mirror(Node* p) 
{
    if(p==NULL)
        return;
    
    mirror(p->left);
    mirror(p->right); //can be done by pre- or postorder traversal
    
    Node* temp = p->left; //& swapping of child pointers
    p->left = p->right;
    p->right = temp;
}