class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>totaltime(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//dist node
        pq.push({0,k});
        totaltime[k]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(it.second+dist<totaltime[it.first]){
                    totaltime[it.first]=dist+it.second;
                    pq.push({dist+it.second,it.first});
                }
            }
        }
        int maxtime=*max_element(totaltime.begin()+1,totaltime.end());
        return maxtime==INT_MAX?-1:maxtime;
    }
};