class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i = 0 ; i<flights.size() ; i++){
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int>mincost(n, INT_MAX);
        mincost[src] = 0;

        queue<pair<int,int>>q;
        q.push({src, 0});
        
        int stops = 0;

        while(!q.empty() && stops<=k){
            int size = q.size();

            for(int i = 0 ; i<size ; i++){
                int currnode = q.front().first , currcost = q.front().second;
                q.pop();
                
                for(auto p : graph[currnode]){
                    int nextnode = p.first ,nextcost = p.second;

                    if(currcost + nextcost < mincost[nextnode]){
                        mincost[nextnode] = currcost + nextcost;
                        q.push({nextnode, mincost[nextnode]});
                    }
                }
            }

            stops++;
        }

        if(mincost[dst] == INT_MAX) return -1;
        return mincost[dst];
    }
};