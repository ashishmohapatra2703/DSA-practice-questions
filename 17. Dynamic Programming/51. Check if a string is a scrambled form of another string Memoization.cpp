#include <iostream>
#include <string.h>
#include <unodered_map>
using namespace std;

unodered_map<string, bool> mp;
bool solve(string a,string b)
{
    if(a.length() != b.length())
        return false;
	if(a.length()==0 && b.length()==0)
        return true;
    if(a.compare(b)==0)
        return true;
    if(a.length()<=1)
        return false;

    string key="";
    key.append(a+" "+b);
    if(mp.find(key) != mp.end())
        return mp[key];

    int n = a.length();
    bool flag=false;
    for(int i=1; i<=n-1; i++)
    {
        bool cond1 =(solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)));
        bool cond2 =(solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)));
        if(cond1 || cond2)
        {
            flag=true;
            break;
        }
    }
    return mp[key] = flag;
}

int main()
{
    string a,b;
    cin>>a>>b;
    mp.clear();
    cout<<solve(a,b);
}