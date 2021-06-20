long long int factorial(int N)
{
    if(N==0)
		return 1;   // 0! = 1 base condition
            
	return N * factorial(N-1); 
}