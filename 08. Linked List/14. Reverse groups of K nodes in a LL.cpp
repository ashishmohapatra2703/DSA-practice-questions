/*Given a linked list, 
write a function to reverse every k nodes (where k is an input to the function). 
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL.  */

class Solution{
public:
    node* tempHead = NULL;
    node* tempTail = NULL;
    node* originalHead = NULL;
    node* originalTail = NULL;
    
    void addFirst(node* &currentNode)
    {
        if(tempHead == NULL)
        {
            tempHead = currentNode;
            tempTail = currentNode;
        }
        else
        {
            currentNode->next = tempHead;
            tempHead = currentNode;
        }
    } 
    int getLengthofLL(node* p)
    {
        int len = 0;
        while(p!=NULL)
        {
            p = p->next;
            len++;
        }
        return len;
    }

    struct node* reverse (struct node* head, int k)
    { 
        if(head==NULL || head->next==NULL || k==0)
            return head;
            
        int length = getLengthofLL(head);
        node* current = NULL;
        node* forward = head;
        
        for(int len=0; len<=length; len+=k) //or for(int len=length; len>=0; len-=k)
        {
            int group = k;
            for(int i=0; i<k && forward!=NULL; i++)
            {
                current = forward;    //following pointers
                forward = forward-> next; 
                current->next = NULL; //breaking the link
                addFirst(current);  //and adding it to the tempHead (cut-paste)
            }
            if(originalHead == NULL)
            {
                originalHead = tempHead;
                originalTail = tempTail;
                tempHead = NULL;
                tempTail = NULL;
            }
            else
            {
                originalTail->next = tempHead;
                originalTail = tempTail;
                tempHead = NULL;
                tempTail = NULL;
            }
        }
        return originalHead;
    }
};