// Maximum Sub Array - https://leetcode.com/problems/maximum-subarray/

// T.C = O(N), S.C = O(1)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // assuming the current subarray have maxSubSum
        int maxSubSum = nums[0], sum = 0;

        // iterating through each element
        for (int i: nums)
        {
            // curr sum is negative (so not needed, changing it to curr element)
            if (sum < 0)
                sum = i;
            else sum += i; // otherwise we have positive sum which can be maxSubSum

            // updating our maxSubSum 
            maxSubSum = max(maxSubSum, sum);
        }
        return maxSubSum;
    }
};