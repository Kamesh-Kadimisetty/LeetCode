class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int total=0,i=0,j=0;
        int n=g.size(),m=s.size();
        while(i<n && j<m){
            if(g[i]<=s[j]){
                total++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return total;
    }
};