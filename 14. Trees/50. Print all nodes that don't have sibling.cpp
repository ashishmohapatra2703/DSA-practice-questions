/* Given a Binary Tree of size N, find all the nodes which don't have any sibling. 
Root node can not have a sibling.
Input :
       37
      /   
    20
    /     
  113 
Output: 20 113     Explanation: 20 and 113 dont have any siblings.

Input :
       1
      / \
     2   3 
Output: -1         Explanation: Every node has a sibling.

Your Task:  You dont need to read input or print anything. Complete the function noSibling() which takes the 
root of the tree as input parameter and returns a list of integers containing all the nodes 
that don't have a sibling in sorted order. If all nodes have a sibling, 
then the returning list should contain only one element -1.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(Height of the tree) */

void getAllNoSiblingNodes(Node* root, vector<int> &noSiblingNodes)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        return;
    
    if(root->left!=NULL && root->right==NULL)
        noSiblingNodes.push_back(root->left->data);
    if(root->right!=NULL && root->left==NULL)
        noSiblingNodes.push_back(root->right->data);
        
    getAllNoSiblingNodes(root->left, noSiblingNodes);
    getAllNoSiblingNodes(root->right, noSiblingNodes);
}
vector<int> noSibling(Node* node)
{
    vector<int> noSiblingNodes;
    getAllNoSiblingNodes(node, noSiblingNodes);
    
    if(noSiblingNodes.size() == 0)
        return {-1};
        
    sort(noSiblingNodes.begin(), noSiblingNodes.end());
    return noSiblingNodes;
}