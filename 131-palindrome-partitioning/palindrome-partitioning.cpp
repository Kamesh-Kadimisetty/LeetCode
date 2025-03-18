class Solution{
public:
    bool ispalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    void func(int ind,string s,vector<string>&ans,vector<vector<string>>&result){
        if(ind==s.size()){
            result.push_back(ans);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                ans.push_back(s.substr(ind,i-ind+1));
                func(i+1,s,ans,result);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        vector<vector<string>>result;
        vector<string>ans;
        func(0,s,ans,result);
        return result;
    }
};