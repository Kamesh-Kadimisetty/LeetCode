class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        int maxday=0;
        for(auto it:events){
            maxday=max(maxday,it[1]);
        }
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int j=0,cnt=0;
        for(int i=1;i<=maxday;i++){
            while(j<n && events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};