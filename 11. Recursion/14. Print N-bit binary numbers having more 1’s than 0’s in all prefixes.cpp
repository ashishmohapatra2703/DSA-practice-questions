class Solution
{
public:	
    void NBitBinary1sGreaterEqual0s(string op,int one,int zero,int N,vector<string> &num)
    {
        if(N == 0)
        {
            num.push_back(op);
            return;
        }
        
        string op1 = op + "1";
        NBitBinary1sGreaterEqual0s(op1, one+1, zero, N-1, num);
        
        if(one >= zero+1)
        {
            string op2 = op + "0";
            NBitBinary1sGreaterEqual0s(op2, one, zero+1, N-1, num);
        }
    }
    
	vector<string> NBitBinary(int N)
	{
	    int one = 0;
	    int zero = 0;
	    
	    string op = "";
	    
	    vector<string> result;
	    NBitBinary1sGreaterEqual0s(op, one, zero, N, result);
	    
	    return result;
	}
};