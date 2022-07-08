// Paint House 3 - https://leetcode.com/problems/paint-house-iii/

// Barely understood this answer

// Reference: https://www.youtube.com/watch?v=7Evjw2VM240

class Solution
{
public:
    int dp[105][25][105];

    int solve(int i, int j, int k, vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        if (k > target)
            return INT_MAX / 2;

        if (i == m)
            return (k == target) ? 0 : INT_MAX / 2;

        if (dp[i][j][k] != -1)
            return (dp[i][j][k]);
        else
        {
            int res = INT_MAX / 2;
            if (houses[i])
            {
                res = min(res, solve(i + 1, houses[i], (houses[i] == j) ? k : k + 1, houses, cost, m, n, target));
            }
            else
            {
                for (int x = 0; x < n; x++)
                {
                    res = min(res, cost[i][x] + solve(i + 1, x + 1, (x + 1 == j) ? k : k + 1, houses, cost, m, n, target));
                }
            }
            dp[i][j][k] = res;
        }

        return dp[i][j][k];
    }

    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        memset(dp, -1, sizeof(dp));
        int res = solve(0, 0, 0, houses, cost, m, n, target);
        return (res == INT_MAX / 2) ? -1 : res;
    }
};