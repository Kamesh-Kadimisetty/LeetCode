class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size(),total=0;
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
            last[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++){
            if(first[i]==-1){
                continue;
            }
            set<char>st;
            for(int k=first[i]+1;k<last[i];k++){
                st.insert(s[k]);
            }
            total+=st.size();
        }
        return total;
    }
};