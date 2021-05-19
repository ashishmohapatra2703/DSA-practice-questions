/*Input: Head of following linked list 
1->2->3->4->5->NULL 
Output: Linked list should be changed to, 
5->4->3->2->1->NULL
 */
//Mrthod-1
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


//Method-2
class Solution{
public:
    Node* tempHead = NULL;
    Node* tempTail = NULL;
    void addFirst(Node* &currentNode)
    {
        if(tempHead == NULL)
        {
            tempHead = currentNode;
            tempTail = currentNode;
        }
        else
        {
            currentNode->next = tempHead;
            tempHead = currentNode;
        }
    }
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* forward = head;
        Node* current = NULL;

        while(forward != NULL)
        {
            current = forward;
            forward = forward-> next;
            current->next = NULL; //breaking the link
            addFirst(current);  //and adding it to the tempHead (cut-paste)
        }
        return tempHead;
    }
};