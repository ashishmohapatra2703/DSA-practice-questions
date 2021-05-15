/* The method push to push element into the queue */
void StackQueue :: push(int x)
{
    s1.push(x);
}


/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if(s2.empty() == true) //moves the elements once and moves elements only if stack2 empty
    {
        if(s1.empty() == true)
            return -1; //that is both s1 and s2 are empty => queue is empty
            
        while(! s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int x = s2.top();
    s2.pop();
    return x;
}
/* enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).
Here time complexity will be O(1)

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Here time complexity will be O(n)  */