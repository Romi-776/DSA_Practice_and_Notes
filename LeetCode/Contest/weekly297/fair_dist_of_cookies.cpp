// Fair Distribution of Cookies


// USED BACKTRACKING AS THE TEST CASES WERE VERY SMALL
// T.C = O(K^N), here k = no. of subset choices and n = no. of elements
class Solution
{
    int ans = INT_MAX;
    // trying to generate all possible combinations of dividing the cookies into k bags
    void find_best(vector<int> &bags, vector<int> &cookies, int i, int k)
    {
        if (i < cookies.size())
        {
            for (int j = 0; j < k; j++)
            {
                bags[j] += cookies[i];
                find_best(bags, cookies, i + 1, k);
                bags[j] -= cookies[i];
            }
        }
        else
        {
            int ma = INT_MIN;
            for (int bag : bags)
                ma = max(ma, bag);
            ans = min(ans, ma);
        }
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> v(k); // used to stored the sum of cookies in the ith bag where 0 <= i < k
        find_best(v, cookies, 0, k);
        return ans;
    }
};