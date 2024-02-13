#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        std::vector<bool> visited(n, false);
        std::queue<int> q;

        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (auto adj : edges[curr])
            {
                if (visited[adj] == false)
                {
                    if (adj == destination)
                        return true;

                    q.push(adj);
                    visited[adj] = true;
                }
            }
        }
        return false;
    }
};
