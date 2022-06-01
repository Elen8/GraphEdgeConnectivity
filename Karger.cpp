#include "Karger.h"
#include <iostream>

void kargers_algorithm(Graph& g)
{
    g.remove_self_loops();
    int u = 0, v = 0;
    while (g.count_vertices() > 2)
    {
        u = 0;
        v = 0;
        do
        {
            u = (rand() % g.get_size());
            v = (rand() % g.get_size());
        } while (g.get(u, v) == 0);
        g.merge_vertices(u, v);
        g.remove_self_loops();
    }
    
    return;
}
