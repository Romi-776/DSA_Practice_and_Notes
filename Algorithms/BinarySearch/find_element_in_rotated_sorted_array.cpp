// (We can first find the no. of rotations done and then we have two separate sorted arrays towards the left of min_ele_index and towards right of max_ele_index
// then we'll simply apply the binary on both the left and right arrays)

// Another approach
int find_in_rotated_sorted_array(vector<int> &A)
{
    // store the index of min_ele, i.e, no.of rotations
    // then use the following code
    // The usual binary search and accounting for rotation.

    int rot = num_of_rotations(A);

    int lo = 0, hi = A.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int realmid = (mid + rot) % n;
        if (A[realmid] == target)
            return realmid;
        if (A[realmid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}
