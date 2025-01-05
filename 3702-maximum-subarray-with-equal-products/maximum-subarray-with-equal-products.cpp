class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    int maxLength(vector<int>& nums) {
        int maxlen = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            int currGCD = nums[i];
            int currLCM = nums[i];
            long long  prod=nums[i];
            for (int j = i+1; j < n; j++) {
                if (j > i) {
                    currGCD = gcd(currGCD, nums[j]);
                    currLCM = lcm(currLCM, nums[j]);
                }
                if (prod > LLONG_MAX / nums[j]) {
                    break;
                }
                prod*=nums[j];
                if (currGCD * currLCM == prod) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }

        return maxlen;
    }
};