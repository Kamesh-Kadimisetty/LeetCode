class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        int n=hcuts.size(),m=vcuts.size(),MOD=1e9+7;
        sort(hcuts.begin(),hcuts.end());
        sort(vcuts.begin(),vcuts.end());
        hcuts.push_back(h);
        vcuts.push_back(w);
        int maxh=hcuts[0],maxv=vcuts[0];
        for(int i=0;i<n;i++){
            maxh=max(maxh,hcuts[i+1]-hcuts[i]);
        }
        for(int i=0;i<m;i++){
            maxv=max(maxv,vcuts[i+1]-vcuts[i]);
        }
        return (1LL*maxh*maxv)%MOD;
    }
};