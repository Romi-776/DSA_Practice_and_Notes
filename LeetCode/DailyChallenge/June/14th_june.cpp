// Delete Operation for Two Strings - https://leetcode.com/problems/delete-operation-for-two-strings/

// T.C = O(L1*L2), S.C = O(L1*L2)
class Solution
{
    // stores the no. of steps required to equalize the remaining word1[i:end] and word2[j:end]
    vector<vector<int>> dp;

    vector<int> v;
    int solve(string &w1, string &w2, int i, int j)
    {
        int n = w1.length(), m = w2.length();
        if (i == n and j == m)
            return 0; // both string have been equalized

        // one string ends then the remaining characters of the other string needs to be removed
        if (i == n)
            return m - j;
        if (j == m)
            return n - i;

        if (dp[i][j] != -1)
            return dp[i][j]; // answer already present

        // no deletion for current char as both equal going to next one
        if (w1[i] == w2[j])
            return dp[i][j] = solve(w1, w2, i + 1, j + 1); // calculating and storing answer

        // 1 current character deletion + min(after deleting w1[i], after deleting w2[j])
        return dp[i][j] = (1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1))); // calculating and storing answer
    }

public:
    int minDistance(string &word1, string &word2)
    {
        dp.resize(size(word1) + 1, vector<int>(size(word2) + 1, -1));
        return solve(word1, word2, 0, 0);
    }
};