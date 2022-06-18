// Prefix and Suffix Search - https://leetcode.com/problems/prefix-and-suffix-search/

// NOTE: THIS SOLUTION CAN BE SOLVED WITH TRIE BUT I DON'T KNOW MUCH ABOUT IT THAT'S WHY I SEARCHED LEARNED AND 
// IMPLEMENTED A SOLUTION WITHOUT TRIE (USING HASHMAP, not the best but AC solution)

// T.C = O(N*L^4), S.C = O(N*L^4)
class WordFilter
{
    // stores the highest index for a word that have different combination of prefix
    // and suffix of a word
    unordered_map<string, int> pref_suff_index;

public:
    WordFilter(vector<string> &words)
    {
        // for ith word
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            int word_len = word.length();
            // generating all the combinations of prefixes and suffixes that can be generated
            for (int j = 1; j <= word_len; j++)
            {
                string pref = word.substr(0, j);
                for (int k = 0; k < word_len; k++)
                {
                    string suff = word.substr(k, word_len);
                    // and then adding that combination together with the highest possible
                    // index they can have
                    pref_suff_index[pref + "|" + suff] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        // if this combination present then it will return the index otherwise -1
        return pref_suff_index[prefix + "|" + suffix] - 1;
    }
};