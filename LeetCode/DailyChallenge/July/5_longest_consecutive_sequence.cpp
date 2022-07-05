// Longest Consecutive Sequence - https://leetcode.com/problems/longest-consecutive-sequence/

/*
APPROACH:
firstly, finding all the unique elements and then for each element in nums, we're checking that is this num's
previous or next came is present in nums then we'll check for next prev or next next until we couldn't find one
and then we'll update our required ans according to the max no. of consecutive sequences that we found till now.
*/
// T.C = O(N), S.C = O(N)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> us;
        for (int i : nums)
            us.insert(i);

        int ans = 0;
        for (int i : nums)
        {
            if (us.find(i) != us.end())
            {
                int lo = i - 1, hi = i + 1;
                us.erase(i);
                while (us.find(lo) != us.end())
                    us.erase(lo--);
                while (us.find(hi) != us.end())
                    us.erase(hi++);

                ans = max(ans, hi - lo - 1);
            }
        }
        return ans;
    }
};