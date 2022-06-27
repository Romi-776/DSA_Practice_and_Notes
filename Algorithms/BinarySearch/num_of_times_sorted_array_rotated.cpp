(Similarly, we can do this for clockwise rotations by using (last_index - index_of_max_num == no_of_rotations))

//  This is For Anticlockwise rotation, i.e., 1 2 3 -> 3 1 2
//  NOTE : Here, (index of min_ele == no.of rotations done)

// Simple and concise code with a trick to remember
int num_of_rotations(vector<int>& A)
{
    int lo = 0, hi = A.size() - 1;
    // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] > A[hi])
            lo = mid + 1;
        else
            hi = mid;
    }
    // lo==hi is the index of the smallest value and also the number of places rotated.
    return lo;
}

// Simple but long code
int num_of_rotations(vector<int> &arr)
{
    int n = arr.size();
    if (arr[0] >= arr[n - 1] or n > 1)
    {
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if (arr[mid] < arr[prev] and arr[mid] < arr[next]) // smallest ele will be smaller than both prev and next elements
                return mid;                                    // so we found the index of smallest_ele ,i.e, no. of rotations
            else if (arr[mid] > arr[next])                     // we're at the biggest ele
                return next;                                   // so at next index will be the smallest element
            else if (arr[mid] > arr[end])                      // curr_ele is greater than last_ele, so this area is not sorted
                start = mid + 1;                               // that's why going towards right
            else                                               // otherwise
                end = mid - 1;                                 // going towards left
        }
    }
    return 0;
}