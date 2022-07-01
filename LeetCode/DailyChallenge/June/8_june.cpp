// Remove Palindromic Subsequences - https://leetcode.com/problems/remove-palindromic-subsequences/


class Solution {
public:
    // checking that a string is palindrome or not
    // T.C = O(N), S.C = O(1)
    bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    
    // solution to the problem
    // T.C = O(N), S.C = O(N)
    int removePalindromeSub(string s) {
        unordered_set<char> us;
        if (isPalindrome(s))
            return 1;
        else {
            for (char i : s)
                us.insert(i);
            return us.size();
        }
    }
};