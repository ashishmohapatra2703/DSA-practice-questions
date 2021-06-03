/* Given inorder and level-order traversals of a Binary Tree, 
construct the Binary Tree and return the root Node. 
Constraints:
1<=T<=100
1<=N<=100

Input:
2
3
1 0 2 
0 1 2 
7
3 1 4 0 5 2 6 
0 1 2 3 4 5 6 
Output:
0 1 2
0 1 3 4 2 5 6 */

int* findSubTreeLevelOrder(int inO[], int inStart, int inEnd, int lvO[], int n)
{
    unordered_set<int> s; 
    for(int i= inStart; i<= inEnd; i++)
        s.insert(inO[i]); //leftSubTree or rightSubTree Nodes from Inorder[] 
    
    int* lvOsubTree = new int[s.size()];
    int lvOitr = 0;
    for(int i= 0; i<= n; i++)
    {
        if(s.find(lvO[i]) != s.end())
        {
            lvOsubTree[lvOitr++] = lvO[i];
        }
    }
    return lvOsubTree;
}
Node* buildTreefromInandLevel(int inorder[], int inStart, int inEnd, int levelOrder[], int size, unordered_map<int, int> &mp)
{
    if(inStart > inEnd)
        return NULL;
        
    int RootData = levelOrder[0];
    int RootindexinIn = mp[RootData];
    Node* root = new Node(RootData);
    
    int* lSubTLevelOrder = findSubTreeLevelOrder(inorder, inStart, RootindexinIn-1, levelOrder, size);
    int lSubTsize = RootindexinIn - inStart;
    int* rSubTLevelOrder = findSubTreeLevelOrder(inorder, RootindexinIn+1, inEnd, levelOrder, size);
    int rSubTsize = inEnd - RootindexinIn; 
    
    root->left = buildTreefromInandLevel(inorder, inStart, RootindexinIn-1, lSubTLevelOrder, lSubTsize, mp);
    root->right = buildTreefromInandLevel(inorder, RootindexinIn+1, inEnd, rSubTLevelOrder, rSubTsize, mp);
    return root;
}


Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n)
{   
    unordered_map<int, int> mp;
    for(int i= iStart; i<= iEnd; i++)
    {
        mp[inorder[i]] = i;
    }
    return buildTreefromInandLevel(inorder, iStart, iEnd, levelOrder, n, mp);
}