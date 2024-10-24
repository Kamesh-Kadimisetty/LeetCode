class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(auto s:strs){
            string t=s;
            sort(t.begin(),t.end());
            mpp[t].push_back(s);
        }
        vector<vector<string>>anagrams;
        for(auto i:mpp){
            anagrams.push_back(i.second);
        }
        return anagrams;
    }
};