/*Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Node structure  used in the program
struct Node
{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};
*/
//// M-1 using extra vector space
Node *flatten(Node *root)
{
    vector<int> v;
    Node *horz = nullptr;
    Node *vert = nullptr;
    
    horz = vert = root;
    while(horz != nullptr)
    {
        v.push_back(horz->data);
        vert = horz->bottom;
        while(vert != nullptr)
        {
            v.push_back(vert->data);
            vert = vert->bottom;
        }
        horz = horz->next;
    }
    
    sort(v.begin(), v.end());
    
    Node *newhead = new Node(v[0]);
    
    Node *newlast = newhead;
    for(int i=1; i<v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        
        newlast->bottom = temp;
        newlast = temp;
    }
    
    return newhead;
}
