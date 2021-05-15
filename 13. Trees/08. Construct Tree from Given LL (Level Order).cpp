/*Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i,
 its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
 Input:
		N = 5
		K = 1->2->3->4->5
Output:    1 2 3 4 5  => i.e, level order traversal of the above tree
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5             */

void convert(Node* head, TreeNode* &root) 
{
    if(head == nullptr)
        return;
        
    queue<TreeNode*> q;
    
    root = new TreeNode(head->data);
    q.emplace(root);
    
    while(!q.empty())
    {
        TreeNode* t = q.front();
        q.pop();
        
        if(head->next != nullptr)
        {
            head = head->next;
            t->left = new TreeNode(head->data);
            q.emplace(t->left);
        }
        
        if(head->next != nullptr)
        {
            head = head->next;
            t->right = new TreeNode(head->data);
            q.emplace(t->right);
        }
    }
}