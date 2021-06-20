/*Given a linked list of N nodes. The task is to check if the linked list has a loop. 
Linked list can contain self loop.

Input:
N = 3
value[] = {1,3,4}
x = 2
Output: True
Explanation: In above test case N = 3. The linked list with nodes N = 3 is given. 
Then value of x=2 is given which means last node is connected with xth node of linked list. 
Therefore, there exists a loop. */

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(head==NULL || head->next==NULL) //length 0 or 1
            return false;
            
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        return false;
    }
};