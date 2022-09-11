#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define endl "\n"

const int MAX = 1e3 + 4; // max no. of vertices
int n, m;                // no. of vertices and edges   

vector<int> Adj[MAX]; // graph using Adj list

vector<bool> visited(MAX); // checks that a node is visited or not

bool CycleCheck_usingBFS(int from)
{
    queue<int> q;
    q.push(from);
    visited[from] = true;

    while (q.size())
    {
        int fro = q.front();
        q.pop();
        int vis_count = 0;
        for (int i : Adj[fro])
        {
            if (!visited[i])
                q.push(i), visited[i] = true;
            else
                vis_count++;
        }

        if (vis_count >= 2)
            return true;
    }
    return false;
}

bool CycleCheck_usingDFS(int from)
{
    visited[from] = true;
    int vis_count = 0;
    bool ans = false;
    for (int to : Adj[from])
    {
        if (!visited[to])
            ans = ans or CycleCheck_usingDFS(to);
        else if (!ans)
            vis_count++;
        else
            break;
    }
    if (vis_count >= 2)
        ans = true;
    return ans;
}

int32_t main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int fro, to;
        cin >> fro >> to;
        Adj[fro].push_back(to), Adj[to].push_back(fro);
    }

    // traversing through all the nodes/vertices because
    // a graph can have multiple components that can be
    // disjoint
    for (int node = 1; node <= n; node++)
    {
        if (!visited[node])
        {
            CycleCheck_usingDFS(node);
        }
    }
}