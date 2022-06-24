// Two Sum - https://leetcode.com/problems/two-sum/

// Sol2 - Using Hashmap - T.C = O(N), S.C = O(N)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // using map to store which element has occurred till now at which index
        unordered_map<int, int> mp;

        int idx = 0;

        vector<int> ans;
        for (int i : nums)
        {
            // the complement of the current element is present in our map
            if (mp[target - i])
            {
                // so adding the curren index and complement's index into our answer
                ans.push_back(mp[target - i]);
                ans.push_back(idx);
                // we need no further searching
                break;
            }

            // otherwise adding current element and its index
            mp[i] = idx;

            // going to next element
            idx++;
        }
        return ans;
    }
};

// Sol2 - Using 2 for loops - T.C = O(N^2), S.C = O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans;

        // for each index, we're finding is there any number after that index such that
        // both the numbers adds up to target
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i), ans.push_back(j);
                    break;
                }
        }
        return ans;
    }
};