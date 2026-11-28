class Solution {
public:
    bool isSafe ( char num , int row , int col , vector<vector<char>>& board ) {
        for ( int j = 0 ; j < 9 ; j ++ ) {
            if ( board[row][j] == num ) return false;
        }
        for ( int i = 0 ; i < 9 ; i ++ ) {
            if ( board[i][col] == num ) return false;
        }
        int sr = ( row / 3 ) * 3;
        int sc = ( col / 3 ) * 3;
        for ( int i = sr ; i <= sr + 2 ; i ++ ) {
            for ( int j = sc ; j <= sc + 2 ; j ++ ) {
                if ( board[i][j] == num ) return false;
            }
        }
        return true;
    }
    bool solve ( int i , int j , vector<vector<char>>& board ) {
        if ( i == 9 ) return true;
        int nextRow = (j == 8) ? i + 1 : i;
        int nextCol = (j == 8) ? 0 : j + 1;
        if ( board[i][j] != '.' ) {
           return solve ( nextRow , nextCol , board );
        }
        for ( char dig = '1' ; dig <= '9' ; dig ++ ) {
            if ( isSafe ( dig , i , j , board )) {
                board[i][j] = dig;
               if ( solve ( nextRow , nextCol , board ) ) return true;
               board[i][j] = '.';
            }
        }
        return false;
    } 
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};