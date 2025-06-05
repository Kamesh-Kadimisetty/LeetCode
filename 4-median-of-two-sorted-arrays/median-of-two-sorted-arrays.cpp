class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size(),i=0,j=0;
        double result=0;
        if((n+m)%2==0){
            int pos=((n+m)/2)-1;
            int cnt=0;
            while(i<n && j<m && cnt<=pos+1){
                int x=0;
                if(nums1[i]<=nums2[j]){
                    x=nums1[i];
                    i++;
                }
                else{
                    x=nums2[j];
                    j++;
                }
                if(cnt==pos || cnt==pos+1){
                    result+=(x/2.00);
                } 
                cnt++;
            }
            while(i<n && cnt<=pos+1){
                if(cnt==pos || cnt==pos+1) result+=(nums1[i]/2.00);
                cnt++;
                i++;
            }
            while(j<m && cnt<=pos+1){
                if(cnt==pos || cnt==pos+1) result+=(nums2[j]/2.00);
                cnt++;
                j++;
            }
        }
        else{
            int pos=(n+m)/2;
            int cnt=0;
            while(i<n && j<m && cnt<=pos){
                int x=0;
                if(nums1[i]<=nums2[j]){
                    x=nums1[i];
                    i++;
                }
                else{
                    x=nums2[j];
                    j++;
                }
                if(cnt==pos) return x;
                cnt++;
            }
            while(i<n && cnt<=pos){
                if(cnt==pos) return nums1[i];
                cnt++;
                i++;
            }
            while(j<m && cnt<=pos){
                if(cnt==pos) return nums2[j];
                cnt++;
                j++;
            }
        }
        return result;
    }
};