// Greatest English Letter in Upper and Lower Case

class Solution
{
public:
    // T.C = O(N), S.C = O(1), constant S.C because we can have max 26 chars in both upper and lower case
    string greatestLetter(string s)
    {
        // stores the freq of lower and upper case letters
        map<char, int> lower, upper;
        string ans = "0";

        // iterating through all the letters and getting their frequency
        for (char i : s)
        {
            if (islower(i))
                lower[i]++;
            else
                upper[i]++;
        }

        // letter present in upper and lowercase then update the answer according 
        // their alphabetical order
        for (auto i : lower)
            if (upper[toupper(i.first)])
                ans = toupper(i.first);

        // answer changed then we have an answer otherwise not
        return ans == "0" ? "" : ans;
    }
};