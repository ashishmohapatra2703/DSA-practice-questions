/*  Input: 19 10 8 11 13
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19  */

void helper(Node* p, vector<int> &PtOT) //pass by reference
{
    if(p == nullptr)
        return;
        
    helper(p->left, PtOT);
    helper(p->right, PtOT);
    PtOT.push_back(p->data);
}

vector<int> postOrder(Node* root)
{
    vector<int> PtOT;
    helper(root, PtOT);
    return PtOT;
}