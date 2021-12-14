// #include "Vertex.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Vertex {
    public:
        string name;
        map<Vertex *, int> routes;

        Vertex() {};

        Vertex(string vertex_name) {
            name = vertex_name;
        }

        void add_route(Vertex * vertex_pointer, int path_length) {
            routes[vertex_pointer] = path_length;
        }
};