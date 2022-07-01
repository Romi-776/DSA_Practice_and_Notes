// Longest Substring Without Repeating Characters - https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution
{
public:
    // T.C = O(N), S.C = O(1) because max 256 characters are possible
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0;
        int i = 0, j = 0, n = s.size();

        unordered_map<char, int> mp;

        // using sliding window
        while (j < n)
        {
            // incrementing frequency of each char
            mp[s[j]]++;

            // if some char repeats
            if (mp[s[j]] > 1)
            {
                // then remove it from map and decrease the window size
                while (mp[s[j]] > 1)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            // otherwise update the max_len accordingly
            else
                max_len = max(max_len, j - i + 1);

            // increase the window length
            j++;
        }
        return max_len;
    }
};