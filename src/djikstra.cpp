#include <limits>
#include "PrioQueue.cpp"

using namespace std;

// Implemented with regular array
void djikstra_shortest_path(Graph G, int starting_idx, int final_idx) {
    map<string, int> shortest_path;
    map<string, string> shortest_previous_stopover;
    unordered_map<string, bool> visited_vertices;
    Graph unvisited_vertices;
    Vertex current_vertex;
    int path_length_through_current_vertex, i, min, idx_min;
    string starting_vertex, final_vertex;
    vector<string> printed_array;

    unvisited_vertices.add_vertex(G.adjacency_list[starting_idx]);
    shortest_path[G.adjacency_list[starting_idx].name] = 0;

    while (unvisited_vertices.length != 0) {
        min = numeric_limits<int>::max();
        for (i = 0; i < unvisited_vertices.length; i++) {
            if (!(shortest_path.count(unvisited_vertices.adjacency_list[i].name)) || (shortest_path[unvisited_vertices.adjacency_list[i].name] < min)) {
                idx_min = i;
                min = shortest_path[unvisited_vertices.adjacency_list[i].name];
            }
        }
        current_vertex = unvisited_vertices.adjacency_list[idx_min];
        unvisited_vertices.delete_vertex(unvisited_vertices.adjacency_list[idx_min].name);
        visited_vertices[unvisited_vertices.adjacency_list[idx_min].name] = true;

        map<Vertex *, int>::iterator adjacent_vertex;
        for (adjacent_vertex = (current_vertex.routes).begin(); adjacent_vertex != (current_vertex.routes).end(); adjacent_vertex++) {
            if (!(visited_vertices[(adjacent_vertex -> first) -> name])) {
                unvisited_vertices.add_vertex(*(adjacent_vertex -> first));
            }
            path_length_through_current_vertex = shortest_path[current_vertex.name] + adjacent_vertex -> second;

            if (!(shortest_path.count((adjacent_vertex -> first) -> name)) || path_length_through_current_vertex < shortest_path[(adjacent_vertex -> first) -> name]) {
                shortest_path[(adjacent_vertex -> first) -> name] = path_length_through_current_vertex;
                shortest_previous_stopover[(adjacent_vertex -> first) -> name] = current_vertex.name;
            }
        }
    }

    starting_vertex = G.adjacency_list[starting_idx].name;
    final_vertex = G.adjacency_list[final_idx].name;
    cout << "Shortest path from " << starting_vertex << " to:" << endl;
    for (auto shortest: shortest_path) {
        cout << shortest.first << " " << shortest.second << endl;
    }
    cout << endl;

    cout << "Shortest previous stopover vertex from "<< starting_vertex<< ":" << endl;
    for (auto shortest_stopover: shortest_previous_stopover) {
        cout << "To " << shortest_stopover.first << " from " << shortest_stopover.second << endl;
    }
    cout << endl;

    while (final_vertex != starting_vertex) {
        printed_array.push_back(final_vertex);
        final_vertex = shortest_previous_stopover[final_vertex];
    }

    printed_array.push_back(starting_vertex);

    cout << "Shortest path from " << starting_vertex << " to " << printed_array[0] << ": ";
    for (i = printed_array.size() - 1; i >= 0; i--) {
        cout << printed_array[i];
        if (i != 0) {
            cout << " -> ";
        }
    }
    cout << endl << "Shortest path weight from " << starting_vertex << " to " << printed_array[0] << ": " << shortest_path[printed_array[0]];
}

// Implemented with heap, faster then array
void djikstra_shortest_path2(Graph G, int starting_idx, int final_idx) {
    map<string, int> shortest_path;
    map<string, string> shortest_previous_stopover;
    unordered_map<string, bool> visited_vertices;
    PrioQueue unvisited_vertices;
    ElType val;
    Vertex * current_vertex;
    int path_length_through_current_vertex, i;
    string starting_vertex, final_vertex;
    vector<string> printed_array;

    unvisited_vertices.enqueue(newElType(G.adjacency_list[starting_idx].name, &(G.adjacency_list[starting_idx]), 0));
    shortest_path[G.adjacency_list[starting_idx].name] = 0;

    while (!unvisited_vertices.isEmpty()) {
        val = unvisited_vertices.dequeue();

        if (!shortest_path.count(val.to -> name) || shortest_path[val.to -> name] > val.path_length) {
            shortest_path[val.to -> name] = val.path_length;
            shortest_previous_stopover[val.to -> name] = val.from;
        }

        current_vertex = val.to;
        visited_vertices[current_vertex -> name] = true;

        for (auto &adjacent_vertex: current_vertex -> routes) {
            path_length_through_current_vertex = shortest_path[current_vertex->name] + adjacent_vertex.second;
            if (!visited_vertices[(adjacent_vertex.first) -> name]) {
                unvisited_vertices.enqueue(newElType(current_vertex -> name, adjacent_vertex.first, path_length_through_current_vertex));
            }
        }
    }

    starting_vertex = G.adjacency_list[starting_idx].name;
    final_vertex = G.adjacency_list[final_idx].name;
    cout << "Shortest path from " << starting_vertex << " to:" << endl;
    for (auto shortest: shortest_path) {
        cout << shortest.first << " " << shortest.second << endl;
    }
    cout << endl;

    cout << "Shortest previous stopover vertex from "<< starting_vertex<< ":" << endl;
    for (auto shortest_stopover: shortest_previous_stopover) {
        cout << "To " << shortest_stopover.first << " from " << shortest_stopover.second << endl;
    }
    cout << endl;

    while (final_vertex != starting_vertex) {
        printed_array.push_back(final_vertex);
        final_vertex = shortest_previous_stopover[final_vertex];
    }

    printed_array.push_back(starting_vertex);

    cout << "Shortest path from " << starting_vertex << " to " << printed_array[0] << ": ";
    for (i = printed_array.size() - 1; i >= 0; i--) {
        cout << printed_array[i];
        if (i != 0) {
            cout << " -> ";
        }
    }
    cout << endl << "Shortest path weight from " << starting_vertex << " to " << printed_array[0] << ": " << shortest_path[printed_array[0]];
}
