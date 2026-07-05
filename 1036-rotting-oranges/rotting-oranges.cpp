class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int minMins = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto &dir : directions) {
                    int a = r + dir[0];
                    int b = c + dir[1];

                    if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == 1) {
                        grid[a][b] = 2;
                        q.push({a, b});
                    }
                }
            }
            if (!q.empty()) {
                minMins++;
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minMins;
    }
};