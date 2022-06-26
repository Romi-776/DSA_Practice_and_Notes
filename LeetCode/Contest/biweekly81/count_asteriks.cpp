// Count Asterisks


// T.C = O(N), S.C = O(1)
class Solution
{
public:
    int countAsterisks(string s)
    {
        int count = 0, bar = 0;
        for (char i : s)
        {
            // keeping track of bars
            if (i == '|')
                bar++;
            // counting asterisks only before and after a pair of bars
            if (bar % 2 == 0 and i == '*')
                count++;
        }

        return count;
    }
};