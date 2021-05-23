/*Given K sorted linked lists of different sizes(Max size = N)
The task is to merge them in such a way that after merging they will be a single sorted linked list.

Input: k = 3, n =  4
list1 = 1->3->5->7->NULL
list2 = 2->4->6->8->NULL
list3 = 0->9->10->11->15->19->NULL

Output: 0->1->2->3->4->5->6->7->8->9->10->11->15->19->NULL   */

//M-1  Brute Force   T.C = O(N. K²)
class Solution{
  public:
    Node* merge2sortedLL(Node* &head1, Node* &head2)  
    {  
        if(head1==NULL)
            return head2;
        else if(head2==NULL)
            return head1;
            
            
        Node* dummyhead3 = new Node(-1);
        
        Node* i = head1;
        Node* j = head2;
        Node* k = dummyhead3;
        
        while(i!=NULL && j!=NULL)
        {
            if(i->data <= j->data)
            {
                k->next = i;
                k = k->next;
                i = i->next;
            }
            else if(j->data < i->data)
            {
                k->next = j;
                k = k->next;
                j = j->next;
            }
        }
        
        if(i!=NULL)
            k->next = i;
        else if(j!=NULL)
            k->next = j;
            
            
        Node* head3 = dummyhead3->next;
        return head3;
    } 
    
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node* arr[], int K)
    {
        Node* mergeKsortedLL = NULL;
        for(int i=0; i<K; i++)
        {
            mergeKsortedLL = merge2sortedLL(mergeKsortedLL, arr[i]);
        }
        return mergeKsortedLL;
    }
};




//M-2 Using divide and conquer   T.C = O(N. KlogK)
class Solution{
  public:
    Node* mergeKsortedLL(Node* arr[], int start, int end)
    {
        if(start == end) //K=1 => arr size = 1
            return arr[start];
            
        int mid = (start+end)/2;
        Node* head1 = mergeKsortedLL(arr, start, mid);
        Node* head2 = mergeKsortedLL(arr, mid+1, end);
        
        return merge2sortedLL(head1, head2); //standard program , DEFINED ABOVE
    }
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node* arr[], int K)
    {
        if(K == 0)
            return NULL;
        
        return mergeKsortedLL(arr, 0, K-1);
    }
};




//M-3 Using Priority Queue / Min-Heap   T.C = O(N. KlogK)  , S.C = O(K)
class myComparator
{
public:
    bool operator()(Node* &a, Node* &b) 
    {
        return a->data > b->data; 
    }
};

class Solution{
  public:
    
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node* arr[], int K)
    {
        priority_queue<Node*, vector<Node*>, myComparator> minh; //MIN-HEAP
        
        for(int i=0; i<K; i++)
        {
            if(arr[i] != NULL)
                minh.push(arr[i]);
        }
        
        Node* dummyMergeLL = new Node(0);
        Node* mergeTail = dummyMergeLL;
        
        while(! minh.empty())
        {
            Node* currentMinNode = minh.top();
            minh.pop();
            
            mergeTail->next = currentMinNode; //mergeTail follows currentMinNode
            mergeTail = mergeTail->next;
            currentMinNode = currentMinNode->next;
            if(currentMinNode != NULL)
            {
                minh.push(currentMinNode);
            }
        }
        
        return dummyMergeLL->next;
    }
};