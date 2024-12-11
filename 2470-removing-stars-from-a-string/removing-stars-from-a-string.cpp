class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans;
        for(auto i:s){
            if(i=='*' && !st.empty()){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};