class Solution {
public:
    int n , m;
    void dfs ( int i , int j , vector<vector<int>>& grid ) {
       if ( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 ) return;
       grid[i][j] = 0;
       dfs ( i - 1 , j , grid );
       dfs ( i + 1 , j , grid );
       dfs ( i , j - 1 , grid );
       dfs ( i , j + 1 , grid );
    }
    int numEnclaves(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        int cnt = 0;

        for ( int i = 0 ; i < m ; i ++ ) {
            if ( grid[0][i] == 1 ) dfs ( 0 , i , grid );
            if ( grid[n-1][i] == 1 ) dfs ( n -1 , i , grid );
        }
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( grid[j][0] == 1 ) dfs ( j , 0 , grid );
            if ( grid[j][m-1] == 1 ) dfs ( j , m - 1 , grid );
        }
        
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( grid[i][j] == 1 ) cnt++;
            }
        }
        return cnt;
    }
};