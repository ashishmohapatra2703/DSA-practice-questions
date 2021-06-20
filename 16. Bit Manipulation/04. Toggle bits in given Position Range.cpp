/*Given a non-negative number N and two values L and R. 
The problem is to toggle the bits in the range L to R in the binary representation of N, 
i.e, to toggle bits from the rightmost Lth bit to the rightmost Rth bit. 
A toggle operation flips a bit 0 to 1 and a bit 1 to 0. Print N after the bits are toggled.

Input:
N = 50 , L = 2 , R = 5
Output:
44
Explanation:
(50)10 = (110010)2.  After toggling all the bits from 2nd to 3rd position we get (101100)2 = (44)10 */

int toggleBits(int N , int L , int R) 
{
    for(int i=L-1; i<=R-1; i++) //Xth bit position = X-1th index from rightside
    {
        N = N ^ (1<<i);
    }
    return N;
}