/*Input:
        10
     /      \ 
    20       30 
  /    \    /
 40    60  50
Output: 40 20 60 10 50 30   */

void helper(Node* p, vector<int> &IOT) //pass by reference
{
    if(p == nullptr)
        return;
        
    helper(p->left, IOT);
    IOT.push_back(p->data);
    helper(p->right, IOT);
}
// Return a vector containing the inorder traversal of the tree
vector<int> inOrder(Node* root)
{
    vector<int> IOT;
    helper(root, IOT);
    return IOT;
}