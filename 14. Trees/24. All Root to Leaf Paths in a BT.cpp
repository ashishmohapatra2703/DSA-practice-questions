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





//////Similar Question --
/*Given a binary tree, you need to find the 
number of all root to leaf paths along with their path lengths.

Input:
10 20 30 40 60
Output:
2 1 $3 2 $
Explanation:
There is 1 root leaf paths of length 2 and 
2 roots to leaf paths of length 3. */

void getPathsLen(Node* root, int currPathLen, vector<int> &FullpathLen, map<int,int> &mp)
{
    if(root==NULL)
        return;
        
    currPathLen = currPathLen + 1;
    if(root->left==NULL && root->right==NULL)   //at leaf node 
    {
        FullpathLen.push_back(currPathLen);
        mp[currPathLen] ++;
    }    
    getPathsLen(root->left, currPathLen, FullpathLen, mp);
    getPathsLen(root->right, currPathLen, FullpathLen, mp);
}
/*You are required to complete below method */
void pathCounts(Node *root)
{
    vector<int> root2leafPathsLen;
    map<int, int> mp; //key=Length & value=Num of Paths of that same Length
    
    getPathsLen(root, 0, root2leafPathsLen, mp);
    
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<" $";
    }
}