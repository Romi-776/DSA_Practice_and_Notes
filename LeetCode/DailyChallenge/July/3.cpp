// Wiggle Subsequence - https://leetcode.com/problems/wiggle-subsequence/

// T.C = O(N), S.C = O(1)
/*
INTUITION
Greedy approach of assuming diff with curr element as 0 then we'll check diff from 2nd element i
with i-1th element and if the curr and last_diff are opposite or zero then we'll update the length of
the possible subsequence.
*/
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size(), last_diff = 0, count = 1;
        for (int i = 1; i < n; i++)
        {
            int diff = nums[i] - nums[i - 1];
            if ((diff < 0 and last_diff >= 0) or (diff > 0 and last_diff <= 0))
                count++, last_diff = diff;
        }
        return count;
    }
};