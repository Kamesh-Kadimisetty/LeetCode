class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> map(32,-2);
        map[0]=-1;
        int maxlen=0,mask=0;

        for(int i=0;i<s.size();i++){
            char ch=s[i];

            switch(ch){
                case 'a':
                    mask^=1;
                    break;
                case 'e':
                    mask^=2;
                    break;
                case 'i':
                    mask^=4;
                    break;
                case 'o':
                    mask^=8;
                    break;
                case 'u':
                    mask^=16;
                    break;                
            }

            int prev=map[mask];
            if(prev==-2){
                map[mask]=i;
            }
            else{
                maxlen=max(maxlen,i-prev);
            }
        }
        return maxlen;
    }
};