// Flood Fill - https://leetcode.com/problems/flood-fill/

// T.C = O(mn), S.C = O(mn)
// Approach - BFS traversal
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        // no. of rows and cols
        int n = image.size(), m = image[0].size();

        // visited matrix initially set to false
        vector<vector<bool>> vis(n, vector<bool>(m));

        // queue for BFS traversal
        queue<pair<int, int>> q;
        q.push({sr, sc}), vis[sr][sc] = true;

        // curr pixel's color
        int start_col = image[sr][sc];

        // directions in which we can move
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // BFS traversal
        while (q.size())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            // changing the color to the required one
            image[x][y] = color;
            for (auto dir : dirs)
            {
                int r = dir[0] + x, c = dir[1] + y;

                // checking that the color of the current pixel is same as that of the src and is not visited
                if (r >= 0 and r < n and c >= 0 and c < m and !vis[r][c] and image[r][c] == start_col)
                    q.push({r, c}), vis[r][c] = true;
            }
        }

        return image;
    }
};