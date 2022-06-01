#include "matrix_creation.h"

std::string graph_file()
{
    std::string temp;
    std::ifstream input("C:\\Users\\Elen\\Desktop\\input_graph.txt");
    std::stringstream sstr;
    while (input >> sstr.rdbuf());
    temp = sstr.str();
    return temp;
}

std::tuple<matrix, int> convert_to_connectivity_matrix(std::string graph)
{
    //E = {{1,2}, {1,3},{1,4},{1,5}, {2,3},{2,4},{2,5}, {3,4},{3,5}, {4,5}, {3,6}, {6,7}, {6,8}, {6,9}, {6,10}, {7,8},{7,9},{7,10},{8,9},{8,10},{9,10}}
    std::vector<int> vec(graph.size());
    int count_of_brackets{};
    int i = 0; 
    int size = 1;
    int max{};
    while (i <= graph.size())
    {
        if (graph[i] == '{') count_of_brackets++;
        if (graph[i] == '}') count_of_brackets--;
        if (isdigit(graph[i]))
        {
            std::string t;
            while (isdigit(graph[i]))
            {
                t += graph[i];
                i++;
            }
            vec[size] = std::stoi(t);
            if (vec[size] > max) max = vec[size];
            size++;
        }
        else i++;
    }
    if (count_of_brackets != 0)
    {
        std::cout << "Wrong expression!";
        exit(1);
    }
    size--;
    matrix mat(max + 1, std::vector<int>(max + 1, 0));
    i = 1;
    while (i <= size)
    {
        mat[vec[i]][vec[i + 1]] = 1;
        mat[vec[i + 1]][vec[i]] = 1;
        i += 2;
    }
    return std::make_tuple(mat, max);
}