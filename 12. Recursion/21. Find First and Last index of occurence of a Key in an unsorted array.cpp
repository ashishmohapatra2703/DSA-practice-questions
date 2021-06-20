class Solution
{
  public:
    //return the FirstIndexOccurrenceOfKey in elements from idxth index to last index
    int FirstIndexOccurrenceOfKey(int a[], int idx, int length, int key)
    {
        if(idx == length)
            return -1;
            
        // int firstidxoccurinRestArr = FirstIndexOccurrenceOfKey(a, idx+1, length, key);
        // if(a[idx] == key)
        //     return idx;
        // else
        //     return firstidxoccurinRestArr;
        if(a[idx] == key)
            return idx;
        else
            return FirstIndexOccurrenceOfKey(a, idx+1, length, key);
    }
    
    //return the LastIndexOccurrenceOfKey in elements from idxth index to last index
    int LastIndexOccurrenceOfKey(int a[], int idx, int length, int key)
    {
        if(idx == length)
            return -1;
            
        int lastidxoccurinRestArr = LastIndexOccurrenceOfKey(a, idx+1, length, key);
        if(lastidxoccurinRestArr == -1 && a[idx] == key)
            return idx;
        else //if(lastidxoccurinRestArr >= 0 || (lastidxoccurinRestArr == -1 && a[idx] != key))
            return lastidxoccurinRestArr;
    }
    
    vector<int> findIndex(int a[], int n, int key)
    {
        vector<int> occur(2);
        occur[0] = FirstIndexOccurrenceOfKey(a, 0, n, key); 
        occur[1] = LastIndexOccurrenceOfKey(a, 0, n, key);
        
        return occur;
    }
};