#include "djikstra.cpp"

using namespace std;

int main() {
    Graph G;

    Vertex atlanta("Atlanta");
    Vertex boston("Boston");
    Vertex chicago("Chicago");
    Vertex denver("Denver");
    Vertex el_paso("El Paso");

    atlanta.add_route(&boston, 100);
    atlanta.add_route(&denver, 160);

    boston.add_route(&chicago, 120);
    boston.add_route(&denver, 180);

    chicago.add_route(&el_paso, 80);

    denver.add_route(&chicago, 40);
    denver.add_route(&el_paso, 140);

    G.add_vertex(atlanta);
    G.add_vertex(boston);
    G.add_vertex(chicago);
    G.add_vertex(denver);
    G.add_vertex(el_paso);

    // djikstra_shortest_path(G, 0, 4);
    djikstra_shortest_path2(G, 0, 4);

    return 0;
}