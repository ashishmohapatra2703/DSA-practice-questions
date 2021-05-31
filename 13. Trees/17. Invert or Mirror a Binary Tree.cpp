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

/* Should convert tree to its mirror */
void mirror(Node* p) 
{
    if(p==0)
        return;
    
    mirror(p->left);
    mirror(p->right); //postorder traversal
    
    Node*temp = p->left; //& swapping of child pointers
    p->left = p->right;
    p->right = temp;
}