// Maximum Score Of Spliced Array - https://leetcode.com/problems/maximum-score-of-spliced-array/

// T.C = O(N), S.C = O(N)
class Solution
{
    // Kadane's algorithm
    int maxSubSum(vector<int> &arr)
    {
        int maxSum = arr[0], sum = 0;
        for (int i : arr)
        {
            if (sum < 0)
                sum = i;
            else
                sum += i;
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }

public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), sum1 = 0, sum2 = 0;

        // Created new vectors to store diff vectors
        vector<int> v1(n), v2(n);

        // calculating sums and diff vectors
        for (int i = 0; i < n; i++)
        {
            sum1 += nums1[i], sum2 += nums2[i];
            v1[i] = nums1[i] - nums2[i];
            v2[i] = nums2[i] - nums1[i];
        }

        // finding the possible total sum if some elements are shifted from
        // one vector to another in a profitable manner
        int ans1 = maxSubSum(v1) + sum2;
        int ans2 = maxSubSum(v2) + sum1;

        // max of possible answers is the answer
        return max(ans1, ans2);
    }
};