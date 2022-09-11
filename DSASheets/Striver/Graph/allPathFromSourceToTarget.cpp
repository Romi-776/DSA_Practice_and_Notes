/*
DFS SOLUTION:
Using Backtracking, starting from the source and trying to go to each of the adjacent nodes
for every curr node until I didn't reached the dest or a node from where I can't go further.
*/
class Solution {
    vector<vector<int>> ans;
    void dfs(int sc, vector<vector<int>>& g, vector<int>& path) {
        int dest = g.size() - 1;
        path.push_back(sc);
        if (sc == dest)
            ans.push_back(path);
        else
            for (auto i: g[sc]) 
                dfs(i, g, path);
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<int> path;
        dfs(0, g, path);
        return ans;
    }
};