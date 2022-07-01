// Longest Palindromic Substring - https://leetcode.com/problems/longest-palindromic-substring/submissions/

// T.C = O(N^2), S.C = O(1)
class Solution
{
    int start, len;

    // checks the max_possible_len of a pallindrome that can be made
    // by taking ith and jth character as center
    void check_pallindrome_for_this_center(string &s, int i, int j)
    {
        // expanding our pallindrome size
        while (i >= 0 and j < s.length() and s[i] == s[j])
            i--, j++;

        // current pallindrome size is greatest among all the pallindromes
        // that occurred till now
        if (len < j - i - 1)
            start = i + 1, len = j - i - 1;
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;

        // checking for all possible centers from where odd or even length
        // pallindrome can be made
        for (int i = 0; i < n - 1; i++)
        {
            check_pallindrome_for_this_center(s, i, i);     // odd length pallindrome
            check_pallindrome_for_this_center(s, i, i + 1); // even length pallindrome
        }

        // creating the required answer
        string ans = "";
        for (int i = start; i < start + len; i++)
            ans += s[i];
        return ans;
    }
};