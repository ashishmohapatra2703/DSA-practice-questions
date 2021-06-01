/*Given below is a binary tree. The task is to print the top view of binary tree. 
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
For the given below tree
       1
    /     \
   2       3
  /  \    /  \
 4    5   6   7
Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. */

//(just by tweaking Vertical Order Traversal a little bit)
class Solution{
public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if(root == NULL)
            return {};  //very imp. base condition
        
        vector<int> TVT;
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        
        q.push({root, 0});
        while(! q.empty())
        {
            pair<Node*, int> tempPair = q.front();
            q.pop();
            Node* tempNode = tempPair.first;
            int hrzIdx =  tempPair.second;//horizontal distance from root (root being the origin of X-axis)
            
        //key -> hrzIdx  and  value -> having only the top vertical node data, at that X abscissa 
            if(mp.count(hrzIdx) == 0) //if not present   //OR can use --> if(mp.find(hrzIdx) == mp.end()) 
                mp[hrzIdx] = tempNode->data; 
            //if present already => do nothing
            
            if(tempNode->left != NULL)
                q.push({tempNode->left , hrzIdx-1});
            if(tempNode->right != NULL)
                q.push({tempNode->right , hrzIdx+1});
        }
        
        for(auto it: mp)
        {
            TVT.push_back(it.second);
        }
        return TVT;
    }
};