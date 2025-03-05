class Solution {
public:
    long long coloredCells(int n) {
        long long k=n;
        return (k*k)+((k-1)*(k-1));
    }
};