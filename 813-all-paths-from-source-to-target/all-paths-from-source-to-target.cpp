class Solution {
public:
    void dfs ( int src , int dest , vector<vector<int>>& graph , vector<int>&srcToDestPath , vector<vector<int>>&totalSrcToDestPaths ) {
        if ( src == dest ) {
           totalSrcToDestPaths.push_back(srcToDestPath);
           return ;
        }
        
        for ( int neighbor : graph[src] ) {
          srcToDestPath.push_back(neighbor);
          dfs ( neighbor , dest , graph , srcToDestPath , totalSrcToDestPaths );
          srcToDestPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int dest = n - 1;
        vector<int>srcToDestPath;
        vector<vector<int>>totalSrcToDestPaths;
        srcToDestPath.push_back(0);
         dfs ( 0 , dest , graph , srcToDestPath , totalSrcToDestPaths );
         return totalSrcToDestPaths;              
    }
};  