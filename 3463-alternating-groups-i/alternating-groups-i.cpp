class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size(),cnt=0;
        if(colors[n-1]==colors[1] && colors[1]!=colors[0]) cnt++;
        for(int i=1;i<n-1;i++){
            if(colors[i-1]==colors[i+1] && colors[i-1]!=colors[i])cnt++;
        }
        if(colors[n-2]==colors[0] && colors[0]!=colors[n-1]) cnt++;
        return cnt;
    }
};