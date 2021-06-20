/*Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
Notice that you should not modify the linked list. */

class Solution {
public:
    ListNode* detectCycle(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) //length 0 or 1
            return NULL;
            
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        if(slow != fast) //if linear LL
            return NULL;
        
        slow = head; 
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow; //or return fast
    }
};