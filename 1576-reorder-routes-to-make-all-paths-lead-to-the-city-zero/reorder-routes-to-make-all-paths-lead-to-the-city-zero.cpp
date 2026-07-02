class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>>& adj, vector<bool>& visited, int& count) {
        visited[node] = true;
        
        for (const auto& edge : adj[node]) {
            int neighbor = edge.first;
            int cost = edge.second;
            
            if (!visited[neighbor]) {
                count += cost; 
                dfs(neighbor, adj, visited, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (const auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back({v, 1}); 
            adj[v].push_back({u, 0}); 
        }
        
        int count = 0;
        vector<bool> visited(n, false);
        dfs(0, adj, visited, count);
        return count;
    }
};