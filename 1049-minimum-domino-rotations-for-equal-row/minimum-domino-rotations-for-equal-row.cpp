class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        vector<int>freq(7,0);
        for(int i=0;i<n;i++){
            freq[tops[i]]++;
            freq[bottoms[i]]++;
        }
        int maxele=0;
        for(int i=1;i<7;i++){
            if(freq[maxele]<freq[i]){
                maxele=i;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(tops[i]==maxele) continue;
            else if(bottoms[i]==maxele) cnt++;
            else return -1;
        }
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(bottoms[i]==maxele) continue;
            else if(tops[i]==maxele) cnt1++;
            else return -1;
        }
        return min(cnt,cnt1);
    }
};