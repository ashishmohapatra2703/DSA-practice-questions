/*Given a list arr of N integers, print sums of all subsets in it. 
Output should be printed in increasing order of sums.

Input:  N = 2  arr[] = {2, 3}
Output:  [0, 2, 3, 5]
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then Sum = 2+3 = 5. */

class Solution{
public:
	//sumPS = sum of Power Set
    void sumOfAllSubSets(vector<int> &ip, int ipItr, int &N, 
                        int &subsetSum, vector<int> &sumPS) 
    {
        if(ipItr == N)  //base condition
        {
            sumPS.push_back(subsetSum);
            return;
        }

        sumOfAllSubSets(ip, ipItr+1, N, subsetSum, sumPS);

        subsetSum += ip[ipItr];
        sumOfAllSubSets(ip, ipItr+1, N, subsetSum, sumPS);
        subsetSum -= ip[ipItr];
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumOfallSubSets;
        int subsetSum = 0;
        sumOfAllSubSets(arr, 0, N, subsetSum, sumOfallSubSets);
        
        sort(sumOfallSubSets.begin(), sumOfallSubSets.end());
        return sumOfallSubSets;
    }
};