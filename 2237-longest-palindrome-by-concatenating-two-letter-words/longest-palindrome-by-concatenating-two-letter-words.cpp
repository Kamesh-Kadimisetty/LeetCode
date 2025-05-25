class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size(),cnt=0,flag=0,x=0;
        unordered_map<string,int>mpp;
        for(auto it:words){
            mpp[it]++;
        }
        for(auto it:mpp){
            cout<<it.first<<" "<<it.second<<endl;
            string s=it.first;
            reverse(s.begin(),s.end());
            if(mpp.find(s)!=mpp.end()){
                if(s[0]==s[1] && mpp[s]==1){
                    if(flag==0){
                        flag=1;
                    }
                }
                else{
                    if(s[0]==s[1]){
                        if(mpp[s]%2==0){
                            cnt+=mpp[s];
                        }
                        else{
                            cnt+=mpp[s]-1;
                            flag=1;
                        }
                    }
                    else{
                        cnt+=min(mpp[s],it.second);
                    }
                }
            }
        }
        cout<<cnt;
        return (cnt+flag)*2;
    }
};