/* Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. 
Find the set bits of y in range [l, r] and set these bits in x also.

						  (r=7)       (l=3)
			   10  9  8  7 [6  5  4  3  2] 1  0
	---------------------------------------------
	Y = 1365 =  1  0  1  0  1  0  1  0  1  0  1
	X = 1177 =  1  0  0  1  0  0  1  1  0  0  1
	---------------------------------------------
	o/p =       1  0  0  1  1  0  1  1  1  0  1  = 1245 

Constraints:
1 ≤ x, y ≤ 10^9
1 ≤ l ≤ r ≤ 32 */

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r)
    {
        int range = (r-l+1);
        long mask = (1L << range);
        mask--;
        mask = (mask << (l-1)); //did -1 to get index
        
        mask = (y & mask);
        x = (x | mask);
        
        return x;
    }
};



	range = 5
	mask = 00000100000
       ==> 00000011111
    <<l-1 means <<2 
       ==> 00001111100


						  (r=7)       (l=3)
			   10  9  8  7  6  5  4  3  2  1  0
	---------------------------------------------
	Y = 1365 =  1  0  1  0 '1  0  1  0  1' 0  1
 &	mask     =  0  0  0  0 '1  1  1  1  1' 0  0
	_____________________________________________
	mask     =  0  0  0  0 '1  0  1  0  1' 0  0  
 |	X = 1177 =  1  0  0  1 '0  0  1  1  0' 0  1
	---------------------------------------------
	o/p =       1  0  0  1 '1  0  1  1  1' 0  1  = 1245 
	