bool detectLoop(Node* head)
{
    Node *p = head;
    Node *q = head;
    do
    {
        p = p->next;
        q = q->next;
        if(q)
            q = q->next;
    }
    while(p!=0 && q!=0 && p!=q);
    
    if(p == q)
        return true;
    else
        return false;
}