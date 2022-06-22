// Spiral Matrix - https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    // Spiral Order Traversal of a Matrix
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        // i and j for traversal
        int i = 0, j = 0, rows = matrix.size(), cols = matrix[0].size();

        // count will store the no. of elements occurred till now
        int count = 0, total = rows * cols;

        // boundaries in four sides
        int up = 0, down = rows - 1, left = 0, right = cols - 1;

        // which direction we're moving right now
        string going_towards = "right";

        // until all the elements are not traversed
        while (count < total)
        {
            // logic for going in each direction and counting the no. of elements traversed till now
            // and changing the direction in order of traversal (clockwise)
            if (going_towards == "right")
            {
                while (j <= right)
                {
                    ans.push_back(matrix[i][j++]);
                    count++;
                }
                up++, j--, i++;
                going_towards = "down";
            }
            else if (going_towards == "down")
            {
                while (i <= down)
                {
                    ans.push_back(matrix[i++][j]);
                    count++;
                }
                right--, i--, j--;
                going_towards = "left";
            }
            else if (going_towards == "left")
            {
                while (j >= left)
                {
                    ans.push_back(matrix[i][j--]);
                    count++;
                }
                down--, j++, i--;
                going_towards = "up";
            }
            else
            {
                while (i >= up)
                {
                    ans.push_back(matrix[i--][j]);
                    count++;
                }
                left++, i++, j++;
                going_towards = "right";
            }
        }
        return ans;
    }
};