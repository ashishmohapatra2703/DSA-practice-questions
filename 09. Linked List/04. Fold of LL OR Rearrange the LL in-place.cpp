/*Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. 
Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …
You are required to do this in place without altering the nodes’ values. 

Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3   */

//Time Complexity: O(2*N)
//Auxiliary Space: O(1)

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


void reorderList(Node* head) 
{
    Node* midNode = getMiddleNode(head); //using hare and tortoise method
    
    Node* head2 = midNode->next;
    midNode->next = NULL; //spliting the LL into 2 halves 
    
    // *head pointing to 1st half and *head2 pointing to 2nd half of LL
    
    head2 = reverseList(head2); //reversing the second half
    
    
    //Folding Algo.
    Node* current1 = NULL;
    Node* forward1 = head;
    Node* current2 = NULL;
    Node* forward2 = head2;
    
    //use while(forward1 != NULL && forward2 != NULL) but
    /* since the 2nd half length will always be less than/ = to to the 1st half length
        (in odd and even length LL respectively)
    => adding forward1 != NULL condition is not redundant */
    while(forward2 != NULL)
    {
        current1 = forward1;
        forward1 = forward1->next;
        current2 = forward2;
        forward2 = forward2->next;
        
        current1->next = current2;
        current2->next = forward1;
    }
}