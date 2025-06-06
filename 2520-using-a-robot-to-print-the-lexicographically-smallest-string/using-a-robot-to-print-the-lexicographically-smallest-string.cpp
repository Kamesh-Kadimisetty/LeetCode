class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<char>minchar(n);
        minchar[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            minchar[i]=min(s[i],minchar[i+1]);
        }
        // for(auto it:minchar) cout<<it<<" ";
        string result;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==minchar[i]){
                // cout<<i<<" "<<result<<endl;;
                result+=s[i];
                while(!st.empty() && st.top()<=s[i+1] && st.top()<=minchar[i+1]){
                    result+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && st.top()<=s[i] && st.top()<=minchar[i]){
                    result+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};