// Short Encoding of Words - https://leetcode.com/problems/short-encoding-of-words/

// T.C = (Nlog(N) + N*M)
// here N = no. of words, M = Encoded string length
class Solution
{
    static bool comp(string s1, string s2)
    {
        return s1.length() > s2.length();
    }

public:
    int minimumLengthEncoding(vector<string> &words)
    {
        int ans = 0;
        // sorting the words in descending order of length
        sort(words.begin(), words.end(), comp);

        // stores the encoded string
        string encoding = "";

        // going through each word
        for (string word : words)
        {
            // checking that the current word is already present or not in our encoded string
            if (encoding.find(word + "#") == string::npos)
                encoding += word + "#"; // not present so adding it
        }
        ans = encoding.length(); // answer will be the length of encoded string generated
        return ans;
    }
};