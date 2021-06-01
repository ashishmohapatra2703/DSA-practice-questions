/*Given a Binary Tree of size N, you need to find 
all the possible paths from root node to all the leaf node's of the binary tree.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: [[10 20 40], [10 20 60], [10 30]]  */

void getPaths(Node* root, vector<int> curr_path, vector<vector<int>> &paths)
{
    if(root==NULL)
        return;
    
    curr_path.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
        paths.push_back(curr_path);
        
    getPaths(root->left, curr_path, paths);
    getPaths(root->right, curr_path, paths);
}
/* The function should print all the paths from root
 to leaf nodes of the binary tree */
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> root2leafPaths;
    vector<int> curr_path;
    
    getPaths(root, curr_path, root2leafPaths);
    return root2leafPaths;
}


// M-2  more space optimization 
// as curr_path is also passed by reference, instead of passing by value
// by handling the returning phase after recursive calls
void getPaths(Node* root, vector<int> &curr_path, vector<vector<int>> &paths)
{
    if(root==NULL)
        return;
    
    curr_path.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
        paths.push_back(curr_path);
        
    getPaths(root->left, curr_path, paths);
    getPaths(root->right, curr_path, paths);
    
    curr_path.pop_back();
}