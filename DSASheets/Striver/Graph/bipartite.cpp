// Is Graph Bipartite? - https://leetcode.com/problems/is-graph-bipartite/

// T.C = O(V+E), S.C = O(V+E) + O(V) + O(V)
/*
INTUITION
BFS TRAVERSAL
*/
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // total no. of vertices
        int v = graph.size();

        // for coloring each vertex
        vector<int> cols(v, -1);

        // iterating all the vertices
        for (int i = 0; i < v; i++)
        {
            // current vertex not colored
            if (cols[i] == -1)
            {
                // Using BFS traversal color this component
                queue<int> q;
                q.push(i), cols[i] = 0;

                while (q.size())
                {
                    int node = q.front();
                    int c = cols[node];
                    q.pop();

                    for (int adj : graph[node])
                    {
                        if (cols[adj] == -1)
                            q.push(adj), cols[adj] = !c;
                        else if (cols[adj] == c) // at any point two adjacent nodes have same color
                            return false;        // then the graph isn't bipartite
                    }
                }
            }
        }
        return true;
    }
};

// T.C = O(V+E), S.C = O(V+E) + O(V) + O(V)
/*
INTUITION
DFS TRAVERSAL
*/
class Solution
{

    bool dfs(vector<vector<int>> &graph, vector<int> &cols, int source)
    {
        // current vertex isn't colored then color that vertex
        if (cols[source] == -1)
            cols[source] = 0;

        // adjacent vertices of the current vertex
        for (int adj : graph[source])
        {
            if (cols[adj] == -1)
            {
                cols[adj] = !cols[source];  // coloring the current vertex
                if (!dfs(graph, cols, adj)) // graph is proved already not bipartite
                    return false;
            }
            else if (cols[adj] == cols[source]) // current vertex and adjacent have same color
            {
                return false; // therefore not bipartite
            }
        }
        return true; // otherwise bipartite
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        bool ans = true;
        int v = graph.size();
        vector<int> cols(v, -1);

        for (int i = 0; i < v; i++)
        {
            if (cols[i] == -1)
            {
                ans = dfs(graph, cols, i);
                if (!ans)
                    break;
            }
        }
        return ans;
    }
};