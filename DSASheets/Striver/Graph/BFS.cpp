#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define endl "\n"

const int MAX = 1e3 + 4; // max no. of vertices
int n, m;                // no. of vertices and edges   

int G[MAX][MAX]; // graph using Adj matrix

vector<int> Adj[MAX]; // graph using Adj list

vector<bool> visited(MAX); // checks that a node is visited or not

// T.C = O(V+E), S.C = O(V+E) + O(V) + O(V)
// for G, visited, and q
void bfs(int from)
{
    queue<int> q;
    q.push(from), visited[from] = true;

    while (q.size())
    {
        int from = q.front();
        q.pop();
        cout << from << " ";
        for (int to = 1; to <= m; to++)
        {
            if (G[from][to] and !visited[to])
            {
                q.push(to), visited[to] = true;
            }
        }
    }
}

// T.C = O(V+E), S.C = O(V+E) + O(V) + O(V)
// for Adj, visited, and q
void bfs_using_adj(int from)
{
    queue<int> q;
    q.push(from), visited[from] = true;

    while (q.size())
    {
        int from = q.front();
        q.pop();
        cout << from << " ";
        for (int to : Adj[from])
        {
            if (!visited[to])
                q.push(to), visited[to] = true;
        }
    }
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
            bfs_using_adj(node);
        }
    }
}