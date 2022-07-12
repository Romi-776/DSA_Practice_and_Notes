// Matchsticks to Square -  https://leetcode.com/problems/matchsticks-to-square/


/*
T.C = O(4^N), S.C = O(1)
INTUITION:
Using backtracking and checking all possible ways in which these sticks can be placed to
make a square out of it.
*/
class Solution
{
    bool backTrack(vector<int> &matchsticks, vector<int> &sides, int i, int possibleLen)
    {
        // we have used all matchsticks
        if (i == matchsticks.size())
            return true;

        // trying to add the current matchstick to each and every side
        for (int j = 0; j < 4; j++)
        {
            // this side can hold this matchstick while maintaining the required maxLen of side
            if (sides[j] + matchsticks[i] <= possibleLen)
            {
                // trying and then removing this possibility
                sides[j] += matchsticks[i];

                // and we got a positive answer then yes its possible
                if (backTrack(matchsticks, sides, i + 1, possibleLen))
                    return true;
                sides[j] -= matchsticks[i];
            }
        }

        return false;
    }

public:
    bool makesquare(vector<int> &matchsticks)
    {
        // don't have required no. of matchsticks
        if (matchsticks.size() < 4)
            return false;
        int sum = 0;
        for (int i : matchsticks)
            sum += i;

        // couldn't divide into 4 equal sides
        if (sum % 4)
            return false;

        // max possible length of a side
        int possibleLen = sum / 4;

        vector<int> sides(4, 0);

        // sorting for later use
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        // backtracking to solution
        return backTrack(matchsticks, sides, 0, possibleLen);
    }
};