class Solution{
  public:
    Node* reverseList(Node* head)
    {
        if(head==nullptr || head->next==nullptr) //length 0 or 1
            return head;
                
        Node* forward = head;
        Node* current = nullptr;
        Node* previous = nullptr;
            
        while(forward != nullptr)
        {
            previous = current;
            current = forward;
            forward = forward->next;
                
            current->next = previous;
        }
        return head = current;
    }
    Node* getMiddleNode(Node* &head)
    {
        if(head==nullptr || head->next==nullptr) //length 0 or 1
            return head;
            
        Node* slow = head;
        Node* fast = head;
       
        //if odd length => return the middle element
        //if even length => return 1st middle element out of 2
        while(fast->next!=NULL && fast->next->next!=NULL) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* midNode = getMiddleNode(head); //using hare and tortoise method
    
        Node* head2 = midNode->next;
        midNode->next = NULL; //spliting the LL into 2 halves 
        
        // *head pointing to 1st half and *head2 pointing to 2nd half of LL
        head2 = reverseList(head2); //reversing the second half
        
        
        //checking for palindrome Algo.
        bool isPalindrome = true;
        Node* i = head;
        Node* j = head2;
        
        //use while(i != NULL && j != NULL) but
        /* since the 2nd half length will always be less than/ = to to the 1st half length
            (in odd and even length LL respectively)
        => adding i != NULL condition is not redundant */
        while(j != NULL)
        {
            if(i-> data != j-> data)
            {
                isPalindrome = false;
                break;
            }
            
            i = i->next; //i++
            j = j->next; //j++
        }
        head2 = reverseList(head2);
        midNode->next = head2; //preserving the original LL order
        
        return isPalindrome;
    }
};