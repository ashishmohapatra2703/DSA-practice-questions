/*You are given two arrays. In each step, you can set a[i] = a[i] - b[i] , if a[i] >= b[i]  
Determine the minimum number of steps that are required to make all a's equal.
input:
5
5 7 10 5 15
2 2 1 3 5
Output : 8  */

#include <iostream>
#include <climits>
using namespace std;

int minStepstoMakeAllEqual(int a[], int b[], int n)
{
	int minima = INT_MAX;
	for(int i=0; i<n; i++)
		minima = min(minima, a[i]);

	int steps = 0;
	bool repeat = true;
	while(repeat)
	{
		repeat = false;
		for(int i=0; i<n; i++)
		{
			while(a[i] > minima)
			{
				a[i] = a[i] - b[i];
				repeat = true;
				steps++;
			}
			if(a[i] < minima)
			{
				minima = a[i];
			}
			if(minima < 0)
				return -1;
		}
	}
	return steps;
}
int main() 
{
	int n;
	cin>>n;										
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int b[n];
	for(int i=0; i<n; i++)
		cin>>b[i];
	
	int ans = minStepstoMakeAllEqual(a, b, n);
	cout<<ans;
}
2