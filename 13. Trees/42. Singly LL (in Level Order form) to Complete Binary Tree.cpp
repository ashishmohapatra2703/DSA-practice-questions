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

//M-1
//Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) 
{
    if(head == nullptr)
        return;
        
    queue<TreeNode*> q;
    
    root = new TreeNode(head->data);
    q.push(root);
    head = head->next;
    while(!q.empty())
    {
        TreeNode* t = q.front();
        q.pop();
        
        if(head != NULL)
        {
            t->left = new TreeNode(head->data);
            q.push(t->left);
            head = head->next;
        }
        
        if(head != NULL)
        {
            t->right = new TreeNode(head->data);
            q.push(t->right);
            head = head->next;
        }
    }
}



//M-2
void convert(Node *head, TreeNode *&root) 
{
    vector<TreeNode*> lvlorderT;
    
    Node* LLitr = head;
    while(LLitr != NULL)
    {
        TreeNode* treeNode = new TreeNode(LLitr->data);
        lvlorderT.push_back(treeNode);
        
        LLitr = LLitr->next;
    }
    
    int NodeCount = lvlorderT.size();
    root = lvlorderT[0];
    for(int i=0; i<=NodeCount/2; i++)
    {
        if(2*i+1 < NodeCount)
            lvlorderT[i]->left = lvlorderT[2*i+1];
        if(2*i+2 < NodeCount)
            lvlorderT[i]->right = lvlorderT[2*i+2];
    }
}
