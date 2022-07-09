// Jump Game VI - https://leetcode.com/problems/jump-game-vi/

// T.C = O(N), S.C = O(k)
/*
INTUITION
Storing the max sum of prev possible k values at the start of dq at each index
and at the end we will have the required max sum of the values
*/
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++)
        {
            // max possible sum by adding the current value
            // and prev possible k-1 values
            nums[i] = nums[i] + nums[dq.front()];

            // at each interval maintaining the max sum index at the start of the deque
            while (dq.size() and nums[i] >= nums[dq.back()])
                dq.pop_back();

            // inserting current value
            dq.push_back(i);

            // if the value at the start is out of bound then we're removing it
            if (i - dq.front() >= k)
                dq.pop_front();
        }
        // returning the required value
        return nums[n - 1];
    }
};