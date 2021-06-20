/*Given a number N, the task is to count minimum steps to minimize it to 1 
according to the following criteria:
If N is divisible by 2 then you may reduce N to N/2.
If N is divisible by 3 then you may reduce N to N/3.
Otherwise, Decrement N by 1.

Input: N = 10
Output: 3
Explanation: 10 - 1 = 9 / 3 = 3 / 3 = 1      */


//Top-Down + Memoization
class Solution{
public:
	vector<int> dp {vector<int>(1e5+1, -1)};
	
	int minSteps(int N) 
	{ 
	    if(dp[N] != -1)
	        return dp[N];
	    if(N == 1)
	        return dp[N] = 0;
	       
        int option1 = INT_MAX;
        int option2 = INT_MAX;
        int option3 = INT_MAX;
        
	    if(N%2 ==0)
	        option1 = 1+minSteps(N/2);
	    if(N%3 ==0)
	        option2 = 1+minSteps(N/3);
	    option3 = 1+minSteps(N-1);
	   
	    return dp[N] = min({option1, option2, option3});
	}
};

//Bottom-up
class Solution{
	public:
	int minSteps(int N) 
	{ 
	    int dp[N+1];
	    
	    dp[1] = 0;
	    for(int i=2; i<=N; i++)
	    {
	        int option1 = INT_MAX;
            int option2 = INT_MAX;
            int option3 = INT_MAX;
            
	        if(i%2 == 0)
	            option1 = 1+dp[i/2];
            if(i%3 == 0)
	            option2 = 1+dp[i/3];
	        option3 = 1+dp[i-1];
	        
	        dp[i] = min({option1, option2, option3});
	    }
	    return dp[N];
	}
};