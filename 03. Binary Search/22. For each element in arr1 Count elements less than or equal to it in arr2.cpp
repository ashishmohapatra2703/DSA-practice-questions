/*Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. 
For each element in arr1[] count elements less than or equal to it in array arr2[].
Input : arr1[] = [1, 2, 3, 4, 7, 9]
        arr2[] = [0, 1, 2, 1, 1, 4]
Output : [4, 5, 5, 6, 6, 6]
So the number of elements less than or equal to 
1 is 4, 2 is 5, 3 is 5, 4 is 6, 7 is 6 and 9 is 6.

Input : arr1[] = [5, 10, 2, 6, 1, 8, 6, 12]
        arr2[] = [6, 5, 11, 4, 2, 3, 7]
Output : [4, 6, 1, 5, 0, 6, 5, 7]
So the number of elements less than or equal to 
5 is 4, 10 is 6, 2 is 1, 6 is 5, 1 is 0, 8 is 6, 
6 is 5 and 12 is 7        */
int CountElementsLessthanorEqual(int arr2[], int n, int key) //key ~ arr1[i]
{
    int low = 0; int high = n-1;
    int floor_index = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr2[mid] > key)
        {
            high = mid-1; //search in left segment
        }
        else if(arr2[mid] <= key) //possible candidate
        {
            floor_index = mid; //store the candidate and then
            low = mid+1; //search in right segment
        }
    }
    return floor_index + 1; //It gives the Count of the Elements in arr2[] which is <= key
}
vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
{
    sort(arr2, arr2+n);
    
    vector<int> v(m);
    for(int i=0; i<m; i++)
    {
        v[i] = CountElementsLessthanorEqual(arr2, n, arr1[i]);
        //Count elements <= arr1[i] ,  in array arr2[].
    }
    return v;
}