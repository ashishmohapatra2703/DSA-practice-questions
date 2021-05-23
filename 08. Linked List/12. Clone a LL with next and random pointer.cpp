/*You are given a Double Link List with 
one pointer of each node pointing to the next node just like in a single link list. 
The second pointer however CAN point to any node in the list and not just the previous node.
Now write a program in O(n) time to duplicate this list. 
That is, write a program which will create a copy of this list.
Let us call the second pointer as arbit pointer as it can point to any arbitrary node in the linked list. */

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
//Method-1 USING HASHMAP
// Should return the head of the copied linked list, the output will be 1 if successfully copied
Node* copyList(Node* head) 
{
    unordered_map<Node*, Node*> mp; //Hash map which contains node to node mapping of original and clone LL
    
    Node* ogCurrent = head;
    
    Node* dummyCloneHead = new Node(-1);
    Node* cloneTail = dummyCloneHead;
    
    while(ogCurrent != nullptr)
    {
        Node* deepCopyNode = new Node(ogCurrent->data);
        mp[ogCurrent] = deepCopyNode;
        cloneTail->next = deepCopyNode;
        
        cloneTail = cloneTail->next;
        ogCurrent = ogCurrent->next;
    }
    
    Node* cloneHead = dummyCloneHead->next; 
    
    ogCurrent = head; //re-assigning it to head node of original LL
    Node* cloneCurrent = cloneHead;  //2 pointers = ogCurrent & cloneCurrent
    
    while(ogCurrent != nullptr) // or cloneCurrent != nullptr is same terminating condition
    {
        cloneCurrent->arb = (ogCurrent->arb != NULL) ? mp[ogCurrent->arb] : NULL;
        
        ogCurrent = ogCurrent->next;
        cloneCurrent = cloneCurrent->next;
    }
    return cloneHead;
}

/*
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
} */



//METHOD-2 WITHOUT USING ANY EXTRA SPACE

/* Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};*/
class Solution {
public:
    void copyLLNodes_InsertingBetween(Node* head)
    {
        Node* forward = head;
        Node* current = NULL;
        while(forward != NULL)
        {
            current = forward;
            forward = forward->next;
            
            Node* copyNode = new Node(current->val);
            current->next = copyNode;
            copyNode->next = forward;
        }
    }
    void copyRandomPointers_OriginalToClone(Node* head)
    {
        Node* current = head;
        while(current != NULL)
        {
            if(current->random != NULL)
                current->next->random = current->random->next;
            else
                current->next->random = NULL;
            
            current = current->next->next;
        }
    }
    Node* linearConnectCopyLL_SeparatingFromOriginal(Node* head)
    {
        Node* dummyCloneHead = new Node(-1);
        Node* cloneTail = dummyCloneHead;
        
        Node* current = head;
        while(current != NULL)
        {
            cloneTail->next = current->next;
            current->next = current->next->next;
            
            cloneTail = cloneTail->next;
            current = current->next;
        }
        
        return dummyCloneHead->next;
    }

    
    Node* copyRandomList(Node* head) 
    {
        copyLLNodes_InsertingBetween(head);
        copyRandomPointers_OriginalToClone(head);
        Node* cloneLLHead = linearConnectCopyLL_SeparatingFromOriginal(head);
        return cloneLLHead;
    }
};