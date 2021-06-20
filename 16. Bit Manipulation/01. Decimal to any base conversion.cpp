class Solution
{
public:
    char reValue(int num)
    {
        if (num >= 0 && num <= 9)
            return (num + '0'); //num = 2   =>  '2' is returned
        else
            return (num - 10 + 'A'); //num = 11  =>  'B' is returned
    }
    string getNumber(int B, int N)
    {
        string converted;
        while(N > 0)
        {
            converted += reValue(N % B);
            
            N = N/B;
        }
        reverse(converted.begin(), converted.end());
        return converted;
    }
};

//(282)10 decimal = (11A)16 hexadecimal