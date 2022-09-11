/*
INTUITION:
Using BFS, try to reach the node from src to dest and keep track of the directions and nodes that you
visited in order to reach the destination node. If you somehow reached the destination node from source
, then create the path using the data stored of dirs and nodes.
T.C = O(N*M), S.C = O(N*M)
*/

#include <bits/stdc++.h>  
using namespace std;
#define endl "\n"

map<pair<int, int>, pair<pair<int, int>, char>> find_path(pair<int, int>& src, string maze[], int n, int m) {
    vector<vector<bool>> vis(n, vector<bool>(m)); 
    map<pair<int, int>, pair<pair<int, int>, char>> prev; // for storing the parent node, i.e., from which node we came
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    string way = "RLUD";
    bool found_dest = false;

    queue<pair<int, int>> q;
    q.push(src);
    vis[src.first][src.second] = 1;

    while (q.size()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int rr = r + dirs[i][0], cc = c + dirs[i][1];
            if (rr >= 0 and rr < n and cc >= 0 and cc < m and !vis[rr][cc] and (maze[rr][cc] == '.' or maze[rr][cc] == 'B')) {
                vis[rr][cc] = 1, q.push({rr, cc});
                // from where we came and in which direction we traveled
                prev[{rr,cc}] = {{r, c}, way[i]};
                if (maze[rr][cc] == 'B') {
                    found_dest = 1;
                    break;
                }
            }
        }
        if (found_dest) break;
    }
    if (!found_dest) // we couldn't find the dest so clearing the map in order to not make any path
        prev.clear();
    return prev;
}

string generate_path(map<pair<int, int>, pair<pair<int, int>, char>>& prev, pair<int, int>& src, pair<int, int>&  dest) {
    string path = "";
    // if we have reached our destination then only we can make a path
    if (prev.size()) {
        for (auto i = dest; i != src; i = prev[i].first) {
            path += prev[i].second;
        }
        reverse(path.begin(), path.end());
    }
    return path;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // getting input and finding the starting point/src
    string maze[n];
    pair<int, int> src, dest;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'A') src.first = i, src.second= j;
            else if (c == 'B') dest.first = i, dest.second = j;
            maze[i] += c;
        }
    }
    // trying to reach the destination
    map<pair<int, int>, pair<pair<int, int>, char>> prev = find_path(src, maze, n, m);

    // if we somehow reached the destination, then trying to generate the path
    string path = generate_path(prev, src, dest);

    // if we got a path to the destination
    if (path.size()) cout << "YES\n" << path.size() << endl << path;
    else cout << "NO";
}

int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--) {
       solve();
       cout << endl;
    }
    return 0;
}