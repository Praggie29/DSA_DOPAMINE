class Solution {
public:
    bool canPlace(int row, int col, vector<string>& store, int n) {
        for (int r = row - 1; r >= 0; r--) {
            if (store[r][col] == 'Q') {
                return false;
            }
        }
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (store[r][c] == 'Q') {
                return false;
            }
        }
        for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
            if (store[r][c] == 'Q') {
                return false;
            }
        }

        return true;
    }
    
    void f ( int i , vector<string>&store , vector<vector<string>>&ans , int n ) {
        if ( i == n ) {
            ans.push_back(store);
            return;
        }
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( canPlace ( i , j , store , n )) {
                store[i][j] = 'Q';
                f ( i + 1 , store , ans , n );
                store[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> store(n, string(n, '.'));
        f ( 0 , store , ans , n );
        return ans;
    }
};