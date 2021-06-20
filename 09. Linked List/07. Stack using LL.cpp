// https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/
#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};
class MyStack
{
    private:
        StackNode *top;
    public :
        MyStack()
        {
            top = NULL;
        }
        void push(int);
        int pop();
};

void MyStack::push(int x)
{
    struct StackNode *t = new StackNode(x);
    t->next = top;
    top = t;
}
int MyStack ::pop()
{
    if(top==NULL)
        return -1;

    struct StackNode *p = top;
    top = top->next;
    return p->data;
    delete p;
}
int main()
{
    int T;
    cin >> T;
    while (T-- )
    {
        MyStack *sq = new MyStack();
        int Q;
        cin >> Q;
        while (Q-- )
        {
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq ->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq ->pop() <<" ";
            }
        }
        cout << endl;
    }
}
