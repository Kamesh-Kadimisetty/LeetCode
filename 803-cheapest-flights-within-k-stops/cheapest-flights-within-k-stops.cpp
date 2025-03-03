class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>qu; //steps,node,dist
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        qu.push({0,{src,0}});
        while(!qu.empty()){
            int steps=qu.front().first;
            int node=qu.front().second.first;
            int dist=qu.front().second.second;
            qu.pop();
            if(steps>k) break;
            for(auto it:adj[node]){
                if(dist+it.second<distance[it.first]){
                    distance[it.first]=dist+it.second;
                    qu.push({steps+1,{it.first,dist+it.second}});
                }
            }
        }
        return distance[dst]==INT_MAX?-1:distance[dst];
    }
};