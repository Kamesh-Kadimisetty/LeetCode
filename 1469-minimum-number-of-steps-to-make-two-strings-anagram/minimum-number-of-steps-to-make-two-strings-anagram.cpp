class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq1(26,0),freq2(26,0);
        for(auto it:s) freq1[it-'a']++;
        for(auto it:t) freq2[it-'a']++;
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq1[i]>freq2[i]) ans+=freq1[i]-freq2[i];
        }
        return ans;
    }
};