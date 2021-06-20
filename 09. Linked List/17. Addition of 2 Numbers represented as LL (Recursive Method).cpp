/* A recursive program to add two linked lists 

#include <iostream> 
using namespace std;

struct Node 
{ 
	int data; 
	struct Node* next; 
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
}; 

void append(Node** head_ref, Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void push(Node** head_ref, int new_data) 
{ 
    // allocate node 
    Node* new_node = new Node(new_data); 
  
    // link the old list off the new node
    new_node->next = (*head_ref); 
  
    // move the head to point to the new node 
    (*head_ref)    = new_node; 
} 

// A utility function to print linked list 
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<<node->data<<" ";
		node = node->next; 
	} 
	cout<<endl;
} 

// A utility function to swap two pointers 
void swapPointer( Node** a, Node** b ) 
{ 
	Node* t = *a; 
	*a = *b; 
	*b = t; 
} 

Node* addSameSize(Node* head1, Node* head2, int* carry) ;

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) ;


// The main function that adds two linked lists represented by head1 and head2. 
// The sum of two lists is stored in a list referred by result 
void addList(Node* head1, Node* head2, int size1, int size2, Node** result) 
{ 
	Node *cur; 
    if (head1 == NULL) { 
		*result = head2; 
		return; 
	}

	if (head2 == NULL) 
	{ 
		*result = head1; 
		return; 
	}
	
	int carry = 0; 

	if (size1 == size2) 
		*result = addSameSize(head1, head2, &carry); 
    else
	{ 
		int diff = abs(size1 - size2); 

		if (size1 < size2) 
			swapPointer(&head1, &head2); 

		for (cur = head1; diff--; cur = cur->next);
		
        *result = addSameSize(cur, head2, &carry); 
        
		addCarryToRemaining(head1, cur, &carry, result); 
	} 

	if (carry) 
		push(result, carry); 
} 

// Driver program to test above functions 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    Node *head1 = NULL, *tail1 = NULL;
	    Node *head2 = NULL, *tail2 = NULL;
	    Node *result = NULL; 
        int size1, size2;
        cin>>size1>>size2;
        
        int temp;
        for(int i = 1; i<=size1; i++){
            cin>>temp;
            append(&head1, &tail1, temp);
        }
        for(int i = 1; i<=size2; i++){
            cin>>temp;
            append(&head2, &tail2, temp);
        }
        
        addList(head1, head2, size1, size2, &result); 
        printList(result); 
	}
    return 0; 
} 
// } Driver Code Ends */


//User function Template for C++

//Function which adds two linked lists of same size. (with no modification of given LLs.)
Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
    if(head1==NULL)
        return NULL;
        
	Node* sumItr = new Node(-1);
	sumItr->next = addSameSize(head1->next, head2->next, carry);
	
	int sumItrData = (head1->data + head2->data + *carry);
	sumItr->data = sumItrData % 10; //10th place digit of the sumData
	*carry = sumItrData/10;     //unit place digit of the sumData
	
	return sumItr;
} 

//Function to add remaining carry.

/* curr is at the first index of where size started to be same.
Suppose we have two no. let "8049" and "89". 
(always given 1st LL is the largest (handled by driver code).)

       head1-> 8->0->4->9
             head2-> 8->9
    ------------------------
      result-> 8->1->3->8
      
Then, curr is at (4) of 1st LL. In the addCarryToRemaining() function we need to
recursively traverse the 1st LL till curr(curr excluding).
And add the remaining carry's similarly like we done in addSameSize(). */

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
	if(head1==curr)
        return;
    
    addCarryToRemaining(head1->next, curr, carry, result);
	
	Node* sumItr = new Node(-1);
	int sumItrData = (head1->data + *carry);
	sumItr->data = sumItrData % 10; //10th place digit of the sumData
	*carry = sumItrData/10;     //unit place digit of the sumData
	
	sumItr->next = *result;
	*result = sumItr;              //or can also use push(result, sumItrData);
}



/*Following are the steps. 
1) Calculate sizes of given two linked lists. 
2) If sizes are same, then calculate sum using recursion. 
   Hold all nodes in recursion call stack till the rightmost node, 
   calculate the sum of rightmost nodes and forward carry to the left side. 
3) If size is not same, then follow below steps: 
….a) Calculate difference of sizes of two linked lists. Let the difference be diff 
….b) Move diff nodes ahead in the bigger linked list. Now use step 2 to 
     calculate the sum of the smaller list and right sub-list (of the same size) of a larger list.
     Also, store the carry of this sum. 
….c) Calculate the sum of the carry (calculated in the previous step) with the 
     remaining left sub-list of a larger list. Nodes of this sum are added at the beginning of the 
     sum list obtained the previous step.*/