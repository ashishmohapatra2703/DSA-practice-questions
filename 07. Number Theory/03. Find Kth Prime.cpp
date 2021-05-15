#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//The 5,000,000th prime is 86,028,121

vector<int> allprime; //contains all prime numbers up to N
bool isPrime[90000001]; //declare globally

void sieve()
{
    int N = 90000000;
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = false;
    isPrime[1] = false;

    for(int p=2; p*p<=N; p++)
    {
        if(isPrime[p] == true)
        {
            for(int m=p*p; m<=N; m+=p)
            {
                isPrime[m] = false;
            }
        }
    }

    for(int i=2; i<=N; i++)
    {
        if(isPrime[i] == true)
        {
            allprime.push_back(i);
        }
    }
}
int main()
{
    sieve();
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        cout<<k<<" th Prime No. is = "<< allprime[k-1] <<endl;
    }
}
/*Input -> An integer stating the number of queries Q(equal to 50000), and Q lines follow,
 each containing one integer K between 1 and 5000000 inclusive.
Output
Q lines with the answer of each query: the Kth prime number.
Example
	Input:
8
1
10
100
1000
10000
100000
1000000
5000000

	Output:
2
29
541
7919
104729
1299709
15485863
86028121  */
