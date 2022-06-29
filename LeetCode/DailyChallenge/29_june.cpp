// T.C = O(N^2), S.C = O(1)
/*
INTUITION
Pick out tallest group of people and sort them in a sub-array (S).
Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
For 2nd tallest group (and the rest), insert each one of them into (S) by k value.
*/
class Solution
{
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0] or (a[0] == b[0] and a[1] <= b[1]);
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // sorting the people firstly in descending order of their heights
        // and after that in ascending order of their k values
        sort(people.begin(), people.end(), comp);

        // inserting people into the queue by their k values
        vector<vector<int>> ans;
        for (auto i : people)
            ans.insert(ans.begin() + i[1], i);
        return ans;
    }
};