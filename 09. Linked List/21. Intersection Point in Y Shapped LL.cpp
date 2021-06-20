/*Given two singly linked lists of size N and M, 
write a program to get the point where two linked lists intersect each other.
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15               
Note that the linked lists must retain their original structure after the function returns.*/

//Method-1    [Using Floyd's Cycle Algorithm]
int findStartingNodeofLoopInaLL(Node* head) 
{
    if(head==NULL || head->next==NULL) //length 0 or 1
        return -1;
            
    Node* slow = head;
    Node* fast = head;
        
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast)
            break;
    }
    
    if(slow != fast) //if linear LL
        return -1;

    slow = head; 
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data; //or return fast
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    Node* tail1 = head1;
    while(tail1->next != NULL)
        tail1 = tail1->next;
    tail1->next = head1;
    
    int interSectionPointinYshappedLL = findStartingNodeofLoopInaLL(head2); //starting from head2
    
    tail1->next = NULL; //preserving the original LL

    return interSectionPointinYshappedLL;
}
/* OR 
tail1->next = head2;
int interSectionPointinYshappedLL = findStartingNodeofLoopInaLL(head1);
tail1->next = NULL;  */



//Method-2   [Using difference of node counts]
int getLengthofLL(Node* head) 
{
    int len = 0;
    Node* itr;
    for(itr = head; itr!=NULL; itr=itr->next)
        len++;
    return len;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int len1 = getLengthofLL(head1);
    int len2 = getLengthofLL(head2);
    
    for(  ; len1>len2 ; len1-- ) //if list1 is longer
        head1 = head1->next;  //terminating condition is len1 == len2
    
    for(  ; len2>len1 ; len2-- ) //if list2 is longer
        head2 = head2->next;
        
    while(head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return (head1!=NULL) ? head1->data : -1;
}
/*Get count of the nodes in the first list, let be c1.
Get count of the nodes in the second list, let be c2.
Get the difference of counts d = abs(c1 – c2).
Now traverse the bigger list from the first node till d nodes so that 
from here onwards both the lists have equal no of nodes.
Then we can traverse both the lists simultaneously till we come across a common node. */ 