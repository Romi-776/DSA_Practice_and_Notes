// Calculate Amount Paid in Taxes

class Solution
{
public:
    // T.C = O(N), S.C = O(1)
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double ans;
        
        // if bracket is in the range of tax or otherwise
        if (brackets[0][0] <= income)
            ans = (double(brackets[0][0]) * brackets[0][1]) / 100, income -= brackets[0][0];
        else
            ans = (double(income) * brackets[0][1]) / 100, income = 0;

        // traversing all the brackets until we have some income to be taxed on
        for (int i = 1; i < brackets.size(); i++)
        {
            if (income == 0)
                break;
            double temp;
            int diff = brackets[i][0] - brackets[i - 1][0];
            
            // if bracket is in the range of tax or otherwise
            if (income >= diff)
                temp = (double(diff) * brackets[i][1]) / 100, income -= diff;
            else
                temp = (double(income) * brackets[i][1]) / 100, income = 0;
            ans += temp;
        }
        return ans;
    }
};