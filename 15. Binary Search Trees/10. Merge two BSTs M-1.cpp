/*Given two BSTs, return elements of both BSTs in sorted form.
return an array of integers denoting the node values of both the BSTs in a sorted order.
Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7

Expected Time Complexity: O(n1 + n2) where n1 and n2 are the sizes if the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2).
Constraints:
1 <= Number of Nodes <= 100000		*/


//M-1  Time Complexity: O(n1+n2)  Space Complexity: O(n1+n2) 
//  traverse both the tree in inorder traversal and store them and then merge them. 
class Solution{
public:
    vector<int> mergeTwoSortedArrays(vector<int> &inOT1, vector<int> &inOT2)
    {
        vector<int> merge;
        
        int i=0;
        int j=0;
        while(i<inOT1.size() && j<inOT2.size())
        {
            if(inOT1[i] < inOT2[j])
                merge.push_back(inOT1[i++]);
            else if(inOT2[j] < inOT1[i])
                merge.push_back(inOT2[j++]);
            else if(inOT1[i] == inOT2[j])
            {
                merge.push_back(inOT1[i++]);
                merge.push_back(inOT2[j++]);
            }
        }
        
        while(i<inOT1.size())
            merge.push_back(inOT1[i++]);
        while(j<inOT2.size())
            merge.push_back(inOT2[j++]);
            
        return merge;
    }
    void inorderTraversal(Node* node, vector<int> &InOT) //pass by reference
    {
        if(node == NULL)
            return;
            
        inorderTraversal(node->left, InOT);
        InOT.push_back(node->data);
        inorderTraversal(node->right, InOT);
    }

    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> inOT1;
        inorderTraversal(root1, inOT1);
        vector<int> inOT2;
        inorderTraversal(root2, inOT2);
        
        return mergeTwoSortedArrays(inOT1, inOT2);
    }
};