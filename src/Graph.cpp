#include "Vertex.cpp"

using namespace std;

class Graph {
    public:
        Vertex adjacency_list[50];
        int length;

        Graph() {
            length = 0;
        };

        void add_vertex(Vertex v) {
            adjacency_list[length] = v;
            length++;
        }

        // Doesn't fully delete a vertex from Graph, only delete 
        // the specified vertex from the adjacency list, 
        // deleted vertex may still exist in the remaining vertices routes
        void delete_vertex(string in_name) {
            int i, j;
            for (i = 0; i < length ; i++) {
                if (adjacency_list[i].name == in_name) {
                    for (j = i; j < length - 1; j++) {
                        adjacency_list[j] = adjacency_list[j + 1];
                    }
                    break;
                }
            }
            length = length - 1;
        }
};
