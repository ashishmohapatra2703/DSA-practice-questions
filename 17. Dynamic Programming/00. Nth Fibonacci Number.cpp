// M-1
#include <iostream>
#include <cstring>
#define mod 1000000007
using namespace std;

int fib(int n, int F[]) 
{
	if(F[n] != -1)
        return F[n]; //Memoization

    if(n==0 || n==1)
        return F[n]=n; //base condition
    
    return F[n] = (fib(n-1, F) + fib(n-2, F))%mod;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N; 
        cin>>N;
        int F[n+1];
        memset(F, -1, sizeof(F));
        
        int ans = fib(N, F);
        cout<< ans <<endl;
    }
}


// M-2
#include <iostream>
#include <cstring>
#define mod 1000000007
using namespace std;

int F[1001]; //according to the constraints

int fib(int n) 
{
	if(F[n] != -1)
        return F[n]; //Memoization

    if(n==0 || n==1)
        return F[n]=n; //base condition
        
    return F[n] = (fib(n-1) + fib(n-2))%mod;
}
int main()
{
    memset(F, -1, sizeof(F));
    int t;
    cin>>t;
    while(t--)
    {
        int N; 
        cin>>N;
        int ans = fib(N);
        cout<< ans <<endl;
    }
}

//OR
#include <iostream>
using namespace std;

long long fib[85];  //according to the constraints
void fibonacci() 
{
    fib[0] = 1;
    fib[1] = 1;
    
    for(int i=2; i<85; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
}
int main()
{
    fibonacci();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cout<<fib[i]<<" ";
        }
        cout<<endl;
    }
}