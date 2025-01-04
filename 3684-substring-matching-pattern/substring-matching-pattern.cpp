class Solution {
public:
    bool hasMatch(string s, string p){
        int m=p.size();
        int i=p.find('*');
        string s1=p.substr(0,i);
        string s2=p.substr(i+1,m-i-1);
        if(s1.size()+s2.size()==0)return true;
        if(s1.size()>0){
            i=s.find(s1);
            if(i<0) return false;
        }
        if(s2.size()>0){
            i=s.find(s2,i+s1.size());
        }
        return i>=0;
    }
};