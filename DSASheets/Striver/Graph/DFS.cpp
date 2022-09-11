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
// for G, visited, and recursive stack
void dfs_recursive(int from)
{
    visited[from] = true;

    // iterating each possible node
    for (int to = 1; to <= n; to++)
    {
        // checking that the current to node has an edge between from node and
        // is not visited
        if (G[from][to] and !visited[to])
        {
            span_back[from][to] = span_back[to][from] = 1;
            dfs_recursive(to);
        }
    }
}

// T.C = O(V+E), S.C = O(V+E) + O(V) + O(V)
// for Adj, visited, and stack
void dfs_iterative(int from)
{
    stack<int> st;
    st.push(from);

    while (st.size())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            cout << node << " ";
            visited[node] = true;
            for (int adj : Adj[node])
            {
                if (!visited[adj])
                {
                    st.push(adj);
                }
            }
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
            dfs_iterative(node);
        }
    }
}