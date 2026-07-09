class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>matrix(n,vector<int>(m,-1));
        vector<vector<int>>directions{{0,1} , {0,-1} , {-1,0} , {1,0}};
        queue<pair<int,int>>q;
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( isWater[i][j] == 1 )  {
                    matrix[i][j] = 0;
                   q.push({i,j});
                }
            }
        }
        
        while ( !q.empty() ) {
            int N = q.size();
            while ( N-- ) {
                pair<int,int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for ( int d = 0 ; d < 4 ; d ++ ) {
                    int newI = i + directions[d][0];
                    int newJ = j + directions[d][1];
                    if ( newI >= 0 && newI < n && newJ >= 0 && newJ < m && matrix[newI][newJ] == -1 ) {
                        matrix[newI][newJ] = matrix[i][j] + 1;
                        q.push({newI , newJ });
                    }
                }
            }
        }

        return matrix;

    }
};