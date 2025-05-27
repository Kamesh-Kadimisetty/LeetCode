class Solution {
public:
    void func(string ans,int cnt,vector<string>& result,int n){
        if(ans.size()==2*n && cnt==0){
            result.push_back(ans);
            return;
        }
        if(cnt>n || ans.size()==2*n) return;
        if(cnt>=0 && cnt<n){
            func(ans+'(',cnt+1,result,n);
        }
        if(cnt>0){
            func(ans+')',cnt-1,result,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        func("",0,result,n);  
        return result;  
    }
};