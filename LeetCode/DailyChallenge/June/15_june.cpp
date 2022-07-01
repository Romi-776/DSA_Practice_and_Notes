// Longest String Chain - https://leetcode.com/problems/longest-string-chain/

// T.C = O(n*log(n) + n*l*l), S.C = O(n*s)
// here n = no. of words, l = word_len, s = prev_len 
class Solution
{
    static bool comp(string s1, string s2)
    {
        return s1.length() < s2.length();
    }

public:
    // Using DP in order to store the max predecessors of every word that occurred till now
    int longestStrChain(vector<string> &words)
    {
        // sorting the words acc. to increasing length in order to check for each word the no. of predecessors that it can have
        sort(words.begin(), words.end(), comp);
        int ans = 1;
        // stores the count of max predecessors (chain) of a word that found till now
        unordered_map<string, int> pred_till_now;

        for (string word : words)
        {
            // intially the current word is the max length
            pred_till_now[word] = 1;

            for (int i = 0; i < word.length(); i++)
            {
                // checking all the predecessors that a word can have
                string prev_pred = word.substr(0, i) + word.substr(i + 1);

                // suppose the predecessor found in our storage
                if (pred_till_now.find(prev_pred) != pred_till_now.end())
                {
                    // now the curr word's max predecessors will be max of the no. of predecessors the curr word have till now
                    // or the no. of predecessors the prev predecessor have along with the curr word
                    pred_till_now[word] = max(pred_till_now[word], pred_till_now[prev_pred] + 1);

                    // ans will store the max of the no. of words that will last with max predecessors (longest chain)
                    ans = max(ans, pred_till_now[word]);
                }
            }
        }
        return ans;
    }
};