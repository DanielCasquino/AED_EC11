#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> dp(n, 0);
        vector<int> dp2(n, 0);
        function<void(int, int)> dfs = [&](int u, int p) {
            dp[u] = vals[u];
            for (int v : g[u]) {
                if (v == p) continue;
                dfs(v, u);
                if (dp[v] > 0) dp[u] += dp[v];
            }
        };
        dfs(0, -1);
        function<void(int, int)> dfs2 = [&](int u, int p) {
            for (int v : g[u]) {
                if (v == p) continue;
                dp2[v] = max(0, dp2[u] + dp[v]);
                dfs2(v, u);
            }
        };
        dfs2(0, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[i] + dp2[i]);
        }
        return ans;
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

