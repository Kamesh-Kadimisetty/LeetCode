class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        stack<char>st;
        for(auto ch:s){
            if(!(ch>='0' && ch<='9')){
                st.push(ch);
            }
            else{
                st.pop();
            }
        }
        string result;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};