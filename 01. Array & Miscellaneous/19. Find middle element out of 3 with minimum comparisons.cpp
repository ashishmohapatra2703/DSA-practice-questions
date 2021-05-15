/*Input:
A = 978, B = 518, C = 300
Output:
518
Explanation:
Since 518>300 and 518<978, so 
518 is the middle element. 
Time Complexity:O(1)   */

class Solution{
  public:
    int middle(int A, int B, int C)
    {
        int x = A-B;
        int y = B-C;
        int z = C-A;
        
        if(x*z > 0)
            return A;
        else if(x*y > 0)
            return B;
        else if(y*z > 0)
            return C;
    }
};