//M-2 Space-Optimized Solution :) 
// Time Complexity: O(n1+n2)  Space Complexity: O(h1+h2)
// do iterative inorder traversal of both the binary search tree and merge them.

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> mergeinOT;
        stack<pair<Node*, int>> s1;
        stack<pair<Node*, int>> s2;
        
        s1.push({root1, 0});
        s2.push({root2, 0});
        while(!s1.empty() and !s2.empty())
        {
            pair<Node*, int> currPair1 = s1.top();
            s1.pop();
            Node* currNode1 = currPair1.first;
            int currState1 = currPair1.second;
            
            pair<Node*, int> currPair2 = s2.top();
            s2.pop();
            Node* currNode2 = currPair2.first;
            int currState2 = currPair2.second;
                
            if((currNode1==NULL or currState1==3) or 
                (currNode2==NULL or currState2==3) )
                continue;
                
            s1.push({currNode1, currState1+1});
            s2.push({currNode2, currState2+1});
            
            if(currState1==0)
                s1.push({currNode1->left, 0});
            if(currState2==0)
                s2.push({currNode2->left, 0});
             
            if(currState1==1 or currState2==1)   
            {
                if(currNode1->data < currNode2->data)
                    mergeinOT.push_back(currNode1->data);
                else if(currNode1->data > currNode2->data)
                    mergeinOT.push_back(currNode2->data);
                else if(currNode1->data == currNode2->data)
                {
                    mergeinOT.push_back(currNode1->data);
                    mergeinOT.push_back(currNode2->data);
                }
            }
               
            if(currState1==2)
                s1.push({currNode1->right, 0});
            if(currState2==2)
                s2.push({currNode2->right, 0}); 
        }

    
    while(! s1.empty())
        {
            pair<Node*, int> currPair1 = s1.top();
            s1.pop();
            Node* currNode1 = currPair1.first;
            int currState1 = currPair1.second;
            
            if(currNode1==NULL or currState1==3)
                continue;
            
            s1.push({currNode1, currState1+1});
            
            if(currState1==0)
                s1.push({currNode1->left, 0});
            else if(currState1==1)
                mergeinOT.push_back(currNode1->data);
            else if(currState1==2)
                s1.push({currNode1->right, 0});
        }
        
        while(! s2.empty())
        {
            pair<Node*, int> currPair2 = s2.top();
            s2.pop();
            Node* currNode2 = currPair2.first;
            int currState2 = currPair2.second;
            
            if(currNode2==NULL or currState2==3)
                continue;
            
            s2.push({currNode2, currState2+1});
            
            if(currState2==0)
                s2.push({currNode2->left, 0});
            else if(currState2==1)
                mergeinOT.push_back(currNode2->data);
            else if(currState2==2)
                s2.push({currNode2->right, 0});
        }
         return mergeinOT;
    }
    
};