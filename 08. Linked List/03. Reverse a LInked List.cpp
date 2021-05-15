/*Input: Head of following linked list 
1->2->3->4->5->NULL 
Output: Linked list should be changed to, 
5->4->3->2->1->NULL
 */
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
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
        head = current;
        return head;
    }
    
};