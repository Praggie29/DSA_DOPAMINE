class Solution {
public:
    int n , m;
    void dfs( int i , int j , int startColor , int color , vector<vector<int>>& image ) {
        if ( i < 0 || i >= n || j < 0 || j >= m ) {
            return;
        }
        if ( image[i][j] != startColor ) return;
        image[i][j] = color;
        dfs ( i - 1 , j , startColor , color , image );
        dfs ( i + 1 , j , startColor , color , image );
        dfs ( i , j - 1 , startColor , color , image );
        dfs ( i , j + 1 , startColor , color , image );
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        int startColor = image[sr][sc];
        if (startColor == color) return image;
        dfs ( sr , sc , startColor , color , image );
        return image;
    }
};