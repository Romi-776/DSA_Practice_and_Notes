// Maximum Erasure Value - https://leetcode.com/problems/maximum-erasure-value/

// T.C = O(N), S.C = O(m), where m = no. of unique nos. in nums vector
class Solution
{
public:
    // we can use sliding window such that it will always contain only unique nos
    // and we will also maintain the sum of nos in the window and our answer will be
    //  the max of all the sum that we encountered
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int i = 0, j = 0, n = nums.size(), sum = 0, ans = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[nums[j]]++;
            while (i < j and mp[nums[j]] > 1)
            {
                sum -= nums[i];
                mp[nums[i]]--;
                if (!mp[nums[i]])
                    mp.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            ans = max(sum, ans);
            j++;
        }
        return ans;
    }
};