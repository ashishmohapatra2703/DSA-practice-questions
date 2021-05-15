/*  Given a set of N nuts of different sizes and N bolts of different sizes. 
There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
It means nut can only be compared with bolt and bolt can only be compared with nut 
to see which one is bigger/smaller. The elements should follow the following order ! # $ % & * @ ^ ~
Input: 
N = 9
nuts[] = {^, &, %, @, #, *, $, ~, !}
bolts[] = {~, #, @, %, &, *, $ ,^, !}
Output: 
! # $ % & * @ ^ ~
! # $ % & * @ ^ ~             */
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool order(char a, char b)
{
    unordered_map<char, int> mp;
    mp['!'] = 1;
    mp['#'] = 2;
    mp['$'] = 3;
    mp['%'] = 4;
    mp['&'] = 5;
    mp['*'] = 6;
    mp['@'] = 7;
    mp['^'] = 8;
    mp['~'] = 9;
        
    if(mp[a] < mp[b])
        return true;
    return false;
}
//User function template for C++
class Solution
{
public:
	void matchPairs(char nuts[], char bolts[], int n) 
	{
	    sort(nuts, nuts+n, order);
	    sort(bolts, bolts+n, order);
	}
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i< n; i++)
            cin >> nuts[i];
        for (int i = 0; i< n; i++)
            cin >> bolts[i];
            
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        
        for (int i = 0; i< n; i++) 
            cout << nuts[i] << " ";
        cout << endl;
        for (int i = 0; i< n; i++) 
            cout << bolts[i] << " ";
        cout << endl;
    }
    return 0;
}