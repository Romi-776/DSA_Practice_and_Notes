// Number of Islands - https://leetcode.com/problems/number-of-islands/

// T.C = O(MN), S.C = O(MN)
/*
INTUITION
Traversing each and every part of our grid and if we found some land then we'll increment the islands count
and will also mark all the connected land parts with the current part using BFS traversal
*/
class Solution
{
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        int rows = grid.size(), cols = grid[0].size();

        // possible directions in which we can go
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        q.push({row, col}), visited[row][col] = 1;

        while (q.size())
        {
            // getting the current position
            row = q.front().first, col = q.front().second;
            q.pop();

            // finding all the adjacent parts where we have not visited
            // and is also a land
            for (auto dir : dirs)
            {
                int r = dir[0] + row, c = dir[1] + col;

                // checking that the current position exists in the grid
                if (r < rows and r >= 0 and c >= 0 and c < cols and grid[r][c] == '1' and visited[r][c] == -1)
                    q.push({r, c}), visited[r][c] = 1; // mark it visited and check its adjacent neighbors later
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size(), islands = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == '1' and visited[i][j] == -1) // we are on land which is not visited then visit that
                    bfs(i, j, grid, visited), islands++;       // as well as its adjacent neighbors and count the islands

        return islands;
    }
};