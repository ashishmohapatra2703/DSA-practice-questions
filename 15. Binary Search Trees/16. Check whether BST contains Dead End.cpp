/*Given a Binary search Tree that contains positive integer values greater then 0. The task is to 
complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. 
Here Dead End means, we are not able to insert any element after that node.
Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that we cant insert any element.       

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at node 9.  

Constraints:
1<=T<=100
1<=N<=200       */

void checkForDeadEnd(Node* currNode, int minLmt, int maxLmt, bool &haveDeadEnd)
{
    if(currNode==NULL)
        return;
    if(minLmt > maxLmt)
        return;
    if(haveDeadEnd == true) //time OPTIMIZATION
        return;
        
    if(currNode->left==NULL && currNode->right==NULL) //checking  at leaf node
    {
        if( minLmt == maxLmt or (minLmt=INT_MIN and maxLmt==1) )
            haveDeadEnd = true;
        
        return;
    }
    
    //if not leaf node
    checkForDeadEnd(currNode->left, minLmt, currNode->data-1, haveDeadEnd);
    checkForDeadEnd(currNode->right, currNode->data+1, maxLmt, haveDeadEnd);
}
/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    bool haveDeadEnd = false;
    checkForDeadEnd(root, INT_MIN, INT_MAX, haveDeadEnd);
    return haveDeadEnd;
}