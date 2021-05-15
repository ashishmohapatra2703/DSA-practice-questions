#include <iostream>
using namespace std;

string* ZigZagRowConcat(string str, int row) 
{
    if(row == 1)
    {
        string* arr = new string[1];
        arr[0] = str;
        return arr;
    }
    
    string* arr = new string[row]; ///
    int row_num = 0; //will vary from 0 to row-1 
    bool down;

    for(int i=0; str[i]!='\0'; i++)
    {
        arr[row_num].push_back(str[i]);
        if(row_num == row-1)
            down = false; //up direction
        else if(row_num == 0)
            down = true; //down direction
        
        if(down == true)
            row_num++;
        else if(down == false)
            row_num--;
    }
    return arr;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        
        int row;
        cin>>row;
        
        string* ans = ZigZagRowConcat(str, row);
        for(int i=0; i<row; i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
}
/*
Given a string and number of rows ‘n’.
 Print the string formed by concatenating n rows 
 when input string is written in row-wise Zig-Zag fashion.

Examples:
Input: str = "ABCDEFGH"
       n = 2
Output: "ACEGBDFH"
Explanation: Let us write input string in Zig-Zag fashion
             in 2 rows.
A   C   E   G   
  B   D   F   H
Now concatenate the two rows and ignore spaces 
in every row. We get "ACEGBDFH"


Input: str = "GEEKSFORGEEKS"
       n = 3
Output: GSGSEKFREKEOE
Explanation: Let us write input string in Zig-Zag fashion
             in 3 rows.
G       S       G       S
  E   K   F   R   E   K
    E       O       E
Now concatenate the two rows and ignore spaces 
in every row. We get "GSGSEKFREKEOE"
*/