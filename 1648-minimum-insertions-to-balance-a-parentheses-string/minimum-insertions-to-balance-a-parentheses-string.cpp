class Solution {
public:
    int minInsertions(string s) {
        int result=0,n=s.size(),i=0;
        stack<char>st;
        while(i<n){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(i<n-1 && s[i+1]==')'){
                    if(!st.empty()){
                        st.pop();
                    }
                    else{
                        result+=1;
                    }
                    i++;
                }  
                else{
                    if(!st.empty()){
                        st.pop();
                        result+=1;
                    }
                    else{
                        result+=2;
                    }
                }
            }
            i++;
        }
        return result+(2*st.size());
    }
};