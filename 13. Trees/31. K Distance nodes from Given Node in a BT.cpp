/*Given a binary tree, a target node in the binary tree, and an integer value k, 
find all the nodes that are at distance k from the given target node, in a sorted order.
No parent pointers are available.

Input :      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2 from node 8 are 10, 14, 22.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(Height of tree)

Constraints:
1 ≤ N ≤ 10^3
1 ≤ data of node ≤ 10000
1 ≤ target ≤ 10000
1 ≤ k ≤ 20 */

class Solution{
private:
    unordered_map<Node*, Node*> mp; //store the parent node of any keynode
    unordered_set<Node*> visited;
    void storeParentofAllNodes(Node* root, Node* parent) //using DFS (pre-order)
    {
        if(root==NULL)
            return;
            
        mp[root] = parent;
        storeParentofAllNodes(root->left, root);
        storeParentofAllNodes(root->right, root);
    }
    Node* findtargetNode(Node* root, int &target) //using DFS (pre-order)
    {
        if(root==NULL)
            return NULL;
        if(root->data == target)    
            return root;
            
        Node* nodeAtleft = findtargetNode(root->left, target);
        if(nodeAtleft != NULL)
            return nodeAtleft;
        Node* nodeAtRight = findtargetNode(root->right, target);
        if(nodeAtRight != NULL)
            return nodeAtRight;
    }
public:
    vector <int> KDistanceNodes(Node* root, int target , int k) //tweaking in BFS/level-order
    {
        if(root == NULL)
            return {};
            
        storeParentofAllNodes(root, NULL); //root node's parent is NULL
        Node* targetNode = findtargetNode(root, target);
        if(targetNode == NULL)
            return {};
            
        //Distance-level Order Traversal
        vector<int> KDistanceOT;
        queue<pair<Node*, int>> q;
        int dist = 0;
    
        q.push({targetNode, dist}); //first push the root and distance 0
        visited.insert(targetNode);
        while(! q.empty())
        {
            int nodesAtDistancedist = q.size();
        
            for(int i=0; i<nodesAtDistancedist; i++)
            {
                pair<Node*, int> tempPair = q.front();
                q.pop();
                Node* tempNode = tempPair.first;
                dist = tempPair.second;
                

                if(dist==k)
                    KDistanceOT.push_back(tempNode->data); //traversing all horizontal nodes at K level from root
                else if(dist > k)     //OPTIMIZATION :)
                {
                    sort(KDistanceOT.begin(), KDistanceOT.end());
                    return KDistanceOT;
                }
                    

                if(tempNode->left!=NULL && visited.find(tempNode->left)==visited.end())
                {
                    q.push({tempNode->left, dist+1});
                    visited.insert(tempNode->left);
                }
                if(tempNode->right!=NULL && visited.find(tempNode->right)==visited.end())
                {
                    q.push({tempNode->right, dist+1});
                    visited.insert(tempNode->right);
                }
                if(mp[tempNode]!=NULL && visited.find(mp[tempNode])==visited.end())
                {
                    q.push({mp[tempNode], dist+1});
                    visited.insert(mp[tempNode]);
                }
            }
        }
        sort(KDistanceOT.begin(), KDistanceOT.end());
        return KDistanceOT;
    }
};