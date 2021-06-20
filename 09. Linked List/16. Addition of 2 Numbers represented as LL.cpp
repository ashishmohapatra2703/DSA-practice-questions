/*Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. 
The most significant node is the first node and the least significant digit is the last node.
The sum list is a linked list representation of the addition of two input numbers from the last.

Input:
N = 2                                     4->5
valueN[] = {4,5}                  (+)  3->4->5 
M = 3                               ------------
valueM[] = {3,4,5}           sumHead-> 3->9->0   
Output: 3 9 0  
Explanation: For the given two linkedlist (4 5) and (3 4 5), 
after adding the two linked list resultant linkedlist will be (3 9 0). */

// Time Complexity: O(N+M)
// Auxiliary Space: O(Max(N,M))

//M-1 (using Reverse of LL)
class Solution
{
    public:
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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first==NULL)
            return second;
        else if(second==NULL)
            return first;
            
        first = reverseLL(first);   //5->4       num1 is  45
        second = reverseLL(second); //5->4->3    num2 is 345
        Node* firstItr = first;
        Node* secondItr = second;
        
        Node* sumDummyHead = new Node(-1);
        Node* sumItr = sumDummyHead;
        int carry = 0;
        
        while(firstItr!=NULL || secondItr!=NULL || carry!=0)
        {
            int sumItrData = ((firstItr!=NULL) ? firstItr->data : 0) +
                             ((secondItr!=NULL) ? secondItr->data : 0) + carry;
                             
            sumItr->next = new Node(sumItrData % 10);// % 10 -> to get the 10th place digit of the sumData
            carry = sumItrData / 10; // / 10 -> to get the unit place digit of the sumData
            //sumData always lies between 0 to 19
 
            if(firstItr!=NULL)
                firstItr = firstItr->next;
            if(secondItr!=NULL)
                secondItr = secondItr->next;
            sumItr = sumItr->next;
        }
        //loop terminates when all 3 firstItr==NULL & secondItr==NULL & carry==0
        
        Node* sum = sumDummyHead->next;
        sum = reverseLL(sum);
        return sum;
    }
};