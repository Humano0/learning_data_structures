#include <iostream>
#include <vector>
#include <list>

using namespace::std;

class Graph{
    //Number of edges
    int V;
    vector<list<int>> neighbors;

    public:
        // Constructor
        Graph(int V){
            this->V = V;
            neighbors.resize(V);
        }

        // v => source // W => destination
        void addEdge(int v, int w){
            neighbors[v].push_back(w);
        }

        void breadth_first_traversal(int target){
            vector<bool> visited;
            visited.resize(V, false);

            list<int> queue;

            visited[target] = true;
            queue.push_back(target);

            while(!queue.empty()){
                target = queue.front();
                cout << target << endl;
                queue.pop_front();

                for(auto neighbor : neighbors[target]){
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        queue.push_back(neighbor);
                    }
                }
            }
        }
};

int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 2);
    cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n";
    g.breadth_first_traversal(2);
    
    return 0;
}