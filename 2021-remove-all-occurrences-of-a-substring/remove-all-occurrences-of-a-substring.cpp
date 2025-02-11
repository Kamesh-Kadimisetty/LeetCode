class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        while(s.find(part)!=string::npos){
            int index=s.find(part);
            s.erase(index,m);
        }
        return s;
    }
};