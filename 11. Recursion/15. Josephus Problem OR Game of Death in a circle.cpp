/*Given the total number of persons n and a number k which indicates 
that k-1 persons are skipped and kth person is killed in circle in a fixed clockwise direction
The task is to choose the safe place in the circle so that when you perform these operations
starting from 1st place  the circle, you are the last one remaining and survive.
Time Complexity: O(N).
Auxiliary Space: O(N).  */
#include <iostream>
#include <vector>
using namespace std;

void GameOfDeath(vector<int> persons, int k, int sword, int &lastman) 
{   
    if(persons.size() == 1)
    {
        lastman = persons[0];
        return;
    }
    sword = (sword + k) % persons.size();
    persons.erase(persons.begin() + sword);
    
    GameOfDeath(persons, k, sword, lastman);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int k; cin>>k;
        
        vector<int> persons;
        for (int i=1; i<=n; i++) 
            persons.push_back(i);
        
        int sword = 0;
        
        int lastman;
        GameOfDeath(persons, --k, sword, lastman);
        cout<<lastman<<endl;
    }
}