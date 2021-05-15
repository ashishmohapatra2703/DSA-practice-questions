/*Write an efficient program to count number of 1s in the binary representation of an integer.

Input : n = 6
Output : 2
Binary representation of 6 is 110 and has 2 set bits */
 
class Solution
{ 
  public:
    int setBits(int N) 
    {
        int count = 0;
        while(N != 0)
        {
            int rmsbm = (N & -N);
            N = N - rmsbm;
            count ++;
        }
        return count;
    }
};