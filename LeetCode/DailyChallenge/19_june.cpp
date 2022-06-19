// Search Suggestions System - https://leetcode.com/problems/search-suggestions-system/

// T.C. = O(n*log(n) + n + m)
// OPTIMIZED AND SHORT SOLUTION USING TWO POINTER
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> ans;

        // sorting the products alphabetically in order to search better
        sort(products.begin(), products.end());

        // taking two pointers in which words with valid prefix will lie
        int lo = 0, hi = products.size() - 1;

        // iterating through each char for prefix matching
        for (int i = 0; i < searchWord.size(); i++)
        {
            // going towards if the current word's size is smaller than the prefix length
            // or this word doesn't have the same prefix
            while (lo <= hi and (products[lo].size() <= i or products[lo][i] != searchWord[i]))
                lo++;

            // similar to above but going towards right
            while (lo <= hi and (products[hi].size() <= i or products[hi][i] != searchWord[i]))
                hi--;

            // storing the words that are suggested for current prefix
            vector<string> res;
            for (int i = 0, j = lo; i < 3 and j <= hi; i++, j++)
                res.push_back(products[j]);
            ans.push_back(res);
        }
        return ans;
    }
};

// T.C. = O(n*log(n) + n + m^2)
// NOT OPTIMIZED BUT AC SOLUTION USING TWO POINTER
class Solution
{
    bool pref_not_equal(string str, string prefix)
    {
        int pref_size = prefix.size(), str_size = str.size();
        if (pref_size > str_size)
            return true;
        int i = 0;
        while (i < pref_size)
        {
            if (str[i] != prefix[i])
                return true;
            i++;
        }
        return false;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());

        int lo = 0, hi = products.size() - 1;
        string prefix = "";

        for (char c : searchWord)
        {
            prefix += c;

            while (lo <= hi and pref_not_equal(products[lo], prefix))
                lo++;
            while (lo <= hi and pref_not_equal(products[hi], prefix))
                hi--;

            vector<string> res;
            for (int i = 0, j = lo; i < 3 and j <= hi; i++, j++)
                res.push_back(products[j]);
            ans.push_back(res);
        }
        return ans;
    }
};