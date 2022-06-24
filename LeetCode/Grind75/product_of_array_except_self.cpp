//  Product of Array Except Self - https://leetcode.com/problems/product-of-array-except-self/


// Sol3 - To be implemented




// Sol2 - Using Prefix and Suffix pre-computation (multiplication)
// T.C = O(N), S.C = O(N)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> pre(n, 1), post(n, 1), ans;
        pre[0] = nums[0], post[n - 1] = nums[n - 1];

        for (int i = 1, j = n - 2; i < n; i++, j--)
        {
            pre[i] *= nums[i] * pre[i - 1];
            post[j] *= nums[j] * post[j + 1];
        }

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