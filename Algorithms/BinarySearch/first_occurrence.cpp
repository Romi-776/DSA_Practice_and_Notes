// (We can implement the same algorithm for last occurrence by using res = mid, start = mid+1)
// NOTE: we're just storing the index of the possible result and will return the result at the end

int first_occurrence(vector<int> &arr, int element)
{
    int n = arr.size();
    int lo = 0, hi = n - 1, res = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (element == arr[mid])
            res = mid, hi = mid - 1;
        else if (element < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return res;
}