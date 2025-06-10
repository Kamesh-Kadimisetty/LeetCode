class Solution {
public:
    int maxDifference(string s) {
        int n=s.size();
        vector<int>hash(26,0);
        for(int i=0;i<n;i++) hash[s[i]-'a']++;
        int mineven=n,maxodd=0;
        for(int i=0;i<26;i++){
            if(hash[i]%2==0 && hash[i]>0) mineven=min(mineven,hash[i]);
            if(hash[i]%2==1) maxodd=max(maxodd,hash[i]);
        }
        return maxodd-mineven;
    }
};