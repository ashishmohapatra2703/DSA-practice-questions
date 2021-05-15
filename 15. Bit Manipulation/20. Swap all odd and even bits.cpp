/*Given an unsigned integer N. The task is to swap all odd bits with even bits. 
For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 
Here, every even position bit is swapped with adjacent bit on the right side, 
and every odd position bit is swapped with an adjacent on the left side.

Input: N = 23
Output: 43
Explanation: 
Binary representation of the given number is 00010111 after swapping 00101011 = 43 in decimal.*/

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        int evenBitMask = 0xAAAAAAAA;
    	int oddBitMask = 0x55555555;
    	
    	int evenBits_preserved = n & evenBitMask;
    	int oddBits_preserved = n & oddBitMask;
    	
    	int evenShiftedToOddPositions = evenBits_preserved >> 1;
    	int oddShiftedToEvenPositions = oddBits_preserved << 1;
    	
    	return evenShiftedToOddPositions | oddShiftedToEvenPositions;
    }
};