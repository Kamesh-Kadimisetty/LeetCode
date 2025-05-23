class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int n=rowCosts.size(),m=colCosts.size(),cost=0;
        int x=startPos[0],y=startPos[1];
        int p=homePos[0],q=homePos[1];
        while(x!=p){
            if(x<p) x++;
            else  x--;
            cost+=rowCosts[x];
        }
        while(y!=q){
            if(y<q) y++;
            else y--;
            cost+=colCosts[y];
        }
        return cost;
    }
};