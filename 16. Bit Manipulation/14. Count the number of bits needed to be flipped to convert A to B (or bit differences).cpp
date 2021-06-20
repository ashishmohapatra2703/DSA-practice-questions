/* Input: A = 10, B = 20
Output: 4 */

class Solution{
    public:
    int countsetBits(int N) 
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
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        int aXORb = a ^ b;
        return countsetBits(aXORb);
    }
};

// A   = 01010
// B   = 10100
// XOR = 11110