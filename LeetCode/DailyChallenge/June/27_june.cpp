// Partitioning Into Minimum Number Of Deci-Binary Numbers - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

// T.C = O(N), S.C = O(1), here N = length of string n
/*
INTUITION
    if the input was only one digit. Then you need to add up as many ones as the value of this digit.
    If the input has multiple digits, then you can solve for each digit independently, and merge the
    answers to form numbers that add up to that input. Thus the answer is equal to the max digit.
*/
class Solution
{
public:
    int minPartitions(string n)
    {
        int max_digit = 0;
        for (char i : n)
        {
            int digit = i - '0';
            max_digit = max(max_digit, digit);
        }
        return max_digit;
    }
};