class Solution {
public:
    int n , m;
    void dfs ( int i , int j , vector<vector<int>>&visited , vector<vector<char>>&board ) {
        if ( i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O' || visited[i][j]) return;
        visited[i][j] = 1 ;
        dfs ( i + 1 , j , visited , board );
        dfs ( i - 1 , j , visited , board );
        dfs ( i , j - 1 , visited , board );
        dfs ( i , j + 1 , visited , board );
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        for ( int j = 0 ; j < m ; j ++ ) {
            if ( !visited[0][j] && board[0][j] == 'O') {
                dfs ( 0 , j , visited , board );
            }
            if ( !visited[n-1][j] && board[n-1][j] == 'O' ) {
                dfs ( n - 1 , j , visited , board );
            }
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( !visited[i][0] && board[i][0] == 'O') {
                dfs ( i , 0 , visited , board );
            }
            if ( !visited[i][m-1] && board[i][m-1] == 'O') {
                dfs ( i , m - 1 , visited , board );
            }
        }
        
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( !visited[i][j] && board[i][j] == 'O') board[i][j] ='X';
            }
        }
    }
};