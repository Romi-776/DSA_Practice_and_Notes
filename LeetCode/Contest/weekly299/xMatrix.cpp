// Check if Matrix Is X-Matrix - https://leetcode.com/problems/check-if-matrix-is-x-matrix/

// T.C = O(N*N), S.C = O(1)
class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // checking that left to right diagonal doesn't have a 0
        for (int i = 0, j = 0; i < n; i++, j++)
        {
            if (grid[i][j] == 0)
                return false;
            grid[i][j] = -1;
        }
        // checking that right to left diagonal doesn't have a 0
        for (int i = 0, j = n - 1; i < n; j--, i++)
        {
            if (grid[i][j] == 0)
                return false;
            grid[i][j] = -1;
        }

        // checking that other elements are zeroes only
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                    return false;
            }
        }
        return true;
    }
};