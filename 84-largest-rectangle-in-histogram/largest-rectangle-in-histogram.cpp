class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxheight=INT_MIN;
        vector<int>nse=NSE(heights);
        vector<int>pse=PSE(heights);
        for(int i=0;i<heights.size();i++){
            // cout<<heights[i]*(nse[i]-pse[i]-1)<<endl;
            // cout<<pse[i]<<" "nse[i]<<endl;
            maxheight=max(maxheight,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxheight;
    }
    vector<int>NSE(vector<int>nums){
        int n=nums.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i]=(st.empty()?n:st.top());
            st.push(i);
        }
        return nse;
    }
    vector<int>PSE(vector<int>nums){
        int n=nums.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            pse[i]=(st.empty()?-1:st.top());
            st.push(i);
        }
        return pse;
    }
};