/* Serialization is to store a tree in an array so that it can be later restored and 
Deserialization is reading tree back from the array. 

Now your task is to complete the function serialize which stores the tree into an array A[ ] 
and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
Your Task:
The task is to complete two function serialize which takes the root node of the tree as input 
and stores the tree into an array and deSerialize which deserializes the array to the original tree 
and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */


class Solution{
private:
    vector<int> srlArr;
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        if(root==NULL)
        {
            srlArr.push_back(-1);
            return srlArr;
        }
        
        srlArr.push_back(root->data);
        
        serialize(root->left);
        serialize(root->right);
        return srlArr;
    }
    
    Node* deSerializeBT(vector<int> &arr, int &itr)
    {
        if(arr[itr] == -1)
        {
            itr++;
            return NULL;
        }
        
        Node* root = new Node(arr[itr]);
        itr++;
        
        root->left = deSerializeBT(arr, itr);
        root->right = deSerializeBT(arr, itr);
        return root;
    }
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        int itr = 0; 
        return deSerializeBT(A, itr);
    }
};


// or using helper recursive function
class Solution{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void serializeBT(Node* root, vector<int> &srlArr)
    {
        if(root==NULL)
        {
            srlArr.push_back(-1);
            return;
        }
        
        srlArr.push_back(root->data);
        
        serializeBT(root->left, srlArr);
        serializeBT(root->right, srlArr);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> srlArr;
        serializeBT(root, srlArr);
        return srlArr;
    }
    
    
    Node* deSerializeBT(vector<int> &arr, int &itr)
    {
        if(itr == arr.size())
        {
            return NULL;
        }
        if(arr[itr] == -1)
        {
            itr++;
            return NULL;
        }
        
        Node* root = new Node(arr[itr]);
        itr++;
        
        root->left = deSerializeBT(arr, itr);
        root->right = deSerializeBT(arr, itr);
        return root;
    }
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        int itr = 0; 
        return deSerializeBT(A, itr);
    }
};