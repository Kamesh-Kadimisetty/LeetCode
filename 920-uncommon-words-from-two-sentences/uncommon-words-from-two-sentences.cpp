class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string nw=s1+" "+s2,str="";
        map<string,int>mp;
        vector<string> ans;
        for(auto c : nw){
            if(c==' '){
                mp[str]++;
                str="";
            }
            else{
                str+=c;
            }
        }
        mp[str]++;
        for(auto it:mp){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};