class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void recurse(int row, int col, vector<vector<int>>& grid, char direction) {
        if (row < 0 || row >= grid.size() || col < 0 ||
            col >= grid[row].size() || grid[row][col] == GUARD ||
            grid[row][col] == WALL) {
            return;
        }
        grid[row][col] = GUARDED;  // Mark cell as guarded
        if (direction == 'U') recurse(row - 1, col, grid, 'U');  // Up
        if (direction == 'D') recurse(row + 1, col, grid, 'D');  // Down
        if (direction == 'L') recurse(row, col - 1, grid, 'L');  // Left
        if (direction == 'R') recurse(row, col + 1, grid, 'R');  // Right
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        // Mark guards' positions
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards) {
            recurse(guard[0] - 1, guard[1], grid, 'U');  // Up
            recurse(guard[0] + 1, guard[1], grid, 'D');  // Down
            recurse(guard[0], guard[1] - 1, grid, 'L');  // Left
            recurse(guard[0], guard[1] + 1, grid, 'R');  // Right
        }

        // Count unguarded cells
        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
};