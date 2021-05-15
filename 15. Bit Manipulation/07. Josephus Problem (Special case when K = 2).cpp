#include <bits/stdc++.h>
using namespace std;

int highestPowerOf2(int n) // m or 2ˣ <= n
{
    int m = 1; //2⁰
    while(m*2 <= n)
    {
        m = m*2;
    }
    return m;
}
int josephus(int n)
{
    int l = n - highestPowerOf2(n);   //n = 2ˣ + l
    return 2*l + 1;             //survior = 2l + 1
}


int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<< josephus(n) <<endl;
	}
	return 0;
}