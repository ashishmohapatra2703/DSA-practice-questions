/*
Input:
	head_A -> 5 -> 10 -> 15 -> 40
	head_B -> 2 -> 3 -> 20
Output: 
   newhead -> 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
*/
Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    Node *newhead = nullptr;
    Node *newlast = nullptr;
    
    if(head_A->data <= head_B->data)
    {
        newhead = newlast = head_A;
        head_A = head_A->next;
        newlast->next = nullptr;
    }
    else if(head_B->data < head_A->data)
    {
        newhead = newlast = head_B;
        head_B = head_B->next;
        newlast->next = nullptr;
    }
    
    while(head_A!=NULL && head_B!=NULL)
    {
        if(head_A->data <= head_B->data)
        {
            newlast->next = head_A;
            newlast = newlast->next; // or newlast = head_A;
            head_A = head_A->next;
            newlast->next = nullptr;
        }
        else if(head_B->data < head_A->data)
        {
            newlast->next = head_B;
            newlast = newlast->next;// or newlast = head_B;
            head_B = head_B->next;
            newlast->next = nullptr;
        }
    }
    while(head_A!=NULL)
    {
        newlast->next = head_A;
        newlast = head_A;
        head_A = head_A->next;
        newlast->next = nullptr;
    }
    while(head_B!=NULL)
    {
        newlast->next = head_B;
        newlast = head_B;
        head_B = head_B->next;
        newlast->next = nullptr;
    }
    return newhead;
}  