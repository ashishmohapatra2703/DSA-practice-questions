//find all primes smaller than n when n is <= 10^7
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        bool isPrime[N+1];
        memset(isPrime, true, sizeof(isPrime));
        
        isPrime[0] = false;
        isPrime[1] = false;

        for(int p=2; p*p<=N; p++)
        {
            if(isPrime[p] == true)
            {
                for(int m=p*p; m<=N; m=m+p)
                {
                    isPrime[m] = false;
                }
            }
        }
        
        vector<int> allprime; //contains all prime numbers up to N
        for(int i=0; i<=N; i++)
        {
            if(isPrime[i] == true)
                allprime.push_back(i);
        }
        return allprime;
    }
};