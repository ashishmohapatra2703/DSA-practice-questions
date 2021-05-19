/*Given Pointer/Reference to the head of the linked list, 
the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, 
then the extra node should go in the first list while splitting. */
class Solution{
  public:
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
    Node* merge2sortedLL(Node* &head1, Node* &head2)  
    {  
        if(head1==NULL)
            return head2;
        else if(head2==NULL)
            return head1;
            
            
        Node* dummyhead3 = new Node(-1);
        
        Node* i = head1;
        Node* j = head2;
        Node* k = dummyhead3;
        
        while(i!=NULL && j!=NULL)
        {
            if(i->data <= j->data)
            {
                k->next = i;
                k = k->next;
                i = i->next;
            }
            else if(j->data < i->data)
            {
                k->next = j;
                k = k->next;
                j = j->next;
            }
        }
        
        if(i!=NULL)
            k->next = i;
        else if(j!=NULL)
            k->next = j;
            
            
        Node* head3 = dummyhead3->next;
        return head3;
    } 

    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) 
    {
        if(head->next == NULL) //length 1 LL is itself sorted
            return head;
            
        Node* midNode = getMiddleNode(head);
        Node* head2 = midNode->next;
        midNode->next = NULL; //spliting the LL into 2 halves 
        // *head pointing to 1st half and *head2 pointing to 2nd half of LL
        
        head = mergeSort(head);
        head2 = mergeSort(head2);
        return head = merge2sortedLL(head, head2);
    }
};