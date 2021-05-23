/*Given two linked lists that represent two large positive numbers. 
The task is to subtract the given two numbers represented by the linked list. 
Subtract the smaller from the larger one.

Input:
L1 = 1->0->0
L2 = 1->2
Output: 8 8
Explanation:  12 subtracted from 100 gives us 88 as result. */

Node* reverseLL(Node* head)
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
    return head = current;
}
int getLengthofLL(Node* p)
{
    int len = 0;
    while(p!=NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
void swapPointers(Node* &a, Node* &b) 
{ 
    Node* temp = a; 
    a = b; 
    b = temp; 
}
Node* getGreaterValueLL(Node* head1, Node* head2)
{
    Node* itr1 = head1;
    Node* itr2 = head2;
       
    while(itr1!=NULL)
    {
        if(itr1->data > itr2->data)
            return head1;
        else if(itr1->data < itr2->data)
            return head2;
        else if(itr1->data == itr2->data)
        {
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
    }
    return NULL; //when l1 and l2 are exactly same
}
void deleteStartingZeros(Node* &itr)
{
    while(itr!= NULL && itr->data == 0)
    {
        Node* next = itr->next; //discarding the initial zeros if any
        delete (itr);
        itr = next;
    }
    //pass by reference => because 
    //to make sure itr will also move the 'actual head of the LL' to first non-zero value
}


//You are required to complete this method
Node* subLinkedList(Node* l1, Node* l2)
{
    if(l2 == NULL)
        return l1; //x-0 = x
    
    deleteStartingZeros(l1);
    deleteStartingZeros(l2);
    
    int size1 = getLengthofLL(l1);
    int size2 = getLengthofLL(l2);
    
    if(size1 < size2)
        swapPointers(l1, l2); 
    else if(size1 == size2)    
    {
        if(l1 == getGreaterValueLL(l1, l2))
        { 
            //as it should be
        }
        else if(l2 == getGreaterValueLL(l1, l2))
        {
            swapPointers(l1, l2); 
        }
        else if(NULL == getGreaterValueLL(l1, l2))
        {
            return new Node(0); //when l1 and l2 are exactly same
        }
    }
    
    
    l1 = reverseLL(l1);   //0->0->1    num1 is 100
    l2 = reverseLL(l2);   //2->1       num2 is 12

    Node* firstItr = l1;
    Node* secondItr = l2;
        
    Node* diffDummyHead = new Node(-1);
    Node* diffItr = diffDummyHead;
    int borrow = 0;
    
    while(firstItr!=NULL)
    {
        int diffItrData = borrow + firstItr->data - ((secondItr!=NULL) ? secondItr->data : 0);

        if(diffItrData >=0)
        {
            diffItr->next = new Node(diffItrData);
            borrow = 0;
        }
        else if(diffItrData < 0)
        {
            diffItr->next = new Node(diffItrData + 10);
            borrow = -1;
        }
        
        firstItr = firstItr->next;
        if(secondItr!=NULL)
            secondItr = secondItr->next;
        diffItr = diffItr->next;
    }
    
    Node* diff = diffDummyHead->next;
    diff = reverseLL(diff);
    deleteStartingZeros(diff);
        
    return diff;
}