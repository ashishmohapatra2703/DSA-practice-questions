/* Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
            k = 4 
   Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23} of size 4. */

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N)
    {
        int sumofsubarr = 0;
        int maxsum = INT_MIN;

        int i = 0;
        int j = 0;

        while(j < N)
        {
            sumofsubarr += Arr[j];
            
            if(j-i+1 < K)
            {
                j++;
            }
            else if(j-i+1 == K)
            {
                maxsum = max(maxsum , sumofsubarr);

                sumofsubarr -= Arr[i];

                i++;
                j++;
            }
        }
        return maxsum;
    }
};