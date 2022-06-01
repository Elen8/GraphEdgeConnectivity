#ifndef MATRIX_CREATION_HPP
#define MATRIX_CREATION_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <tuple>
using matrix = std::vector<std::vector<int>>;


std::string graph_file();
std::tuple<matrix, int> convert_to_connectivity_matrix(std::string);

#endif //M_C
