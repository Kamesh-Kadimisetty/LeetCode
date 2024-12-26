class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        int ind=0;
        while(ind<result.size() && result[ind]=='0'){
            ind++;
        }
        result=result.substr(ind);
        return result==""?"0":result;
    }
};