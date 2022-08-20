// https://leetcode.com/problems/valid-palindrome/

// Sol - 1 T.C = O(N), S.C = O(N)
bool isPalindrome(string s)
{
    string p;
    for (char c : s)
    {
        if ((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
            p += c;
        else if (c >= 'A' and c <= 'Z')
            p += c + ('a' - 'A');
    }

    int n = p.size();
    for (int i = 0; i < n / 2; i++)
        if (p[i] != p[n - i - 1])
            return false;
    return true;
}

// Sol - 2 T.C = O(N), S.C = O(1)
bool isPalindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        while (!isalnum(s[i]) and i < j)
            i++;
        while (!isalnum(s[j]) and i < j)
            j--;
        if (tolower(s[i++]) != tolower(s[j--]))
            return false;
    }
    return true;
}