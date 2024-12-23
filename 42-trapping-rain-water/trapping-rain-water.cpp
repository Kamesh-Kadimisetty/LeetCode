class Solution {
public:
    int trap(vector<int>& height) {
        int total=0,n=height.size();
        vector<int>lmax(n);
        vector<int>rmax(n);
        lmax[0]=height[0];
        for(int i=1;i<n;i++){
            lmax[i]=max(height[i],lmax[i-1]);
        }
        rmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(height[i],rmax[i+1]);
        }
        for(int i=0;i<n;i++){
            if(lmax[i]>=height[i] && rmax[i]>=height[i]){
                total+=(min(lmax[i],rmax[i])-height[i]);
            }
        }
        return total;
    }
};