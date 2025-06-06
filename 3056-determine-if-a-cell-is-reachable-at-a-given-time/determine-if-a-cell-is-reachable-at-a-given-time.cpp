class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1) return false;
        int dist=max(abs(sx-fx),abs(sy-fy));
        return dist<=t;
    }
};