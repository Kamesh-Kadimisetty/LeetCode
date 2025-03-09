class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt=0,size=1,n=colors.size();
        for(int i=0;i<n+k-2;i++){
            if(colors[i%n]!=colors[(i+1)%n]){
                size++;
                if(size>=k)cnt++;
            }
            else{
                size=1;
            }
        }
        return cnt;
    }
};