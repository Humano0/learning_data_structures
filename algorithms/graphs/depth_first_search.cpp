#include <iostream>
#include <list>
#include <map>

using namespace ::std;

class Graph{
    map<int, bool> visited;
    map<int, list<int>> neighbors;

    public:
        void addEdge(int v, int w){
            neighbors[v].push_back(w);
        }
        void depth_first_search(int target){
            visited[target] = true;
            cout << target << endl;

            for(list<int>::iterator it = neighbors[target].begin(); it != neighbors[target].end(); it++){
                if(!visited[*it]){
                    depth_first_search(*it);
                }
            }
        }
};

int main()
{
    Graph g;
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
    cout << "Following is Depth First Traversal " << "(starting from vertex 2) \n";
    g.depth_first_search(2);

    return 0;
}