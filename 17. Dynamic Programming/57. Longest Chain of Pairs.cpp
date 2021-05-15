/* You are given N pairs of numbers. In every pair, the first number is always smaller than the second number.
 A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
You have to find the longest chain which can be formed from the given set of pairs. 

The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool incChain(struct val a, struct val b)
{
    return a.first < b.first; //OR return a.second < b.second;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, incChain);
    
    int LIS[n];

    for(int i=0; i<n; i++)
        LIS[i] = 1;     //every single pair is increasing subseq. of length 1
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if( p[j].second < p[i].first )
            {
                if(1+LIS[j] >= LIS[i])
                {
                    LIS[i] = 1+LIS[j];
                }
            }
        }
    }
    //LIS[i] stores the lenLIS ending with p[i] pair
    
    int maxchain = 0;
    for(int i=0; i<n; i++)
    {
        maxchain = max(maxchain, LIS[i]);
    }
    return maxchain; //Length of Longest Valid Chain
}