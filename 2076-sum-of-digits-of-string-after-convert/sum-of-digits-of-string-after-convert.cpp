class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        long long sum=0,ans=0;
        for(int i = 0; i < s.size(); i++){
            int num = s[i] - 'a' + 1; // 'a' -> 1, 'b' -> 2, ..., 'z' -> 26
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
        }
        while(k > 1) {
            long long newSum = 0;
            while(sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
            k--;
        }
        return sum;
    }
};