// Minimum Moves to Equal Array Elements II - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

// T.C = O(Nlog(N)), S.C = O(1)
/*
INTUITION
Min. no. of steps will be required when each number will become equal to the
median of the numbers given in nums vector
*/
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        // sorting before finding median
        sort(nums.begin(), nums.end());

        // finding the median
        int n = nums.size() / 2;

        // calculating the difference between each num and median num
        int sum = 0;
        for (int i : nums)
            sum += abs(nums[n] - i);
        return sum;
    }
};