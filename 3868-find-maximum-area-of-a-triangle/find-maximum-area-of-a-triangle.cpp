class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<int,set<int>>xaxis,yaxis;
        set<int>allx,ally;
        for(auto it:coords){
            xaxis[it[0]].insert(it[1]);
            yaxis[it[1]].insert(it[0]);
            allx.insert(it[0]);
            ally.insert(it[1]);
        }
        long long maxarea=-1;
        for(auto it:xaxis){
            if(it.second.size()>1){
                int base=*it.second.rbegin()-*it.second.begin();
                int minx=*allx.begin(),maxx=*allx.rbegin();
                if(maxx!=it.first) maxarea=max(maxarea,1LL*base*abs(maxx-it.first));
                if(minx!=it.first) maxarea=max(maxarea,1LL*base*abs(minx-it.first));
            }
        }
        for(auto it:yaxis){
            if(it.second.size()>1){
                int base=*it.second.rbegin()-*it.second.begin();
                int miny=*ally.begin(),maxy=*ally.rbegin();
                if(maxy!=it.first) maxarea=max(maxarea,1LL*base*abs(maxy-it.first));
                if(miny!=it.first) maxarea=max(maxarea,1LL*base*abs(miny-it.first));
            }
        }
        return maxarea;
    }
};