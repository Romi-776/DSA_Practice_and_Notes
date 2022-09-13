/*
INTUITION:
The idea is to sort the intervals by their starting points. Then, we take the first interval and compare 
its end with the next intervals starts. As long as they overlap, we update the end to be the max end of the 
overlapping intervals. Once we find a non overlapping interval, we can add the previous "extended" interval 
and start over.

T.C = O(Nlog(N)), S.C = O(N)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // mainly sorting the intervals acc. to their first val
        // so that we can process them in ascending order
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        // initially we have only 1 interval
        ans.push_back(intervals[0]);
        
        // now checking for overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            // if the prev end is after the starting of the curr interval
            // then its overlapping otherwise its some other interval
            int n = ans.size() - 1;
            int prevEnd = ans[n][1];
            if (prevEnd >= intervals[i][0]) 
                ans[n][1] = max(intervals[i][1], prevEnd);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};