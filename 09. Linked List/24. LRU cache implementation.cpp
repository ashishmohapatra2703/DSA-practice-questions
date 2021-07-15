/*The task is to design and implement methods of an LRU cache. 
The class has two methods get() and set() which are defined as follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. 
           If the cache reaches its capacity it should invalidate the least recently used item 
           before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Input:
N = 2
Q = 7
Queries = SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
Output: 5 -1
Explanation: Cache Size = 2
SET 1 2 SET 2 3 SET 1 5 SET 4 5
SET 6 7 GET 4 SET 1 2 GET 1
SET 1 2 : 1 -> 2
SET 2 3 : 1 -> 2, 2 -> 3 (the most recently used one is kept at therightmost position) 
SET 1 5 : 2 -> 3, 1 -> 5
SET 4 5 : 1 -> 5, 4 -> 5 (Cache sizeis 2, hence we delete the least recently used key-value pair)
SET 6 7 : 4 -> 5, 6 -> 7 
GET 4 : Prints 5         (The cache now looks like 6 -> 7, 4->5)
SET 1 2 : 4 -> 5, 1 -> 2 (Cache size is 2, hence we delete the least recently used key-value pair)
GET 1 : No key value pair having key = 3. Hence, -1 is printed.

https://practice.geeksforgeeks.org/problems/lru-cache/1#

Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). 
                        (though, you may use extra space for cache storage and implementation purposes).*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    class Node{
    public:
        Node* prev;
        int key;
        int value;
        Node* next;
    
        Node(int key, int value)
        {
            this->prev = NULL;
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
    };
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> hash; //You can't access a non static member in a static function.
public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->capacity = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev; 
    }
    void addNodetoMRU(Node* node)
    {
        Node* headNextNode = head->next;
        node->next = headNextNode;
        node->prev = head;
        head->next = node;
        headNextNode->prev = node;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(hash.find(key) != hash.end()) //if key exists in the cache/hashmap
        {
            Node* currNodeAddr = hash[key];
            deleteNode(currNodeAddr);
            addNodetoMRU(currNodeAddr);
            hash[key] = head->next; //new Node Address updated
            return hash[key]->value; 
        }
        return -1; //if not present in the hashmap
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(hash.find(key) != hash.end())
        {
            Node* currNodeAddr = hash[key];
            hash.erase(key);
            deleteNode(currNodeAddr);
        }
        if(hash.size() == capacity)
        {
            Node* LRUnode = tail->prev;
            hash.erase(LRUnode->key);
            deleteNode(LRUnode); //delete the least recently used Node
        }
        
        addNodetoMRU(new Node(key, value));
        hash[key] = head->next; //new Node Address inserted
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends

