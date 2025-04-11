class Solution {
public:
    bool issymmentric(string s){
        int cnt=0,n=s.size();
        for(int i=0;i<n/2;i++){
            cnt+=int(s[i]);
            cnt-=int(s[n-i-1]);
        }
        return cnt==0;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2==0 && issymmentric(s)){
                cnt++;
            }
        }
        return cnt;
    }
};