// Kth Largest Element in an Array - https://leetcode.com/problems/kth-largest-element-in-an-array/

// SOL4
// T.C = Theta(N), O(N^2), S.C = O(1) Using quick select / partition algo of Quick Sort algorithm
class Solution
{
    // it will use partitioning algo to set some elements to its correct position
    // and partitioning elements into 2 halves where one half have all smaller than or equal
    // elements in left side of pivot and vice-versa
    int quick_select(vector<int> &nums, int lo, int hi)
    {
        int pivot = lo, i = lo;
        while (i < hi)
        {
            if (nums[i] <= nums[hi])
                swap(nums[i], nums[pivot]), pivot++;
            i++;
        }
        swap(nums[pivot], nums[hi]);

        return pivot;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        // converting k to kth index for a sorted array from behind
        k = n - k;

        // starting our search in the whole array
        int lo = 0, hi = n - 1, pivot = 0;
        while (lo <= hi)
        {
            // got the pivot index
            pivot = quick_select(nums, lo, hi);

            // pivot is k which means kth largest element is at its correct position
            if (pivot == k)
                break;          // no need to go ahead
            else if (pivot > k) // kth element is in left half
                hi = pivot - 1; // going towards left half
            else
                lo = pivot + 1; // otherwise going towards right half
        }

        return nums[pivot]; // returning the required element
    }
};





// SOL3
// T.C = O(Nlog(N)), S.C = O(1) Sorting the vector/array
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - k];
    }
};






// SOL2
// T.C = O(Nlog(K)), S.C = O(K) Using Priority Queue (MIN HEAP)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // stores smallest element at top
        priority_queue<int, vector<int>, greater<int>> pq;

        // adding all the elements to the queue
        for (int num : nums)
        {
            pq.push(num);

            // queue size is greater so we're discarding values that aren't required
            if (pq.size() > k)
                pq.pop();
        }
        // returning the kth largest element
        return pq.top();
    }
};





// SOL1
// T.C = O(Nlog(N)), S.C = O(N) Using Priority Queue (MAX HEAP)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // stores largest element at top
        priority_queue<int> pq;

        // adding all the element
        for (int num : nums)
            pq.push(num);

        // deleting k-1 elements to get to the kth largest element at top
        while (k > 1)
            pq.pop(), k--;
        return pq.top();
    }
};