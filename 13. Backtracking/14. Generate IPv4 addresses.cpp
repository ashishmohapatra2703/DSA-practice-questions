/*Given a string S containing only digits, Your task is to complete the function genIp() 
which returns a vector containing all possible combination of valid IPv4 ip address 
and takes only a string S as its only argument.
Note : Order doesn't matter.

For string 11211 the ip address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1 

For string 50361 the ip address possible are 
5.0.3.61
5.0.36.1
50.3.6.1

Time Complexity: O(N⁴) */

//M-1 using nested loops
class Solution{
  public:
    bool isValid(string subPart) //subPart shouble be of size >0 and <=3
    {
        if(subPart[0] == '0')
        {
            if(subPart.size() == 1) // .0. ->valid but 
                return true; 
            return false;        //.06. ->not valid
        }
        
        if(stol(subPart) <= 255) //converts string to long int
            return true;
        return false;
    }

    vector<string> genIp(string &s) 
    {
        vector<string> allPossibleIP;
        int n = s.size();
        //=> spaces = n-1 i.e, **[0 .... n-2]**
        //out of which we have to place 3 dots at i,j,k index

        for(int i=0; i<=n-4; i++)
        {
            for(int j=i+1; j<=n-3; j++)
            {
                for(int k=j+1; k<=n-2; k++)
                {
                    string part1 = s.substr(0, i+1);  // index 0 ... i      //len = (i)-(0)+1
                    string part2 = s.substr(i+1, j-i);// index i+1 ..... j  //len = (j)-(i+1)+1
                    string part3 = s.substr(j+1, k-j);// index j+1 ..... k  //len = (k)-(j+1)+1
                    string part4 = s.substr(k+1, n-k-1);//index k+1 .... n-1  //len = (n-1)-(k+1)+1
                    
                    if( isValid(part1) and 
                         isValid(part2) and 
                          isValid(part3) and 
                            isValid(part4) )
                        allPossibleIP.push_back(part1+'.'+part2+'.'+part3+'.'+part4);
                }
            }
        }
        return allPossibleIP;
    }
};

//M-2 backtracking