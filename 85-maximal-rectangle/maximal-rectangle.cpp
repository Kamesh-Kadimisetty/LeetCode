class Solution {
public:
    //REFER TO BEFORE PROBLEM 84
    int largestRectangleArea(vector<int>& heights) {
        int total=0;
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int val=heights[st.top()];
                st.pop();
                int pse=st.empty()?-1:st.top();
                int nse=i;
                total=max(total,val*(nse-pse-1)); 
            }
            st.push(i);
        } 
        //if elements present in stack are removed after iteration .....
        while(!st.empty()){
            int nse=n;
            int val=heights[st.top()];
            st.pop();
            int pse=st.empty()?-1:st.top();
            total=max(total,val*(nse-pse-1)); 
        }
        return total;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>barsizes(n,vector<int>(m));
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]=='1'){
                    cnt++;
                }
                else{
                    cnt=0;
                }
                barsizes[j][i]=cnt;
            }
        }
        int maxsize=0;
        for(int i=0;i<n;i++){
            maxsize=max(maxsize,largestRectangleArea(barsizes[i]));
        }
        return maxsize;
    }
};