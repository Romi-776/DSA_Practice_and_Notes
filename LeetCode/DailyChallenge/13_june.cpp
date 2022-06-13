// Triangle - https://leetcode.com/problems/triangle/

// T.C = O(n^2), S.C = O(n)
class Solution
{
public:
    // using DP to store the possible minimum sum of path starting from the lowermost
    // row and building that path till the uppermost row
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // getting the lowermost row
        vector<int> ans(triangle.back());

        // traversing the rows from bottom to up
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            // for each element calculating the possible minimum sum of path from that
            // element to the last last row
            for (int j = 0; j < triangle[i].size(); j++)
                ans[j] = triangle[i][j] + min(ans[j], ans[j + 1]);
        }

        // returning the minimum possible sum of path
        return ans[0];
    }
};