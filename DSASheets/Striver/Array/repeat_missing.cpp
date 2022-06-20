// Find Missing And Repeating - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#

// SOL2 - Using sum of N and sum square of N natural numbers - T.C = O(N), S.C = O(1)
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        long long sumOfNNumbers = (n * (n + 1)) / 2;
        long long sumOfSqrOfNNumbers = (n * (n + 1) * (2 * n + 1)) / 6;

        for (int i = 0; i < n; i++)
        {
            sumOfNNumbers -= arr[i];
            long long sq = (long long)arr[i] * (long long)arr[i];
            sumOfSqrOfNNumbers -= sq;
        }

        /*
            Here, x = missing number and y is the repeating number
            Now, sumOfNumbers will store x - y = z
            and, sumOfSqrOfNNumbers will store x^2 - y^2 = z'
            so,
            we can get x by (x - y + (x^2 - y^2)/(x - y)) / 2
            and y = x - z
        */

        long long missingNum = (sumOfNNumbers + sumOfSqrOfNNumbers / sumOfNNumbers) / 2;
        long long repeatingNum = missingNum - sumOfNNumbers;

        int *ans = new int[2];
        ans[0] = repeatingNum, ans[1] = missingNum;
        return ans;
    }
};



// SOL1 - USING EXTRA ARRAY OF N SIZE - T.C. = O(N), S.C = O(N)
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2];

        // Freq array of elements
        int count[n + 1] = {0};
        for (int i = 0; i < n; i++)
            count[arr[i]]++;

        // finding the missing and repeating elements
        for (int i = 1; i <= n; i++)
        {
            if (count[i] > 1)
                ans[0] = i;
            else if (count[i] == 0)
                ans[1] = i;
        }
        return ans;
    }
};
