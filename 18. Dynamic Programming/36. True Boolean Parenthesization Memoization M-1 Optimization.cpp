//Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true
////////////////////////// With Optimization -> memoize at every call in the k loop too
//TLE in gfg
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp; //for storing every sub-problems ans.(Memoization)

int TBP(string s, int i, int j, bool output) // here boolean output is the subproblem expression o/p
{
    string temp_key = "";
    temp_key.append( to_string(i)+" "+to_string(j)+" "+to_string(output) );

    if(mp.find(temp_key) != mp.end()) //found a key-value pair present in map //OR can use if(mp.count(temp_key) == 1)
        return mp[temp_key];//ans value stored previously corresponding to same temp_key is returned


    if(i>j) //invalid i/p
        return mp[temp_key] = 0;
    if(i==j) //smallest valid i/p
    {
        if(output == true)
        {
            if(s[i] == 'T') // i& j index pointer always lies either on T or F
                return mp[temp_key] = 1;
            else
                return mp[temp_key] = 0;
        }
        else if(output == false)
        {
            if(s[i] == 'F')
                return mp[temp_key] = 1;
            else
                return mp[temp_key] = 0;
        }
    }              ////Base Condition



    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2) // k breaking subproblems index pointer always lies either on char | or & or ^
    {
        int lt,rf,lf,rt;

        string lt_key = "";
        lt_key.append( to_string(i)+" "+to_string(k-1)+" "+to_string(true) );
        if(mp.find(lt_key) != mp.end())
        {
            lt = mp[lt_key];
        }
        else
        {
            lt = TBP(s, i ,k-1 , true);
            mp[lt_key] = lt;
        }

        string rf_key = "";
        rf_key.append( to_string(k+1)+" "+to_string(j)+" "+to_string(false) );
        if(mp.find(rf_key) != mp.end())
        {
            rf = mp[rf_key];
        }
        else
        {
            rf = TBP(s, k+1 ,j , false);
            mp[rf_key] = rf;
        }

        string lf_key = "";
        lf_key.append( to_string(i)+" "+to_string(k-1)+" "+to_string(false) );
        if(mp.find(lf_key) != mp.end())
        {
            lf = mp[lf_key];
        }
        else
        {
            lf = TBP(s, i ,k-1 , false);
            mp[lf_key] = lf;
        }

        string rt_key = "";
        rt_key.append( to_string(k+1)+" "+to_string(j)+" "+to_string(true) );
        if(mp.find(rt_key) != mp.end())
        {
            rt = mp[rt_key];
        }
        else
        {
            rt = TBP(s, k+1 ,j , true);
            mp[rt_key] = rt;
        }



        if(s[k] == '&')
        {
            if(output == true)
                ans += lt*rt;
            else if(output == false)
                ans += lt*rf + lf*rt + lf*rf;
        }
        else if(s[k] == '|')
        {
            if(output == true)
                ans += lt*rt + lt*rf + lf*rt;
            else if(output == false)
                ans += lf*rf;
        }
        else if(s[k] == '^')
        {
            if(output == true)
                ans += lt*rf + lf*rt;
            else if(output == false)
                ans += lt*rt + lf*rf;
        }
    }
    return mp[temp_key] = ans%1003; //storing in value for the key in the unordered_map
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int n;
        cin>>n; //str length
        string str;
        cin>>str;
        int TrueNoOfWaysParenthesize  = TBP(str, 0 ,n-1 , true); //final value of expression to be evaluated  true.
        cout<< TrueNoOfWaysParenthesize <<endl;
    }
}
