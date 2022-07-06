// Fibonacci Number - https://leetcode.com/problems/fibonacci-number/

// recursive fibonacci - T.C = (2^N)
class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// iterative fibonacci - T.C = O(N)
class Solution
{
public:
    int fib(int n)
    {
        int prev = 1, prev_prev = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = prev;
            prev = prev_prev + prev;
            prev_prev = temp;
        }
        return prev_prev;
    }
};