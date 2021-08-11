//M-1 Lomuto Partitioning 
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        while(i <= n-1)
        {
            if((nums[i]&1) == 1) //odd
                i++;
            else if((nums[i]&1) == 0) //even
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        //0....j-1 = even region
        //j....i-1 = odd region
        //i to n-1 = region of unknown (which goes on decreasing in traversal)
        return nums;
    }
};

//M-2 Two pointers
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high)
        {
            if((nums[low]&1) == 1 and (nums[high]&1) == 0)
            {
                swap(nums[low] , nums[high]);
                low++;
                high--;
            }
            if((nums[low]&1) == 0) //even
            {
                low++;
            }
            if((nums[high]&1) == 1) //odd
            {
                high--;
            }
        }
        return nums;
    }
};

/* input = [24,13,68,79,46,77]
  Output = [24,68,46,79,13,77]  
stability= [24,68,46,13,79,77]*/ 
//both above 2 methods do not maintain stable order of evens and odds


//M-3  taking extra space  (do maintain stable order of evens and odds)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> even;
        vector<int> odd;
        
        for(int i=0; i<n; i++)
            if((nums[i]&1) == 0) //even
                even.push_back(nums[i]);
        
        for(int i=0; i<n; i++)
            if((nums[i]&1) == 1) 
                odd.push_back(nums[i]); //odd
        
        int i;
        for(int x: even)
            nums[i++] = x;
        for(int x: odd)
            nums[i++] = x;
        
        return nums;
    }
};