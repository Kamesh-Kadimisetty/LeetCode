class Solution {
public:
    bool isvalid(string curr,string s,int k){
        int j=0;
        for(auto it:s){
            if(curr[j]==it){
                j++;
                if(j==curr.size()){
                    k--;
                    j=0;
                    if(k==0) return true;
                }
            }
        }
        return false;
    }
    // void solve(string curr,string ans,string s,int k){
    //     if(curr.size()>7) return;
    //     if(isvalid(curr,s,k)){
    //         if(curr.size()==result.size()) result=max(result,curr);
    //         if(curr.size()>result.size()) result=curr;
    //     }
    //     // solve(curr,ind+1,ans,s,k);
    //     // solve(curr+ans[ind],ind+1,ans,s,k);
    //     for(auto ch:ans){
    //         xsolve(curr+ch,ans,s,k);
    //     }
    // }
    string longestSubsequenceRepeatedK(string s, int k) {
        string result;
        queue<string>qu;
        qu.push("");
        while(!qu.empty()){
            string curr=qu.front();
            qu.pop();
            for(char ch='a';ch<='z';ch++){
                string next=curr+ch;
                if(isvalid(next,s,k)){
                    result=next;
                    qu.push(next);                    
                }
            }
        }
        return result;
    }
};