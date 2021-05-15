/* A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. 
Given a byte, swap the two nibbles in it. 
For example 100 is be represented as 01100100 in a byte (or 8 bits). 
The two nibbles are (0110) and (0100). 
If we swap the two nibbles, we get 01000110 which is 70 in decimal.*/

class Solution{
public:
    int swapNibbles(unsigned char x)
    {
        int lowerNibble = x & 0x0F;
        int leftShiftedlowerNibble = lowerNibble << 4;
        
        int rightShiftedUpperNibble = x >> 4;
        
        return leftShiftedlowerNibble | rightShiftedUpperNibble;
    }
};