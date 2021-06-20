/*Given a Linked List of integers, write a function to modify the linked list such that 
all even numbers appear before all the odd numbers in the modified linked list. 
Also, keep the order of even and odd numbers same.

Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL

Input: 8->12->10->NULL
Output: 8->12->10->NULL  If all numbers are even then do not change the list

Input: 1->3->5->7->NULL
Output: 1->3->5->7->NULL  If all numbers are odd then do not change the list          */

class Solution{
public:
    Node* divide(int N, Node *head)
    {
        if(N==0||N==1)
            return head;
            
            
        Node* dummyEvenHead = new Node(0);
        Node* evenTail = dummyEvenHead;
        
        Node* dummyOddHead = new Node(0);
        Node* oddTail = dummyOddHead;
        
        Node* current = head;
        while(current != NULL)
        {
            if(current->data % 2 ==0)
            {
                evenTail->next = current;
                evenTail = evenTail->next;
                current = current->next;
            }
            else if(current->data % 2 !=0)
            {
                oddTail->next = current;
                oddTail = oddTail->next;
                current = current->next;
            }
        }
        
        evenTail->next = dummyOddHead->next; //linking even segment to odd segment  (evenTail to oddHead)
        oddTail->next = NULL; //end of required LL
        
        return dummyEvenHead->next;
    }
};