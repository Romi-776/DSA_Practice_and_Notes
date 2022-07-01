// Minimum Deletions to Make Character Frequencies Unique - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

// T.C = O(N), S.C = O(N)
/*
INTUITION
Greedy Algorithm
Count each character first. For each 26 characters, check if it's count is already used. If so, delete characters until you find unused count,
or reach zero
*/
class Solution
{
public:
    int minDeletions(string s)
    {
        // couting frequencies of each character
        vector<int> freqs(26);
        for (char c : s)
            freqs[c - 'a']++;

        // checking which frequencies occurred till now
        unordered_map<char, int> freq_count;
        for (int i : freqs)
            freq_count[i]++;

        // sorting the frequencies
        sort(freqs.begin(), freqs.end());

        // stores the total characters to be deleted
        int count = 0;

        // iterating through frequencies
        for (int i = 0; i < freqs.size() - 1; i++)
        {
            // current and next frequencies area same
            if (freqs[i] == freqs[i + 1])
            {
                // until we find a frequency that haven't occurred till now
                while (freqs[i] and freq_count[freqs[i]])
                    freqs[i]--, count++; // we're going to delete characters of current type

                // we found best suited frequency
                freq_count[freqs[i]]++;
            }
        }

        return count;
    }
};