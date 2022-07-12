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

// T.C = O(mn), S.C = O(1) if we don't consider recursive stack as external memory otherwise O(mn)
// Approach - DFS traversal
class Solution
{
    void dfs(vector<vector<int>> &image, vector<vector<bool>> &vis, int i, int j, int prevColor, int newColor)
    {
        // for all the cases where we don't or can't need to do anything
        if (i < 0 or j < 0 or i >= image.size() or j >= image[0].size() or vis[i][j] == true or image[i][j] == newColor or image[i][j] != prevColor)
            return;

        // otherwise marking the current pixel with new color
        image[i][j] = newColor;

        // checking for adjacent pixels in all the 4 directions
        dfs(image, vis, i + 1, j, prevColor, newColor);
        dfs(image, vis, i - 1, j, prevColor, newColor);
        dfs(image, vis, i, j + 1, prevColor, newColor);
        dfs(image, vis, i, j - 1, prevColor, newColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        dfs(image, vis, sr, sc, image[sr][sc], newColor);
        return image;
    }
};