/*A linked list L0 -> L1 -> L2 -> ….. -> LN can be 
      folded as L0 -> LN -> L1 -> LN – 1 -> L2 -> ….. 
Given a folded linked list, the task is to unfold and print the original linked list

Input: 1 -> 6 -> 2 -> 5 -> 3 -> 4 
Output: 1 2 3 4 5 6

Input: 1 -> 5 -> 2 -> 4 -> 3 
Output: 1 2 3 4 5   */

ListNode* reverseList(ListNode* head)
{
    if(head==nullptr || head->next==nullptr) //length 0 or 1
        return head;
            
    ListNode* forward = head;
    ListNode* current = nullptr;
    ListNode* previous = nullptr;
        
    while(forward != nullptr)
    {
        previous = current;
        current = forward;
        forward = forward->next;
            
        current->next = previous;
    }
    return head = current;
}


void unfold(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return;
        
    ListNode* head1 = head;
    ListNode* head2 = head->next;
    
    ListNode* current1 = NULL;
    ListNode* forward1 = head1;
    ListNode* current2 = NULL;
    ListNode* forward2 = head2;
    
    //terminating condition for odd and even length LL respectively.
    while(forward2!= NULL && forward2->next!=NULL)
    {
        current1 = forward1;
        forward1 = forward1->next->next;
        current1->next = forward1;
        
        current2 = forward2;
        forward2 = forward2->next->next;
        current2->next = forward2;
    }
    
    forward1->next = NULL; //breaking the link of 2 halves
    
    head2 = reverseList(head2);
    forward1->next = head2;
}