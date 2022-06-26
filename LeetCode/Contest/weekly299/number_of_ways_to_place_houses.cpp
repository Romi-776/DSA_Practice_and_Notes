// Count Number of Ways to Place Houses - https://leetcode.com/problems/count-number-of-ways-to-place-houses/

// T.C = O(N), S.C = O(1)
/*
INTUITION:
    The opposite sides are independent to each other.
    So, the total number of ways would be the product of no.of ways of one side and another side.

    Let's try to write the result for some numbers:

    1 -> 4 (2*2)
    2 -> 9 (3*3)
    3 -> 25 (5*5)
    4 -> 64 (8*8)
    If you observe carefully, a fibonacci type sequence is formed.
*/
class Solution
{
    const int mod = 1e9 + 7;

public:
    int countHousePlacements(int n)
    {
        if (n == 1)
            return 4;
        if (n == 2)
            return 9;

        long long prev = 3, prev_prev = 2;
        long long ans = 0;

        // calculating terms just like fibonacci series
        for (int i = 3; i <= n; i++)
        {
            long long temp = prev;
            prev = (prev + prev_prev) % mod;
            prev_prev = temp;
        }

        return (int)(((prev % mod) * (prev % mod)) % mod);
    }
};