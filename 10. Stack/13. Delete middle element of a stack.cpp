/*
 Input    Output:
-------- ---------
  5         
  4         5
  3         4
  2         2
  1         1              
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1) without using any additional data structure*/

stack<int> deleteMidofStack(stack<int> &s, int mid) //pass by reference 
{
    if(s.size() == 0)
        return s;
    if(mid==1)
    {
        s.pop();
        return s;
    }                    //base condition
    
    int topele = s.top();
    s.pop();
    deleteMidofStack(s, mid-1); //hypothesis
    
    s.push(topele);    //induction
    return s;
}
//User function Template for C++
//You need to complete this function

stack<int> deleteMid(stack<int> s, int sizeOfStack, int current) //no need of int current
{
    int mid = sizeOfStack/2 + 1; //position from top
    return deleteMidofStack(s, mid);
}