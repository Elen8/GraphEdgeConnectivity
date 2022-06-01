#include "matrix_creation.h"
#include "Graph.h"
#include "Graph.cpp"
#include "Karger.h"
#include "printing.h"
#include <windows.h>
#include <iomanip>


int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    matrix connectivity_matrix;
    int matrix_size;

    std::tie(connectivity_matrix, matrix_size) = convert_to_connectivity_matrix(graph_file());
    print_matrix(connectivity_matrix, matrix_size);

    Graph graph1(connectivity_matrix, matrix_size);
    Graph ming;

    ming.set_size(0);
    int n = graph1.count_vertices();
    float ln = log((float)n);
    float runs = n * ln, mincut = INT_MAX;

    for (int i = 0; i < runs; ++i)
    {
        Graph copy = graph1;
        kargers_algorithm(copy);
        int cut = copy.count_edges();
        if (cut < mincut)
        {
            mincut = cut;
            ming = copy;
        }
    }

    SetConsoleTextAttribute(hConsole, 176);
    std::cout << std::endl << "                Vertex connectivity of the given graph is " << mincut << "                  " << std::endl;
    SetConsoleTextAttribute(hConsole, 0);
    return 0;
}