/*Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.
Input:                               
           7                -->
        /     \
       9       7		   <---
     /  \     /   
    8    8   6          ---------->
   /  \
  10   9             <------------------
Output:
7 7 9 8 8 6 9 10    */

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
	stack<Node*> s1;
	stack<Node*> s2;
	vector<int> ZZT;
	
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
	    while(!s1.empty())
	    {
	        Node* temp = s1.top();
	        s1.pop();
	        ZZT.push_back(temp->data);
	        
	        if(temp->left != NULL)
                s2.push(temp->left);
            
            if(temp->right != NULL)
                s2.push(temp->right);
	    }
	    
	    while(!s2.empty())
	    {
	        Node* temp = s2.top();
	        s2.pop();
	        ZZT.push_back(temp->data);
	        
	        if(temp->right != NULL)
                s1.push(temp->right);
            
            if(temp->left != NULL)
                s1.push(temp->left);
	    }
	}
	return ZZT;
}


/* if asked in reverse sprial 
	    <-
	    -->
	  <------
	 ---------->  */
vector<int> findSpiral(Node *root)
{
    if(root == NULL)
        return {};
        
    stack<Node*> s1;
	stack<Node*> s2;
	vector<int> ZZT;
	
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
	    while(!s1.empty())
	    {
	        Node* temp = s1.top();
	        s1.pop();
	        ZZT.push_back(temp->data);
	        
	        if(temp->right != NULL)   
                s2.push(temp->right);
            //swapped the order as R-L
            if(temp->left != NULL)
                s2.push(temp->left);
	    }
	    
	    while(!s2.empty())
	    {
	        Node* temp = s2.top();
	        s2.pop();
	        ZZT.push_back(temp->data);
	        
	        if(temp->left != NULL) 
                s1.push(temp->left);
           	//swapped the order as L-R
            if(temp->right != NULL)
                s1.push(temp->right);
	    }
	}
	return ZZT;
}
