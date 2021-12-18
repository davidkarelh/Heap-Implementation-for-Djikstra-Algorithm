#include "djikstra.cpp"

using namespace std;

int main() {
    Graph graph;

    // Test Case 1
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

    graph.add_vertex(atlanta);
    graph.add_vertex(boston);
    graph.add_vertex(chicago);
    graph.add_vertex(denver);
    graph.add_vertex(el_paso);

    djikstra_shortest_path(graph, 0, 4);
    djikstra_shortest_path2(graph, 0, 4);

    // Test Case 2
    // Vertex A("A");
    // Vertex B("B");
    // Vertex C("C");
    // Vertex D("D");
    // Vertex E("E");
    // Vertex F("F");
    // Vertex G("G");
    // Vertex S("S");
    // Vertex T("T");

    // A.add_route(&C, 1);

    // B.add_route(&S, 3);
    // B.add_route(&D, 4);

    // C.add_route(&E, 1);
    // C.add_route(&D, 3);

    // D.add_route(&E, 1);
    // D.add_route(&F, 5);
    // D.add_route(&T, 3);

    // E.add_route(&G, 2);
    // E.add_route(&T, 4);

    // G.add_route(&E, 2);
    // G.add_route(&T, 3);

    // S.add_route(&D, 7);
    // S.add_route(&A, 4);
    // S.add_route(&B, 3);

    // T.add_route(&F, 5);

    // graph.add_vertex(A);
    // graph.add_vertex(B);
    // graph.add_vertex(C);
    // graph.add_vertex(D);
    // graph.add_vertex(E);
    // graph.add_vertex(F);
    // graph.add_vertex(G);
    // graph.add_vertex(S);
    // graph.add_vertex(T);

    // // djikstra_shortest_path(graph, 7, 8);
    // djikstra_shortest_path2(graph, 7, 8);
    return 0;
}
