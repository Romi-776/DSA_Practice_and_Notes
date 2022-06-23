// Valid Parentheses - https://leetcode.com/problems/valid-parentheses/

// T.C = O(N), S.C = O(N)
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        // iterating through all the brackets
        for (char i : s)
        {
            // if its a opening bracket, then push it into stack
            if (i == '(' or i == '[' or i == '{')
                st.push(i);
            else if (!st.size()) // if its a closing bracket, and we don't have anything in stack
                return false;    // then its not balanced
            else
            {
                // so we have an opening and closing bracket which can be of same type
                char closing, t = st.top();
                if (t == '(')
                    closing = ')';
                else if (t == '{')
                    closing = '}';
                else
                    closing = ']';

                // if they aren't of same type then they aren't balanced
                if (closing != i)
                    return false;

                // otherwise pop off the opening bracket as we found a balanced brackets pair
                st.pop();
            }
        }

        // if we still have some opening brackets left then also its unbalanced
        if (st.size())
            return false;

        // after all these conditions it should definitely be balanced
        return true;
    }
};