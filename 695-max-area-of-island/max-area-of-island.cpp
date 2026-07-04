class Solution {
public:
    int n , m ;
    int dfs ( int i , int j , vector<vector<int>>& grid ) {
       if ( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1 ) return 0 ;
        grid[i][j] = -1;
       return 1  + dfs ( i - 1  , j , grid )
                 + dfs ( i + 1 , j , grid )
                 + dfs ( i , j - 1 , grid )
                 + dfs ( i , j + 1 , grid );
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        int islandsArea = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( grid[i][j] == 1 ) {
                    int area = dfs ( i , j , grid );
                   islandsArea = max ( islandsArea , area ); 
                } 
            }
        }
        return islandsArea;
    }
};