// Minimum Amount of Time to Fill Cups - https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

// Couldn't solve this in the contest

// Sol-1
// T.C = O(nlog(n)), S.C = O(1) where n = max value in amount array
/*
INTUITION
Minimizing the time by filling 2 cups at a time for max no. of times.
So, we need to take max of the 3 cups that need to be filled.
*/
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        priority_queue<int> pq;
        for (int i : amount)
            if (i > 0)
                pq.push(i);

        int time = 0;
        while (pq.size() > 1)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            x--, y--;
            if (x > 0) pq.push(x);
            if (y > 0) pq.push(y);
            time++;
        }

        if (pq.size())
            time += pq.top();

        return time;
    }
};



// Sol-2
// T.C = O(n), S.C = O(1)
/*
INTUITION/Observations
1. res >= max(A)
    Because each time,
    one type can reduce at most 1 cup
2. res >= ceil(sum(A) / 2)
    Because each time,
    we can fill up to 2 cups,
The possible strategy is greedily fill up 2 cups with different types of water.
We pick the 2 types with the most number of cups.
*/
int fillCups(vector<int> &amount)
{
    int mx = 0, sum = 0;
    for (int &a : amount)
    {
        mx = max(a, mx);
        sum += a;
    }
    return max(mx, (sum + 1) / 2);
}