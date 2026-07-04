class Solution {
public:
    int n , m;
    void dfs ( int i , int j , int& perimeter , vector<vector<int>>& grid ) {
        if ( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 ) {
            perimeter++;
            return;
        }
        if ( grid[i][j] == -1 ) return;
        grid[i][j] = -1;
        dfs ( i - 1 , j , perimeter , grid );
        dfs ( i + 1 , j , perimeter , grid );
        dfs ( i , j - 1 , perimeter , grid );
        dfs ( i , j + 1 , perimeter , grid );
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int perimeter = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
               if ( grid[i][j] == 1 ) {
                 dfs ( i , j , perimeter , grid );
               }
            }
        }
        return perimeter;
    }
};