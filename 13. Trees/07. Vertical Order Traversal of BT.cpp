/*Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, 
then they should be printed as they appear in level order traversal of the tree.
Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
   4 2 1 5 6 3 8 7 9    */

class Solution{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> VOT;
        queue<pair<Node*, int>> q;
        map<int, vector<int>> mp;
        
        q.push({root, 0});
        while(! q.empty())
        {
            pair<Node*, int> tempPair = q.front();
            q.pop();
            Node* tempNode = tempPair.first;
            int hrzIdx =  tempPair.second;//horizontal distance from root (root being the origin of X-axis)
            
        //key -> hrzIdx  and  value -> vector<int> having all vertical node data, at that X abscissa 
            if(mp.find(hrzIdx) != mp.end()) //found a key-value pair present in map
                mp[hrzIdx].push_back(tempNode->data);
            else
                mp[hrzIdx] = {tempNode->data};
                //mp.insert( pair<int,vector<int>>( hrzIdx , {tempNode->data} ) );    //can use this too
            
            if(tempNode->left != NULL)
                q.push({tempNode->left , hrzIdx-1});
            if(tempNode->right != NULL)
                q.push({tempNode->right , hrzIdx+1});
        }
        

        for(auto it: mp)
        {
            for(int nodeData: it.second)
            {
                VOT.push_back(nodeData);
            }
        }
        return VOT;
    }
};

//can do simply -- mp[hrzIdx].push_back(tempNode->data);   WITHOUT ANY CONDITIONS  LOL :)