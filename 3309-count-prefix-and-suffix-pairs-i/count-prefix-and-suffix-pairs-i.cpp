class Solution {
public:
    bool isPrefixAndSuffix(string s1,string s2){
        int n=s1.size(),m=s2.size();
        if(m<n) return false;
        // for(int i=0;i<n;i++){
        //     if(s1[i]!=s2[i]){
        //         return false;
        //     }
        //     int j=m-i-1,k=n-i-1;
        //     if(s1[k]!=s2[j]){
        //         return false;
        //     }   
        // }
        string prefix=s2.substr(0,n);
        reverse(s2.begin(),s2.end());
        string suffix=s2.substr(0,n);
        reverse(suffix.begin(),suffix.end());
        return prefix==s1 && suffix==s1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])==true){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};