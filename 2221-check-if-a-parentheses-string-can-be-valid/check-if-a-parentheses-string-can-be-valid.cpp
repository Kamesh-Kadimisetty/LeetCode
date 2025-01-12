class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2==1) return false;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                s[i]='*';
            }
        }
        stack<int>open,star;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!open.empty() && !star.empty() && open.top()<star.top()){
            star.pop();
            open.pop();
        }
        // if(star.size()%2==1)return false;
        return open.empty();
    }
};