// Minimum Operations to Reduce X to Zero - https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/submissions/

// T.C = O(N), S.C = O(1)
class Solution
{
public:
    // we can use sliding window method to find longest sub-array of sum(nums)-x
    // Then our answer would be nums.size()-size_of_longest_sub-array
    int minOperations(vector<int> &nums, int x)
    {
        // firstly calculate the sum of all the numbers in nums
        int sum = 0, n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);

        // required sum equals total sum, i.e, return n
        if (x == sum)
            return n;

        // otherwise subtract x from sum in order to find the required window of max_len
        sum -= x;

        // using sliding windo
        int s = 0, mx_len = 0, i = 0, j = 0;
        while (j < n)
        {
            s += nums[j];
            if (s == sum)
                mx_len = max(mx_len, j - i + 1);
            else if (s > sum)
            {
                while (i < j and s > sum)
                    s -= nums[i++];
                if (s == sum)
                    mx_len = max(mx_len, j - i + 1);
            }
            j++;
        }

        // if we have some window size then the remaining numbers have the answer
        // otherwise we don't have any answer
        return (mx_len ? n - mx_len : -1);
    }
};