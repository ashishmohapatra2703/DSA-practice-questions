/*Given a Two Binary Trees, 
write a function that returns true if one is mirror of other, else returns false.
Input:
T1:     1     T2:     1
      /   \         /   \
     2     3       3     2
Output: 1                       */

// Given two trees, should return true if they are mirror of each other.
class Solution
{
    public:
    int areMirror(Node* a, Node* b) 
    {
        if(a==NULL && b==NULL)  //both NULL
            return true;
        if(a==NULL || b==NULL)  //any one is NULL
            return false;
        if(a->data != b->data) //if above both conditions are not the case,
            return false;       //then check if both datas are equal or not
            
        if(areMirror(a->left, b->right) == true &&
            areMirror(a->right, b->left) == true)
            return true;   //recur for checking in left and right subtree
        else
            return false;
    }
};
