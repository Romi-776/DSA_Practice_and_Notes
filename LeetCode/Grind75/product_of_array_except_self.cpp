//  Product of Array Except Self - https://leetcode.com/problems/product-of-array-except-self/

// Sol3 - Using the answer vector for computing prefix and postfix multiplication.
// T.C = O(N), S.C = O(1)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int pre = 1, post = 1;

        // doing the prefix multiplication
        for (int i = 0; i < n; i++)
        {
            if (i)
                pre *= nums[i - 1];
            ans[i] = pre;
        }

        // doing the postfix multiplication
        for (int j = n - 1; j >= 0; j--)
        {
            if (j < n - 1)
                post *= nums[j + 1];
            ans[j] *= post;
        }
        return ans;
    }
};

// Sol2 - Using Prefix and Suffix pre-computation (multiplication)
// T.C = O(N), S.C = O(N)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        // taking 2 extra vectors for pre-computing prefix and postfix multiplication
        vector<int> pre(n, 1), post(n, 1), ans;
        pre[0] = nums[0], post[n - 1] = nums[n - 1];

        for (int i = 1, j = n - 2; i < n; i++, j--)
        {
            pre[i] *= nums[i] * pre[i - 1];
            post[j] *= nums[j] * post[j + 1];
        }

        // now for each element, multiply all the nos. before
        // and after that number using pre and post multiplication vectors
        for (int i = 0; i < n; i++)
        {
            int mul = 1;
            if (i > 0)
                mul *= pre[i - 1];
            if (i < n - 1)
                mul *= post[i + 1];
            ans.push_back(mul);
        }

        return ans;
    }
};

// Sol1 - My naive solution using Power Function and Hashmap
// T.C = O(Nlog(M)), S.C = O(N) , here M = max value in nums vector
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // frequency mapping of each element
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }

        vector<int> ans;
        for (int i : nums)
        {
            // for each element
            int mul = 1;

            // getting the product of all elements using pow
            for (auto j : mp)
            {
                // current element is same as i so we're multiplying it 1 less than total times
                // otherwise multiply each and every element
                if (j.first == i)
                    mul *= pow(j.first, j.second - 1);
                else
                    mul *= pow(j.first, j.second);
            }
            ans.push_back(mul);
        }
        return ans;
    }
};