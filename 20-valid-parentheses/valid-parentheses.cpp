class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char c=st.top();
                if((c=='{' && i=='}') || (c=='(' && i==')') || (c=='[' && i ==']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty()?true:false;
    }
};