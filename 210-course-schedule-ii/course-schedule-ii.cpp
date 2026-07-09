class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int,vector<int>> adj;
        vector<int>inDegree ( numCourses , 0 );
        for ( auto &it : prerequisites ) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        
        vector<int>res;
        queue<int>q;
        int cnt = 0;
        for ( int i = 0 ; i < numCourses ; i ++ ) {
            if ( inDegree[i] == 0 ) {
                cnt ++;
                q.push(i);
            }
        }

        while ( !q.empty() ) {
            int a = q.front();
            q.pop();
            res.push_back(a);
            for ( auto &it : adj[a] ) {
                inDegree[it]--;
                if ( inDegree[it] == 0 ) {
                    q.push(it);
                    cnt ++;
                }
            }
        }

        if ( cnt == numCourses ) {
            return res;
        }
        return {};
    }
};