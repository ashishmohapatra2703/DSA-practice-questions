//M-1     O(n)
long long power(int N,int R)
{
    if(R == 0)
        return 1;
        
    long long NpowerRminus1 = power(N, R-1);
    return (N * NpowerRminus1) %mod;
}

//using (m * n) %p  =  (m%p * n%p) %p



//M-2    O(log₂n)
class Solution{   
public:
    long long int mod = 1000000007; //or use #define globally
    long long int power(int a, long long int b) 
    { 
        if(b == 0)
            return 1;
        
        long long int ApowerBby2 = power(a, b/2);
        
        if(b%2 == 0) //even power b
        {
            return (ApowerBby2%mod * ApowerBby2%mod) %mod;  // aᵇ/² * aᵇ/²
        }
        else if(b%2 != 0) //odd power b
        {
            return (ApowerBby2%mod * ApowerBby2%mod * a) %mod; // aᵇ/² * aᵇ/² * a
        }
    }
};