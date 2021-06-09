/*  You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it  successfully, the answer will be 1.  */

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL) //length 0 or 1
            return;
            
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        if(slow != fast) //if linear LL
            return;
        
        
    //special case (when head is the entrance node of loop and also the meeting point)
        if(slow==head && fast==head) 
        {
            while(slow->next != fast)
            {
                slow = slow->next;
            }
            slow->next = NULL;
        }
        else
        {
            slow = head; 
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL; //breaking the loop at the entrance node of loop
        }
    }
};