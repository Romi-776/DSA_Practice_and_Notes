// Interleaving String - https://leetcode.com/problems/interleaving-string/

// Don't know much about DP but understood the approach from someone else's code and
//  then coded it that's why couldn't come up with time and space complexity
// would try my best with some other problems
class Solution
{
    int dp[104][104];
    bool sol(string s1, string s2, string s3, int i, int j)
    {
        int k = i + j;
        int n = s1.length(), m = s2.length(), p = s3.length();
        if (i >= n and j >= m and k >= p)
            return true;

        if (i >= n and s2[j] != s3[k] or j >= m and s1[i] != s3[k])
            return false;

        if (dp[i][j] == -1)
        {
            bool ans = 0;
            if (i < n)
            {
                if (s1[i] == s3[k])
                    ans = ans or sol(s1, s2, s3, i + 1, j);
                if (s2[j] == s3[k])
                    ans = ans or sol(s1, s2, s3, i, j + 1);
            }
            else if (j < m)
            {
                if (s2[j] == s3[k])
                    ans = ans or sol(s1, s2, s3, i, j + 1);
                if (s1[i] == s3[k])
                    ans = ans or sol(s1, s2, s3, i + 1, j);
            }
            dp[i][j] = ans;
        }

        return dp[i][j];
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        memset(dp, -1, sizeof(dp));
        return sol(s1, s2, s3, 0, 0);
    }
};