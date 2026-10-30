class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>ans;
        int startRow = 0 , startCol = 0;
        int endRow = n - 1 , endCol = m - 1;
        while ( startRow <= endRow && startCol <= endCol ) {
            for ( int j = startCol ; j <= endCol ; j ++ ) { //Top
              ans.push_back(matrix[startRow][j]);
            }
            startRow++;
            for ( int i = startRow ; i <= endRow ; i ++ ) { //Left
              ans.push_back(matrix[i][endCol]);
            }
            endCol--;
            if (startRow <= endRow) { //Bottom
                for (int j = endCol; j >= startCol; j -- ) {
                    ans.push_back(matrix[endRow][j]);
                }
                endRow--;
            }
            if (startCol <= endCol) { //Right
                for (int i = endRow; i >= startRow; i -- ) {
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }
        

        return ans;
    }
};