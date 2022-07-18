/*
SOL - 2 (someone else's solution short, crisp and clean but changes the graph data)
T.C = O(MN), S.c = O(MN)
Using DFS traversal and connected components
*/
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    max_area = max(max_area, AreaOfIsland(grid, i, j));
        return max_area;
    }

    int AreaOfIsland(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
        {
            grid[i][j] = 0;
            return 1 + AreaOfIsland(grid, i + 1, j) + AreaOfIsland(grid, i - 1, j) + AreaOfIsland(grid, i, j - 1) + AreaOfIsland(grid, i, j + 1);
        }
        return 0;
    }
};

/*
SOL - 1 (My solution very lengthy but without changing the graph's data)
T.C = O(MN), S.c = O(MN)
Using DFS traversal and connected components
can also be done using BFS traversal
*/
class Solution
{
    int area(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col)
    {
        // getting total no. of rows and cols
        int n = grid.size(), m = grid[0].size(), total_area = 0;

        // checking that the given row and col of source is in between our grid
        // and is not visited before and is also a land area
        if (row >= n or row < 0 or col >= m or col < 0 or vis[row][col] or !grid[row][col])
            return total_area; // if yes then we don't have any area of land

        // otherwise, mark the current area as visited and increment the total area
        vis[row][col] = 1, total_area++;

        // all the possible directions of adjacent possible areas
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // going in all the directions and adding its area into current components total area
        for (int i = 0; i < 4; i++)
        {
            total_area += area(grid, vis, row + dirs[i][0], col + dirs[i][1]);
        }

        return total_area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        // getting total no. of rows and cols
        int n = grid.size(), m = grid[0].size();

        // visited matrix for marking area is visited or not
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int max_area = 0;

        // checking each and every box of grid in order to find the max possible area out of it
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                    max_area = max(max_area, area(grid, vis, i, j));
            }
        }

        return max_area;
    }
};