class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD=1e9+7;
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>distance(n,LLONG_MAX);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;//dist node
        pq.push({0,0});
        distance[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            long long dist=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long adjnode=it.first;
                long long wt=it.second;
                if(wt+dist<distance[adjnode]){
                    distance[adjnode]=dist+wt;
                    ways[adjnode]=ways[node];
                    pq.push({dist+wt,adjnode});
                }
                else if(wt+dist==distance[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};