class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxarea=INT_MIN;
        int left=0,right=n-1;
        while(left<right){
            maxarea=max(maxarea,(right-left)*min(height[left],height[right]));

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};