#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
using matrix = std::vector<std::vector<int>>;

class Graph
{
public:
	int vertices;
    matrix edges;
    Graph();

    Graph(matrix, int);
    void set(int, int, int);
    int get(int, int);

    void set_size(int);
    int get_size();
    int count_vertices();
    int count_edges();

    Graph& remove_self_loops();

    Graph& merge_vertices(int, int);
};


#endif //GRAPH
