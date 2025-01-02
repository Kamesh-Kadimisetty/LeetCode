class Solution {
public:
    bool isvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' ||c=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>prefixsum(n);
        prefixsum[0]=isvowel(words[0].front())&&isvowel(words[0].back());
        for(int i=1;i<n;i++){
            int add=0;
            if(isvowel(words[i].front())&& isvowel(words[i].back())){
                add=1;
            }
            prefixsum[i]=prefixsum[i-1]+add;
        }
        vector<int>ans;
        for(auto it:queries){
            int left=it[0];
            int right=it[1];
            if(left>0){
                ans.push_back(prefixsum[right]-prefixsum[left-1]);
            }
            else{
                ans.push_back(prefixsum[right]);
            }
        }
        return ans;
    }
};