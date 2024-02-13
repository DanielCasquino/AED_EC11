#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> subtree(n, 0);
        vector<int> dp(n, 0);
        function<void(int, int)> dfs = [&](int u, int p) {
            subtree[u] = vals[u];
            for (auto v : adj[u]) {
                if (v == p) continue;
                dfs(v, u);
                subtree[u] += max(0, subtree[v]);
            }
        };
        function<void(int, int)> dfs2 = [&](int u, int p) {
            dp[u] = subtree[u];
            for (auto v : adj[u]) {
                if (v == p) continue;
                dfs2(v, u);
                dp[u] = max(dp[u], subtree[u] - max(0, subtree[v]) + dp[v]);
            }
        };
        dfs(0, -1);
        dfs2(0, -1);
        return dp[0];
    }
};
int main() {
    vector<int> vals = {1,2,3,4,10,-10,-20};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4},{3,5},{3,6}};
    int k = 2;
    Solution sol;
    cout << sol.maxStarSum(vals, edges, k) << endl;
    return 0;
}
