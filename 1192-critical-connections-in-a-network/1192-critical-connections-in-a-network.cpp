class Solution {
public:
    int time;
    vector<int> dt, low;

    void DFS(int u, int parent, vector<bool>&visited, vector<vector<int>>&graph, vector<vector<int>>&ans){
        visited[u] = true;
        dt[u] = low[u] = ++time;

        for(int i = 0 ; i<graph[u].size() ; i++){
            int v = graph[u][i];
            if(!visited[v]){
                DFS(v, u, visited, graph, ans);
                low[u] = min(low[u] , low[v]);
                if(low[v] > dt[u]){
                    ans.push_back({u,v});
                }
            }else{
                if(v != parent){
                    low[u] = min(low[u] , dt[v]);
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // creating adjacency list
        vector<vector<int>>graph(n);
        for(int i = 0 ; i<connections.size() ; i++){
            int u = connections[i][0] , v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        time = 0;
        dt.resize(n);
        low.resize(n);
        vector<bool>visited(n, false);
        vector<vector<int>>ans;
        for(int i = 0 ; i<n ; i++){
            if(!visited[i]){
                DFS(i, -1, visited, graph, ans);
            }
        }
        return ans;
    }
};