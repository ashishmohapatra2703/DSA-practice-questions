/*M-1
The inorder traversal of a BST produces a sorted array.
  So a simple method is to store inorder traversal of the input tree in an auxiliary array.
  Sort the auxiliary array. 
  Finally, insert the auxiilary array elements back to the BST, keeping the structure of the BST same.
  Time complexity of this method is O(nLogn) and auxiliary space needed is O(n).*/

//M-2
//While doing In-Order traversal, we can keep track of previously visited node.
//If the swapped nodes are adjacent to each other, then first and middle contain the resultant nodes 
//Else, first and last contain the resultant nodes 

void swap(int &a, int &b) //pass by reference
{ 
    int temp = a; 
    a = b; 
    b = temp; 
}
void InorderFixBST(struct Node *root, struct Node* &first, struct Node* &last, struct Node* &prev)
{
    if(root == NULL)
        return;
        
    InorderFixBST(root->left, first, last, prev);
    
    if(first==NULL && prev && prev->data >= root->data)//If this node is smaller than the previous node,
    {
        first = prev;   //it's violating the BST rule first time
        last = root;
    }
    if(first!=NULL && prev && prev->data >= root->data)
    {
        last = root;   //it's violating the BST rule second time
    }
    prev = root;
    
    InorderFixBST(root->right, first, last, prev);
}
struct Node* correctBST(struct Node* root)
{
    struct Node* first = NULL;
    struct Node* last = NULL;
    struct Node* prev = NULL;
    
    InorderFixBST(root, first, last, prev);
    
    if(first && last)
        swap(first->data ,last->data);
    //case-1 1st & 2nd element of a pair are swapped (Adjacent node)
    //case-2 1st element of 1st pair & 2nd element of 2nd pair are swapped
    return root;
}