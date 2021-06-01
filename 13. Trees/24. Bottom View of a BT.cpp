/*Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.
                      20
                    /    \
                  8       22
                /   \       \
              5      3       25
                    /  \      
                  10    14
For the above tree, the bottom view is 5 10 3 14 25.

If there are multiple bottom-most nodes for a horizontal distance from root, 
then print the later one in level traversal.    For example, in the below diagram, 
3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.
                      20
                    /    \
                  8       22
                /   \     /  \
              5      3   4    25
                     /    \      
                   10     14
For the above tree the output should be 5 10 4 14 25. */

//(just by tweaking Vertical Order Traversal a little bit)

//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
    if(root == NULL)
        return {};  //very imp. base condition
        
    vector<int> BVT;  //Bottom view traversal
    queue<pair<Node*, int>> q;
    map<int, int> mp;
        
    q.push({root, 0});
    while(! q.empty())
    {
        pair<Node*, int> tempPair = q.front();
        q.pop();
        Node* tempNode = tempPair.first;
        int hrzIdx =  tempPair.second;//horizontal distance from root (root being the origin of X-axis)
            
        //key -> hrzIdx  and  value -> having only the Bottom/last vertical node data, at that X abscissa
        mp[hrzIdx] = tempNode->data; //updation at every level
        //so that the lowest node at any vertical level, gets into the respective X-axis key
            
        if(tempNode->left != NULL)
            q.push({tempNode->left , hrzIdx-1});
        if(tempNode->right != NULL)
            q.push({tempNode->right , hrzIdx+1});
    }
        
    for(auto it: mp)
    {
        BVT.push_back(it.second);
    }
    return BVT;
}
