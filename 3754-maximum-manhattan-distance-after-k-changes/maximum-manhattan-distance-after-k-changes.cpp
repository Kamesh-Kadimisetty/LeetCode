class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size(),maxdist=INT_MIN,i=0;
        unordered_map<char,int>mpp;
        for(auto it:s){
            i++;
            mpp[it]++;
            int dist=abs(mpp['N']-mpp['S'])+abs(mpp['E']-mpp['W']);
            maxdist=max(maxdist,dist+min(2*k,i-dist));
        } 
        return maxdist;
    }
};