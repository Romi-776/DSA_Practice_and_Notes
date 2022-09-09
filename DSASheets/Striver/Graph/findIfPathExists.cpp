/*
BFS SOLUTION:
Created graph/adj_list using edges and then using bfs tried to go to the dest. vertex
and if reached then return true otherwise false.
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == end)
                return 1; 
            for(auto &node : graph[curr]){
                if(!visited[node]){
                    visited[node] = 1; 
                    q.push(node);
                }
            }
        }
        
        return false;
    }
};


/*
DFS SOLUTION: 
Created graph/adj_list using edges and then using dfs tried to go to the dest. vertex
and if reached then return true otherwise false.
*/
class Solution {
    vector<vector<int>> create_adj_list(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            int fro = i[0], to = i[1];
            adj[fro].push_back(to);
            adj[to].push_back(fro);
        }
        return adj;       
    }
    
    bool path_exists(int source, int destination, vector<vector<int>>& adj, vector<bool>& vis) {
        if (source != destination and !vis[source]) {
            vis[source] = 1;
            bool found = false;
            for (auto i : adj[source]) {
                if (!vis[i] and !found)
                    found |= path_exists(i, destination, adj, vis);
                if (found) return 1;
            }
        } 
        return source == destination;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj = create_adj_list(n, edges);
        vector<bool> vis(n); 
        return path_exists(source, destination, adj, vis);
    }
};