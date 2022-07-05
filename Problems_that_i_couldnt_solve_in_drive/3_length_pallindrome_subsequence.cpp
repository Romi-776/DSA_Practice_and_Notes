// Unique Length-3 Palindromic Subsequences - https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

/*
DRIVE: WALMART
Question was similar to this question
*/

/*
APPROACH:
For this problem, we just need to find the no. of unique characters that occurred in b/w the
first and last occurrence of a character.
*/

// Well structured code
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();

        // storing the first and last occurrence of each of the 26 chars
        vector<pair<int, int>> first_last(26, {-1, -1});

        for (int i = 0; i < n; i++)
        {
            if (first_last[s[i] - 'a'].first == -1)
                first_last[s[i] - 'a'].first = i;
            else
                first_last[s[i] - 'a'].second = i;
        }

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            // for each char occurring more than once, counting no. of unique chars in between
            // its first and last occurrence
            if (first_last[i].second != -1)
            {
                unordered_set<char> us;
                for (int j = first_last[i].first + 1; j < first_last[i].second; j++)
                    us.insert(s[j]);
                count += ((int)us.size());
            }
        }

        return count;
    }
};

// My Naive solution with the given approach
// T.C = O(N), S.C = O(N)
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        // frequency map
        unordered_map<char, int> freq;
        int n = s.length();

        // calculating frequency for each character
        for (char i : s)
            freq[i]++;

        // count of all palindromic subsequences
        int count = 0;

        for (auto i : freq)
        {
            // for each char with more than one freq
            if (i.second > 1)
            {
                // to store all unique chars
                unordered_set<char> us;
                int lo = 0, hi = n - 1;

                // finding the first occurrence of a char
                for (; lo < hi; lo++)
                    if (s[lo] == i.first)
                        break;

                // finding last occurrence of a char
                for (; hi > lo; hi--)
                    if (s[hi] == i.first)
                        break;
                // after the first occurrence
                lo++;

                // checking all the unique chars
                for (; lo < hi; lo++)
                    us.insert(s[lo]);

                // counting all the unique chars
                count += us.size();
            }
        }
        return count;
    }
};
