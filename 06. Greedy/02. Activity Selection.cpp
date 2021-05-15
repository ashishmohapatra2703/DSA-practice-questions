/* Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.
Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 3 and 4. */
class Solution
{
    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second < b.second;
    }
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> activity(n);
        for(int i=0; i<n; i++)
        {
            activity[i] = make_pair(start[i], end[i]);
        }
        
        sort(activity.begin(), activity.end(), comp);
        
        int endDayLimit = activity[0].second;
        int maxActivities = 1;
        for(int i=1; i<n; i++)
        {
            if(activity[i].first > endDayLimit)
            {
                endDayLimit = activity[i].second;
                maxActivities++;
            }
        }
        return maxActivities;
    }
};

/* Algorithm:
• Sort the activities according to their finishing day.
• Push the pair of starting and finish day and their index as pair in another list.
• If the starting day of current activity is greater than the finish day of previously selected activity 
  then increment the counter and update previously selected activity .
• Return the counter. */