class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int n=s.size(),cnt=0;
        for(int i=0;i<=n-k;i++){
            int x= stoi(s.substr(i,k));
            if(x!=0 && num%x==0) cnt++;
        }
        return cnt;
    }
};