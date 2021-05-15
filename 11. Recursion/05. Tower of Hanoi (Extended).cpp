class Solution{
public:
    void TOH(int N,int source,int destin,int helper,int &stepscount,int n, vector<int> &nthMove)
    {
        if(N==1)
        {
            stepscount ++;
            if(n==stepscount)
            {
                nthMove.push_back(source);
                nthMove.push_back(destin);
                return;
            }
            return;
        }

        TOH(N-1, source, helper, destin, stepscount, n, nthMove);
        TOH(1, source, destin, helper, stepscount, n, nthMove);
        TOH(N-1, helper, destin, source, stepscount, n, nthMove);          
    }

    vector<int> shiftPile(int N, int n)
    {
        int stepscount = 0;
        vector<int> ans;
        
        //There are N plates and the nth move in the format ith box to jth box.
        TOH(N, 1, 3, 2, stepscount, n, ans);
        return ans;
    }
};
/* 
The king showed him a pile of glass plates kept one above another, each one being smaller than the one beneath.
The plates were kept in box 1. He had to transfer the plates to box 3 using box 2. 
However, there were some constraints. The old man could only take one plate at a time and he could only 
place a smaller plate on top of a larger plate. He could take a plate only from the top. Help the old man do so.
There are N plates and he has to tell the nth move in the format (i, j) 
where a plate is being moved from ith box to jth box.

Note:
Given any number of plates, they can be transferred from box 1 to box 3 using box 2 using the following steps.
Step 1: Transfer first N-1 plates from box 1 to box 2 using box 3.
Step 2: Transfer the remaining plate from box 1 to box 3.
Step 3: Transfer the first N-1 plates from box 2 to box 3 using box 1.

Example 1:
Input: N = 2, n = 2
Output: 1 3
Explaination:  
The plate on top of box 1 is first transferred to box 2. 
The second plate from box 1 is transferred to box 3 and 
finally the plate from box 2 is transferred to box 3. 
In each situation, all the constraints are satisfied. You are required to print the 2nd move 
which is "Move plate from box 1 to box 3", hence 1 3.

Example 2:
Input: N = 3, n = 4.
Output: 1 3
Explaination: 
The movements of plates will be from 1 to 3. 
Then from 1 to 2. 
Then from 3 to 2. 
And finally 4th move from 1 to 3. */