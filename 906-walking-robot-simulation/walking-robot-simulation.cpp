class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string,int>mp;
        for(auto it :obstacles){
            string key=to_string(it[0])+"+"+to_string(it[1]);
            mp[key]++;
        }
        vector<vector<int>> direc={{-1,0},{0,1},{1,0},{0,-1}};
        // according to order W N E S
        int dir=1;//north
         // 0: west, 1: north, 2: east, 3: south
         int x=0,y=0;
         int mxdist=0;
         for(auto it:commands){
            if(it==-1){
                // move right
                dir=(dir+1)%4;
            }
            else if(it==-2){
                 // move left
                dir=(dir+3)%4;
            }
            else{
                int k=it;
                for(int i=1;i<=k;i++){
                    int newx=x+direc[dir][0];
                    int newy=y+direc[dir][1];
                    string key=to_string(newx)+"+"+to_string(newy);
                    if(mp.find(key)!=mp.end()){
                        // obstacle has been found so don't go there
                        break;
                    }
                    x=newx,y=newy;
                    mxdist=max(mxdist,x*x+y*y);
                }
            }
         }
         return mxdist;
    }
};