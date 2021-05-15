/* Given a number n, generate bit patterns from 0 to 2^n-1 
such that successive patterns differ by one bit.
Input: n=3
Output: Every adjacent element of gray code differs only by one bit.
    000 
    001 
    011 
    010 
    110 
    111 
    101 
    100  */

//M-1
//Time Complexity: O(2^N)
//Auxiliary Space: O(2^N)
class Solution{
  public:
    vector<string> generateCode(int N)
    {
        if(N == 1)
            return {"0", "1"};
            
        vector<string> greyCodeofNminus1bit = generateCode(N-1);
        vector<string> greyCodeofNbit;
         
        for(auto it=greyCodeofNminus1bit.begin(); it!=greyCodeofNminus1bit.end(); it++)
        {
            greyCodeofNbit.push_back( "0" + *it );
        }
        for(auto it=greyCodeofNminus1bit.rbegin(); it!=greyCodeofNminus1bit.rend(); it++)
        {
            greyCodeofNbit.push_back( "1" + *it );
        }
        return greyCodeofNbit;
    }
};


//M-2
// Time Complexity: O(2^N)
// Auxiliary Space: O(N)
class Solution{
  public:
    vector<string> generateCode(int N)
    {
        vector<string> greyCodeofNbit;
         
        for (int i=0; i < (1<<N); i++) 
        {
            greyCodeofNbit.push_back( bitset<32>(i ^ (i >> 1)).to_string().substr(32 - N) );
        }
        return greyCodeofNbit;
    }
};