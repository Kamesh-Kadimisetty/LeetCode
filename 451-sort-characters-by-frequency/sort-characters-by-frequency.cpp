class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        vector<pair<int,char>>sortedchars;
        for(auto it:mpp){
            sortedchars.push_back({it.second,it.first});
        }
        sort(sortedchars.rbegin(),sortedchars.rend());
        string ans="";
        for(auto it:sortedchars){
            for(int i=0;i<it.first;i++){
                ans+=it.second;
            }
        }
        return ans;
    }
};