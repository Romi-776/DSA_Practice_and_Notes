/*
INTUITION:
Creating the first and second row's if required and then to build each row, using previous row.
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            vector<int> v(i);
            v[0] = 1;
            if (i) {
                v[i-1] = 1;
                for (int j = 1; j < i - 1; j++)
                    v[j] = ans[i - 2][j - 1] + ans[i - 2][j];
            } 
            ans.emplace_back(v);
        }
        return ans;
    }
};