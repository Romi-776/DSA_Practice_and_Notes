//  Count Unreachable Pairs of Nodes in an Undirected Graph

// T.C = O(V+E), S.C = O(N)
class Solution
{
    // helper function to find connected components
    void helper(int v, vector<vector<int>> &adj, vector<int> &component, vector<bool> &visited)
    {
        component.push_back(v), visited[v] = true;

        auto start = adj[v].begin(), end = adj[v].end();
        while (start != end)
        {
            auto curr = *start;
            if (visited[curr] == false)
                helper(curr, adj, component, visited);
            start++;
        }
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n), components;
        // creating adjacency list (for later use)
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // to keep track that a node is visited or not
        vector<bool> visited(n, false);

        // finding the connected components
        for (int i = 0; i < n; i++)
        {
            vector<int> component;
            if (!visited[i])
            {
                helper(i, adj, component, visited);
            }
            components.push_back(component);
        }

        long long ans = 0;

        // each connected component can make pair with other remaining nodes that
        // aren't in the connected component and storing the count into our answer
        for (auto i : components)
        {
            long long sz = i.size();
            n -= i.size();
            long long a = n;
            ans += a * sz;
        }

        return ans;
    }
};