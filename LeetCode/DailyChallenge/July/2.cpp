// Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts - https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

/*
INTUITION
In order to get max area of a piece of cake, we need to maximize the length and breadth obtained from the cuts
so will find the max_diff_between_cuts in order to find the maximum length and breadth and then we'll calculate area.
*/
class Solution
{
    const long long mod = 1e9 + 7;
    int max_diff_between_cuts(int upper_limit, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());

        int max_diff = cuts[0], i;
        for (i = 1; i < cuts.size(); i++)
        {
            max_diff = max(max_diff, cuts[i] - cuts[i - 1]);
        }

        max_diff = max(max_diff, upper_limit - cuts[i - 1]);
        return max_diff;
    }

public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        int length = max_diff_between_cuts(h, horizontalCuts);
        int breadth = max_diff_between_cuts(w, verticalCuts);

        int area = ((length % mod) * (breadth % mod)) % mod;
        return area;
    }
};