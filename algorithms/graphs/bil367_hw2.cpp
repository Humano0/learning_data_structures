#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Graph
{
    // V = Number of edges
    int V;
    vector<list<int>> neighbors;

public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        neighbors.resize(V);
    }

    // v => source // W => destination
    void addEdge(int v, int w)
    {
        neighbors[v].push_back(w);
    }

    void breadth_first_traversal(int target)
    {
        vector<bool> visited;
        visited.resize(V, false);

        list<int> queue;

        visited[target] = true;
        queue.push_back(target);

        cout << "BFS";
        while (!queue.empty())
        {
            target = queue.front();
            cout << " -> " << target;
            queue.pop_front();

            for (auto neighbor : neighbors[target])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.push_back(neighbor);
                }
            }
        }
    }

    void detect_cycles(){
        map<vector<int>, int> lol;
        vector<vector<int>> cycle;

        
    }
};

int main()
{
    Graph g(16);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(1, 6);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(3, 6);
    g.addEdge(3, 9);
    g.addEdge(5, 0);
    g.addEdge(5, 3);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    g.addEdge(7, 1);
    g.addEdge(8, 0);
    g.addEdge(8, 1);
    g.addEdge(8, 5);
    g.addEdge(9, 5);
    g.breadth_first_traversal(0);
}