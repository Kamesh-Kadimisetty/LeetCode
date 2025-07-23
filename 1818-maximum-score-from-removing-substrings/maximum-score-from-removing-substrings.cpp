class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size(),score=0;
        stack<char>st;
        if(x>=y){
            for(auto it:s){
                if(it=='b' && !st.empty() && st.top()=='a'){
                    st.pop();
                    score+=x;
                }
                else{
                    st.push(it);
                }
            }
            string rem="";
            while(!st.empty()){
                rem+=st.top();
                st.pop();
            }
            reverse(rem.begin(),rem.end());
            for(auto it:rem){
                if(it=='a' && !st.empty() && st.top()=='b'){
                    st.pop();
                    score+=y;
                }
                else{
                    st.push(it);
                }
            }
        }
        else{
            for(auto it:s){
                if(it=='a' && !st.empty() && st.top()=='b'){
                    st.pop();
                    score+=y;
                }
                else{
                    st.push(it);
                }
            }
            string rem="";
            while(!st.empty()){
                rem+=st.top();
                st.pop();
            }
            reverse(rem.begin(),rem.end());
            for(auto it:rem){
                if(it=='b' && !st.empty() && st.top()=='a'){
                    st.pop();
                    score+=x;
                }
                else{
                    st.push(it);
                }
            }
        }
        return score;
    }
};