/* Given a binary tree and two node values your task is to find the minimum distance between them.

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation:  We need the distance between 2 and 3. 
Being at node 2, we need to take two steps ahead in order to reach node 3.
The path followed will be: 2 -> 1 -> 3. Hence, the result is 2.  */

//M-1
Node* getlca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2) //base condition:- found any one of the 2 nodes
        return root;
            
    Node* LSubTreeLCA = getlca(root->left, n1, n2);
    Node* RSubTreeLCA = getlca(root->right, n1, n2);
    if(LSubTreeLCA!=NULL && RSubTreeLCA!=NULL)
        return root;
    if(LSubTreeLCA!=NULL)
        return LSubTreeLCA;
    else if(RSubTreeLCA!=NULL)
        return RSubTreeLCA;
    return NULL; //none of them are present
}
int getDistanceBetween(Node* node, int dist, int &target)
{
    if(node==NULL)
        return -1;
    if(node->data == target)
        return dist;
    
    int distinLSubT = getDistanceBetween(node->left, dist+1, target);
    if(distinLSubT != -1)
        return distinLSubT;
    int distinRSubT = getDistanceBetween(node->right, dist+1, target);
    if(distinRSubT != -1)
        return distinRSubT;
}
/* Should return minimum distance between a and b
   in a tree with given root*/
int findDist(Node* root, int a, int b) 
{
    Node* LCA = getlca(root, a, b);
    if(LCA == NULL)
        return -1; //2 nodes dont have any connection
        
    int dist1 = getDistanceBetween(LCA, 0, a); //dist1 from LCA to aNode
    int dist2 = getDistanceBetween(LCA, 0, b); //dist2 from LCA to bNode
    return dist1 + dist2;
}


//M-2
//Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)