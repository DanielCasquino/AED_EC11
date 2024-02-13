#include <vector>
#include <queue>
#include <iostream>

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

        while (!q.empty()) // BFS hasta encontrar a destination
        {
            auto curr = q.front();
            q.pop();

            for (auto adj : edges[curr])
            {
                if (visited[adj] == false)
                {
                    if (adj == destination) // Si se encontro, hay un camino valido
                        return true;
                    q.push(adj);
                    visited[adj] = true;
                }
            }
        }
        return false; // Termino el BFS y no se encontro destination, no hay camino valido
    }
};

// int main()
// {
//     vector<vector<int>> case1 = {{1}, {2}, {0}};
//     vector<vector<int>> case2 = {{1, 2}, {}, {}, {5}, {3}, {4}, {}};
//     cout << boolalpha << Solution().validPath(3, case1, 0, 2) << endl;
//     cout << boolalpha << Solution().validPath(6, case2, 0, 5);
//     return 0;
// }