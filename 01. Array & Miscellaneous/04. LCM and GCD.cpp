#include <iostream>
using namespace std;

long long GCD(long long a, long long b)
{ 
    if (a == 0) 
        return b;  
    return GCD(b%a, a);  
} 
int main()
{
    int t;
    cin>>t;
    for (int i=0; i<t; i++) 
    {
        long long a;
        cin>>a;
        long long b;
        cin>>b;

        long long gcd = GCD(a, b);
        long long lcm = (a*b/gcd);
        
        cout<<lcm<<" "<<gcd;
        cout<<endl;
    }
    return 0;
}