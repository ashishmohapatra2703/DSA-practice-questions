/*Input:             Output:
    2                  2 2 5 2
    100 ~ 2².5²        5 1 7 1
    35 ~ 5¹.7¹                           */
#include <iostream>
using namespace std;

void PrimeFactorization(int N) 
{
    for(int p=2; p<=N; p++)
    {
        if(N % p == 0)
        {
            int Powerofp = 0;
            while(N % p == 0)
            {
                Powerofp++;
                N = N/p;
            }
            cout<< p <<" "<< Powerofp <<" ";
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        PrimeFactorization(N);
        cout<<endl;
    }
}