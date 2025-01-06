class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        int leftballs=0,rightballs=0;
        int leftmoves=0,rightmoves=0;
        for(int i=0;i<n;i++){
            ans[i]+=leftmoves;
            leftballs+=boxes[i]-'0';
            leftmoves+=leftballs;

            int j=n-i-1;
            ans[j]+=rightmoves;
            rightballs+=boxes[j]-'0';
            rightmoves+=rightballs;
        }
        return ans;
    }
};