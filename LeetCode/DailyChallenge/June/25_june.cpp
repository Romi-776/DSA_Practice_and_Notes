// Non-decreasing Array - https://leetcode.com/problems/non-decreasing-array/

// T.C = O(N), S.C = O(1)
class Solution
{
public:
    bool checkPossibility(vector<int> &arr)
    {
        int n = arr.size();
        // flag tells us that we used the operation or not
        bool changed = false;

        // starting from first to 2nd last element
        for (int i = 0; i < n - 1; i++)
        {
            // we don't need to do anything
            if (arr[i] <= arr[i + 1])
                continue;
            // we have used operation before then not possible
            if (changed)
                return false;

            // changing value effectively
            if (!i or arr[i + 1] >= arr[i - 1])
                arr[i] = arr[i + 1];
            else
                arr[i + 1] = arr[i];
            // operation is used now
            changed = true;
        }
        return true;
    }
};