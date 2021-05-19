// Function Problem on gfg
/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node* copyList(Node *head) 
{
    Node *p = head;
    
    unordered_map<Node*, Node*> mp; //Hash map which contains node to node mapping of original and clone LL
    
    while(p!=nullptr)
    {
        Node *q = new Node(p->data);
        mp[p] = q;
        p = p->next;
    }
    p = head; //again assigning it to head node of original LL
    
    Node *clone_head = mp[p]; 
    
    while(p!=nullptr)
    {
        Node *q = mp[p];
        q->next = mp[p->next];
        q->arb = mp[p->arb];
        p = p->next; 
    }
    
    return clone_head;
}