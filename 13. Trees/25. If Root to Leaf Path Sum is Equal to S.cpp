/*Given a binary tree and an integer S, check whether there is root to leaf path with its sum as S.
Input: Tree = 
            1
          /   \
        2      3
S = 4

Output: 1
Explanation: The sum of path from leaf node 3 to root 1 is 4. */

class Solution{
public:
    void hasPathSumasS(Node* root, int curr_sum, int &S, bool &sumPathFound)
    {
        if(root==NULL)
            return;
        
        curr_sum += root->data;
        if(root->left==NULL && root->right==NULL && curr_sum==S) //at a leaf node
        {
            sumPathFound = true;
            return;
        }
            
        hasPathSumasS(root->left, curr_sum, S, sumPathFound);
        hasPathSumasS(root->right, curr_sum, S, sumPathFound);
    }
    bool hasPathSum(Node *root, int S) 
    {
        int curr_sum = 0;
        bool sumPathFound = false;
        
        hasPathSumasS(root, curr_sum, S, sumPathFound);
        
        return sumPathFound;
    }
};


// M-2  more space optimization 
// as curr_sum is also passed by reference, instead of passing by value
// by handling the returning phase after recursive calls
    void hasPathSumasS(Node* root, int &curr_sum, int &S, bool &sumPathFound)
    {
        if(root==NULL)
            return;
        
        curr_sum += root->data;
        if(curr_sum==S && root->left==NULL && root->right==NULL)
        {
            sumPathFound = true;
            return;
        }
            
        hasPathSumasS(root->left, curr_sum, S, sumPathFound);
        hasPathSumasS(root->right, curr_sum, S, sumPathFound);
        
        curr_sum -= root->data;
    }




///////Similar Question on Root to leaf paths Sum ----
/*Given a binary tree of N nodes, where every node value is a number. 
Find the sum of all the numbers which are formed from root to leaf paths.

Input :      
           6                               
         /   \                          
        3     5                      
      /   \     \
     2    5      4             
        /  \                        
       7    4  
Output: 13997
Explanation :
There are 4 leaves, hence 4 root to leaf paths:
Path                      Number
6->3->2                   632
6->3->5->7                6357
6->3->5->4                6354
6->5>4                    654   
Answer = 632 + 6357 + 6354 + 654 = 13997   */

long long convertArraytoNumber(vector<int> v)
{
    long long num = 0;
    int expo = 0;
    for(int i=v.size()-1; i>=0; i--)
    {
        num += v[i]*pow(10,expo);
        expo ++;
    }
    return num;
}
void getPaths(Node* root, vector<int> curr_path, vector<vector<int>> &paths)
{
    if(root==NULL)
        return;
    
    curr_path.push_back(root->data);
    if(root->left==NULL && root->right==NULL) //at leaf node
        paths.push_back(curr_path);
        
    getPaths(root->left, curr_path, paths);
    getPaths(root->right, curr_path, paths);
}
/*You are required to complete below method */
long long treePathsSum(Node *root)
{
    vector<vector<int>> root2leafPaths;
    vector<int> curr_path;
    
    getPaths(root, curr_path, root2leafPaths);
    
    long long sum = 0;
    for(vector<int> it: root2leafPaths)
    {
        long long number = convertArraytoNumber(it);
        sum += number;
    }
    return sum;
}