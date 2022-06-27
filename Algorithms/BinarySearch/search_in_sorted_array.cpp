// (T.C = O(log(n)), S.C = O(1))
// Here, n = no. of elements in the array

int search(vector<int> &arr, int element)
{
    int n = arr.size();
    int lo = 0, hi = n - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (element == arr[mid])
            return mid;
        else if (element < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return -1;
}

/*

2. Finding an element in descending sorted array
(Implement binary search but in opposite manner, i.e., if ele == arr[mid] return index otherwise if ele < arr[mid] go towards right otherwise go towards left)


3. Finding an element in sorted array whose order is not known (ORDER AGNOSTIC SEARCH)
(Firstly, check if the first_ele <= last_ele then ascending otherwise descending and then implement B.S accordingly if both elements are not same)
  
*/