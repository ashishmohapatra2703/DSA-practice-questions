/*Input:  N = 6
		inorder[] = {3 1 4 0 5 2}
		preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).             */

Node* BuildTreefromInandPre(int in[],int pre[],int inStart,int inEnd,int preStart,int preEnd)
{
    if(inStart > inEnd || preStart > preEnd)
        return NULL;
    
    int RootindexinPre = preStart;
    int RootData = pre[RootindexinPre];
    int RootindexinIn = -1;
    for(int i= inStart; i<= inEnd; i++)
    {
        if(in[i] == RootData)
        {
            RootindexinIn = i;
            break;
        }
    }
    
    Node* root = new Node(RootData);
    
    int leftinStart = inStart;
    int leftinEnd = RootindexinIn - 1;
    int leftpreStart = RootindexinPre + 1;
    int leftpreEnd = leftinEnd - leftinStart + leftpreStart;
    root->left = BuildTreefromInandPre(in, pre, leftinStart, leftinEnd, leftpreStart, leftpreEnd);
    
    int rightinStart = RootindexinIn + 1;
    int rightinEnd = inEnd;
    int rightpreStart = leftpreEnd + 1;
    int rightpreEnd = preEnd;
    root->right = BuildTreefromInandPre(in, pre, rightinStart, rightinEnd, rightpreStart, rightpreEnd);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int inStart = 0;
    int inEnd = n-1;
    int preStart = 0;
    int preEnd = n-1;
    return BuildTreefromInandPre(in, pre, inStart, inEnd, preStart, preEnd);
}