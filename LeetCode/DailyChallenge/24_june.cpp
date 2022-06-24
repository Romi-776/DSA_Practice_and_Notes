// Construct Target Array With Multiple Sums - https://leetcode.com/problems/construct-target-array-with-multiple-sums/

// T.C = O(NlogN), S.C = O(N)
class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        priority_queue<int> pq;
        long long int sum1 = 0;

        // getting total sum of all elements
        for (int i : target)
        {
            pq.push(i), sum1 += i;
        }

        // using the reverse process to predict that if we can make all the elements equal to 1 or not
        // by converting all current max elements into smaller elements and eventually to 1's
        while (pq.top() > 1)
        {
            // getting the max element from array
            int t = pq.top();
            pq.pop();

            // getting the rest of the sum (except current max element)
            sum1 -= t;

            // sum is not in valid range (so we can't make all 1's)
            if (sum1 <= 0 or sum1 >= t)
                return false;

            // sum == 1 means that we can convert any element to 1 with some no. of steps so its possible
            if (sum1 == 1)
                return true;

            // remainder when that current max got subtracted sum1 some no. of times
            int newVal = t % sum1;

            // we got a zero so its not possible
            if (newVal == 0)
                return false;

            // otherwise we will continue the process of checking possibility
            pq.push(newVal);

            // adding new num into our array
            sum1 += newVal;
        }

        return true;
    }
};