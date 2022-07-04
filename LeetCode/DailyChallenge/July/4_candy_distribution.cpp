// Candy - https://leetcode.com/problems/candy/

// T.C = O(N), S.C = O(N)
/*
INTUITION
We have to give higher rating person greater number of candies than its neighbors, so we divided
the problem into sub-problem of giving more number of candies when the current child's rating
is greater than the left child and similarly for the right child. And then checking the max
from left or right's requirement.
*/
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int candies = 1, n = ratings.size(), count = 0;
        vector<int> arr(n, 1);
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i - 1])
                arr[i] = arr[i - 1] + 1;

        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                arr[i] = max(arr[i + 1] + 1, arr[i]);

        for (int i : arr)
            count += i;

        return count;
    }
};