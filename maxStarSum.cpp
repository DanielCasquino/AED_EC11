#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
    {

        if (edges.size() < 1)
        {
            return vals[0];
        }

        vector<vector<int>> graph(vals.size());

        for (auto pair : edges)
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        vector<bool> visited(vals.size(), false);
        queue<int> q;

        int maxSum = 0;

        visited[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            int tempSum = vals[current];

            vector<int> starValues;

            for (int neighbour : graph[current])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
                starValues.push_back(vals[neighbour]);
            }

            sort(starValues.begin(), starValues.end(), greater<int>());

            for (int i = 0; i < min((int)graph[current].size(), k); ++i)
                tempSum += starValues[i];

            if (tempSum > maxSum)
                maxSum = tempSum;
        }
        return maxSum;
    }
};

int main()
{
    vector<int> vals = {1, 2, 3, 4, 10, -10, -20};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}, {3, 6}};
    int k = 2;
    cout << Solution().maxStarSum(vals, edges, k) << endl;
    return 0;
}
