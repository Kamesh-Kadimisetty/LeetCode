class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
         int n=moveTime.size(),m=moveTime[0].size();
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>pq; //{time,cnt,row,col}
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({{0,1},{0,0}});
        distance[0][0]=0;
        while(!pq.empty()){
            int time=pq.top().first.first;
            int cnt=pq.top().first.second;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(auto [dr,dc]:directions){
                int nr=row+dr;
                int nc=col+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int t=moveTime[nr][nc];
                    int newtime=0;
                    newtime=max(t+cnt,time+cnt);
                    if(newtime<distance[nr][nc]){
                        distance[nr][nc]=newtime;
                        int x=(cnt==1)?2:1;
                        pq.push({{newtime,x},{nr,nc}});
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};