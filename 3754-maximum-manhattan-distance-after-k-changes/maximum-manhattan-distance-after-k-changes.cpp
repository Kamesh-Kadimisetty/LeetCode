class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size(),maxdist=INT_MIN;
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            int dist=abs(mpp['N']-mpp['S'])+abs(mpp['E']-mpp['W']);
            maxdist=max(maxdist,dist+min(2*k,i+1-dist));
        } 
        return maxdist;
    }
};