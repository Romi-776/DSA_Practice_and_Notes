// Smallest distinct window - https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// T.C. = O(N), S.C = (M), n = length of str, m = no. of unique chars in str
class Solution
{
public:
    int findSubString(string str)
    {
        // for counting no. of unique chars in str
        unordered_set<char> s;
        for (char c : str)
            s.insert(c);
        int count = s.size();

        // for counting no. of unique chars in current window
        unordered_map<char, int> mp;
        int n = str.length();
        int i = 0, j = 0, ans = n;

        // iterating through windows
        while (j < n)
        {
            // adding current char into window
            mp[str[j]]++;

            // window have all the unique chars of str
            while (i <= j and mp.size() == count)
            {
                // minimizing the window size and possible answer
                ans = min(ans, j - i + 1);
                mp[str[i]]--;
                if (!mp[str[i]])
                    mp.erase(str[i]);
                i++;
            }
            j++;
        }

        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
} // } Driver Code Ends