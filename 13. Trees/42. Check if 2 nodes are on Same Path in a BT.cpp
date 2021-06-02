/* Given two nodes of a binary tree v1 and v2, 
the task is to check if two nodes are on the same path in a tree. 
Example: 
Input:  v1 = 1, v2 = 5
       1
    /  |  \
   2   3   4
  /    |    \
 5     6     7
Output: Yes
Explanation: Both nodes 1 and 5lie in the path 1 -> 2 -> 5.

Input: v1 = 2, v2 = 6
       1
    /  |  \
   2   3   4
  /    |    \
 5     6     7
Output: NO 		*/

Node* lca(Node* root ,int &n1 ,int &n2, bool &isSamePath)
{
    if(root == NULL)
        return NULL;
    if(root->data==n1 || root->data==n2) //base condition:- found any one of the 2 nodes
        return root;
           
    Node* inLSubT = lca(root->left, n1, n2);
    Node* inRSubT = lca(root->right, n1, n2);
    if(inLSubT!=NULL && inRSubT!=NULL)
    {						//while finding LCA,
      	isSamePath = false; //in this case the given 2 nodes will not be in the same path 
        return root;
    }
    if(inLSubT!=NULL)
        return inLSubT;
    else if(inRSubT!=NULL)
        return inRSubT;
    return NULL; //none of them are present
}
bool ifNodesonSamePath(Node* root ,int n1 ,int n2)
{
	bool isSamePath = true;
	lca(root, n1, n2, isSamePath);
	return isSamePath;
}


/*  M-2
1.find the lca node
2.check if lca node is equal to either of a or b / any one of them
3.if it's true => return true 
    else => return false */