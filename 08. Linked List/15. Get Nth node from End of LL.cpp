/*Given a linked list consisting of L nodes and given a number N. 
The task is to find the Nth node from the end of the linked list.
need to return Nth from the end or -1 in case node doesn't exist. [note:-solve in single traversal]
Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there are 9 nodes in linked list and 
we need to find 2nd node from end. 2nd node from end is 8.  

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there are 4 nodes in the linked list and 
we need to find 5th from the end. Since 'n' is more than the number of nodes in the LL, the output is -1.  */

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    Node* nthForward = head;
    Node* current = head;
    
    for(int i=0; i<n; i++)  //traversing first n elements with nthForward pointer.
    {
        if(nthForward == NULL) //if n > size of LL
            return -1;
        else
            nthForward = nthForward->next;
    }
    ////now traversing with both pointers and when nthForward pointer gives null 
    //we have got the nth node from end in current pointer since the nthForward pointer
    //had already traversed n nodes and thus had difference of n nodes with current pointer.
	while(nthForward != NULL)
    {
        nthForward = nthForward->next;
        current = current->next;
    }
    
    return current->data;
}