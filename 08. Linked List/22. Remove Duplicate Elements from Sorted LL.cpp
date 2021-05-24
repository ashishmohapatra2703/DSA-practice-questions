/*Given a singly linked list consisting of N nodes. 
The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). 
The nodes are arranged in a sorted way.

Input:
LinkedList: 2->2->2->4->5
Output: 2->4->5  */

void addLast(Node* &currentNode, Node* &tempHead, Node* &tempTail)
{
    if(tempTail == NULL)
    {
        tempHead = tempTail = currentNode;
    }
    else
    {
        tempTail->next = currentNode;
        tempTail = currentNode;
    }
}
//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    Node* tempHead = NULL;
    Node* tempTail = NULL;

    if(head==NULL || head->next==NULL) //length 0 or 1
        return head;
            
    Node* forward = head;
    Node* current = NULL;

    while(forward != NULL)
    {
        current = forward;    //following pointers
        forward = forward-> next; 
        current->next = NULL; //breaking the link
        
        if(tempTail==NULL  || current->data != tempTail->data)
            addLast(current, tempHead, tempTail);
        else if(current->data == tempTail->data)
            delete current;
    }
    return tempHead;
}