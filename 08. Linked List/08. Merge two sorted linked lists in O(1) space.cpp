/*
Input:
	head_A -> 5 -> 10 -> 15 -> 40
	head_B -> 2 -> 3 -> 20
Output: 
   newhead -> 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
*/

Node* sortedMerge(Node* head1, Node* head2)  
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