// Min Cost Climbing Stairs - https://leetcode.com/problems/min-cost-climbing-stairs/

// Solution - 1 Using DP (T.C = O(N), S.C = O(N) + O(N) for call stack)
class Solution
{
    int minCost(vector<int> &cost, vector<int> &dp, int n)
    {
        if (n < 0)
            return 0;
        else if (dp[n] != -1)
            return dp[n];
        return dp[n] = cost[n] + min(minCost(cost, dp, n - 1), minCost(cost, dp, n - 2));
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0], dp[1] = cost[1];
        return min(minCost(cost, dp, n - 1), minCost(cost, dp, n - 2));
    }
};

// Solution - 2 Using DP and removing call stack extra space
// T.C = O(N), S.C = O(N)
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

// Solution - 3 Using DP and removing all extra space
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int prev1 = cost[0], prev2 = cost[1];
        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1, prev2);
    }
};