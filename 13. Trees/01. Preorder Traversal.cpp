/*Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2    */

void helper(Node* p, vector<int> &PrOT) //pass by reference
{
    if(p == nullptr)
        return;
       
    PrOT.push_back(p->data); 
    helper(p->left, PrOT);
    helper(p->right, PrOT);
}
// Return a vector containing the preorder traversal of the tree
vector <int> preorder(Node* root)
{
    vector<int> PrOT;
    helper(root, PrOT);
    return PrOT;
}