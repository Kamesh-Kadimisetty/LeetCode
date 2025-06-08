class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        vector<int>visited(n,0);
        queue<pair<int,int>>qu;
        qu.push({id,0});
        visited[id]=1;
        unordered_map<string,int>mpp;
        while(!qu.empty()){
            int node=qu.front().first;
            int lvl=qu.front().second;
            qu.pop();
            if(lvl==level){
                for(auto it:watchedVideos[node]) mpp[it]++;
            }
            for(auto it:friends[node]){
                if(!visited[it] && lvl+1<=level){
                    qu.push({it,lvl+1});
                    visited[it]=1;
                } 
            }
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,
                            greater<pair<int,string>>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        vector<string>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};