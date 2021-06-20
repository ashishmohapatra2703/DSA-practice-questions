/*  Input:
    N = 8
    in[] = 4 8 2 5 1 6 3 7
    post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder andinorder traversal of tree the  resultant binary tree will be
          1
       /    \
     2       3
   /  \    /   \
  4    5  6    7
   \
     8           
Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(N).         */


Node* BuildTreefromInandPre(int in[],int post[],int inStart,int inEnd,int postStart,int postEnd)
{
    if(inStart > inEnd || postStart > postEnd)
        return NULL;
    
    int RootindexinPost = postEnd;
    int RootData = post[RootindexinPost];
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
    int leftpostStart = postStart;
    int leftpostEnd = leftinEnd - leftinStart + leftpostStart;
    root->left = BuildTreefromInandPre(in, post, leftinStart, leftinEnd, leftpostStart, leftpostEnd);
    
    int rightinStart = RootindexinIn + 1;
    int rightinEnd = inEnd;
    int rightpostStart = leftpostEnd + 1;
    int rightpostEnd = postEnd - 1;
    root->right = BuildTreefromInandPre(in, post, rightinStart, rightinEnd, rightpostStart, rightpostEnd);
    
    return root;
}
// Function should construct tree and return root of it. 
// in[] stores inorder traversal & post[] stores postorder traversal.  n is size of these arrays

Node *buildTree(int in[], int post[], int n) 
{
    int inStart = 0;
    int inEnd = n-1;
    int postStart = 0;
    int postEnd = n-1;
    return BuildTreefromInandPre(in, post, inStart, inEnd, postStart, postEnd);
}

/* while searching for RootData in inorder[] worst case T.C = O(n)
 //OPTIMIZATION :-
 make a unordered_map<int, int> storing 
  key = inorder elements &
  value = index 
so that every n time, searching RootindexinIn can be done in O(1) time 
Henceforth, Overall T.C will be O(n) & S.C will be O(n)     */