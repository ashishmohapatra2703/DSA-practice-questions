class Solution
{
public:
    int findBitonicPoint(int arr[], int low, int high, int n) 
    {
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(mid>=1 && mid<=n-2)
            {
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) 
                    return mid;
            }
            if(mid==0)
            {
                if(arr[mid] > arr[mid+1])
                    return mid;
            }
            if(mid==n-1)
            {
                if(arr[mid] > arr[mid-1])
                    return mid;
            }
            
    
            else if(arr[mid+1] > arr[mid])
                low = mid + 1;
            else if(arr[mid-1] > arr[mid])
                high = mid - 1;
        }
    }
    int BinarySearchinSortedArray(int arr[], int low, int high, int key) 
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(key == arr[mid])
                return mid;
            else if(key < arr[mid])
                high = mid-1;
            else if(key > arr[mid])
                low = mid+1;
        }
        return -1; //key not found unsuccessful search
    }
    int BinarySearchinReverseSortedArray(int arr[], int low, int high, int key) 
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2; 
            if(key == arr[mid])
                return mid;
            else if(key < arr[mid])
                low = mid+1; /////// ->
            else if(key > arr[mid])
                high = mid-1; ////// <-
        }
        return -1; //key not found unsuccessful search
    }
    
    
    int findNumber(int arr[], int n, int key) 
    {
        int MaxEleIdx = findBitonicPoint(arr, 0, n-1, n);
        int KeyIdxinIncPart = BinarySearchinSortedArray(arr, 0, MaxEleIdx-1, key);
        int KeyIdxinDecPart = BinarySearchinReverseSortedArray(arr, MaxEleIdx, n-1, key);
        
        if(KeyIdxinIncPart==-1 && KeyIdxinDecPart==-1)
            return -1;
        else if(KeyIdxinIncPart >= 0)
            return KeyIdxinIncPart;
        else if(KeyIdxinDecPart >= MaxEleIdx)
            return KeyIdxinDecPart;
    }
}