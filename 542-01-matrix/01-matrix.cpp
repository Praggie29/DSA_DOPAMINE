class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       vector<vector<int>>matr(n,vector<int>(m,-1));
       queue<pair<int,int>>q;
       for ( int i = 0 ; i < n ; i ++ ) {
         for ( int j = 0 ; j < m ; j ++ ) {
            if ( mat[i][j] == 0 ) {
                matr[i][j] = 0;
                q.push({i,j});
            }
         }
       } 
       vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
       while ( !q.empty() ) {
         pair<int,int> p = q.front();
         q.pop();
         int i = p.first;
         int j = p.second;
         for ( auto &dir : directions ) {
            int newI = i + dir[0];
            int newJ = j + dir[1];
            if ( newI >= 0 && newI < n && newJ >= 0 && newJ < m && matr[newI][newJ] == -1 ) {
                matr[newI][newJ] = matr[i][j] + 1;
                q.push({newI,newJ});
            }
          }
       }
       return matr;
    }
};