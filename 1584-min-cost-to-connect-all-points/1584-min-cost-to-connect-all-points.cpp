class Solution {
public:
    int getdis(int p1 , int p2 , vector<vector<int>>&points){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<bool>visited(n,false);
        int mincost = 0;

        pq.push({0,0}); // weight , element
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node]) continue;
            visited[node] = true;

            mincost += weight;

            for(int i = 0 ; i<n ; i++){

                if(!visited[i]){
                    int distance = getdis(node, i, points);
                    pq.push({distance,i});
                } 
            }
        }

        return mincost;
    }
};