// Maximum Points You Can Obtain from Cards - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// T.C = O(N), S.C = O(1)
// Using Sliding Window
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int maxScore = 0, total = 0;

        // Firstly, taking all the k elements from the start
        // and finding maxScore at each position
        for (int i = 0; i < k; i++)
            total += cardPoints[i], maxScore = max(maxScore, total);

        int j = cardPoints.size() - 1;

        // now, lets take some elements from end and rest of the elements from start
        // and finding maxScore at each position
        for (int i = k - 1; i >= 0; i--, j--)
        {
            total -= cardPoints[i];
            total += cardPoints[j];
            maxScore = max(maxScore, total);
        }

        return maxScore;
    }
};