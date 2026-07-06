class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int steps = 0;
        vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                pair<int, int> temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                
                if ((temp != make_pair(entrance[0], entrance[1])) && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                    return steps;
                }
                
                for (auto &it : directions) {
                    int newI = i + it[0];
                    int newJ = j + it[1];
                    if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && maze[newI][newJ] != '+') {
                        q.push({newI, newJ});
                        maze[newI][newJ] = '+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};