/* arr[] = [a, b, c, d]

o/p :-
(a+a)^(a+b)^(a+c)^(a+d)^
(b+a)^(b+b)^(b+c)^(b+d)^
(c+a)^(c+b)^(c+c)^(c+d)^
(d+a)^(d+b)^(d+c)^(d+d)  

= 2a ^ 2b ^ 2c ^ 2d 
= 2*( a^b^c^d )         */


long long int XORsum(int arr[], int n)
{
    long long int XORofSumofallPairs = 0;
    	
    for(int i=0; i<n; i++)
    {
    	XORofSumofallPairs = XORofSumofallPairs ^ (2LL*arr[i]);
    }
    return XORofSumofallPairs;
}