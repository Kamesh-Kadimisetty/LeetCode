class Solution {
public:
    int minLength(string s) {
        vector<char> stack;
        for(auto c: s){
            if(!stack.empty() && 
            ((c=='B' && stack.back()=='A') ||
            (c=='D' && stack.back()=='C'))){
                stack.pop_back();
            }
            else{
                stack.push_back(c);
            }
        }
        return stack.size();
    }
};