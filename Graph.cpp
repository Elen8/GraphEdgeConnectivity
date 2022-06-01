#include "Graph.h"

Graph::Graph()
{
    vertices = 0;
}

Graph::Graph(matrix mat, int size)
{
    
	vertices = size;
    matrix temp(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp[i][j] = mat[i + 1][j + 1];
        }
    }
    edges = temp;
    
}

void Graph::set(int row, int column, int value) {
    edges[row][column] = value;
    return;
}

int Graph::get(int row, int column) {
    return edges[row][column];
}

void Graph::set_size(int size) {
    vertices = size;
    edges.resize(vertices * vertices);
    return;
}

int Graph::get_size() {
    return vertices;
}

int Graph::count_vertices() {
    int vrtc = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (get(i, j) > 0) {
                vrtc++;
                break;
            }
        }
    }
    return vrtc;
}

int Graph::count_edges() {
    int edge = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            edge += get(i, j);
        }
    }
    return edge / 2;
}

Graph& Graph::remove_self_loops() {
    for (int i = 0; i < vertices; i++) {
        set(i, i, 0);
    }
    return *this;
}

Graph& Graph::merge_vertices(int u, int v) {
    if (u < vertices && v < vertices) {
        for (int i = 0; i < vertices; i++) {
            set(i, v, get(i, u) + get(i, v));
            set(i, u, 0);
            set(v, i, get(u, i) + get(v, i));
            set(u, i, 0);
        }
        
    }
    return *this;
}