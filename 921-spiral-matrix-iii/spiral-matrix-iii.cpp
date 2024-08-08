#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        int steps = 1; // Initial step size in each direction
        int d = 0; // direction index (0: right, 1: down, 2: left, 3: up)
        
        result.push_back({rStart, cStart});
        
        while (result.size() < rows * cols) {
            for (int i = 0; i < 2; ++i) { // Increase steps every two directions
                for (int j = 0; j < steps; ++j) {
                    rStart += directions[d][0];
                    cStart += directions[d][1];
                    
                    // Check if we're within the bounds
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                }
                d = (d + 1) % 4; // Change direction
            }
            ++steps; // Increase the number of steps after completing two directions
        }
        
        return result;
    }
};
