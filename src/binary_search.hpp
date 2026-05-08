#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include "parser.hpp"
#include <vector>

// Devuelve el índice de la primera solicitud con tenure >= k, o -1 si no existe.
int binary_search_first_ge(const std::vector<Solicitud>& a, int k);

#endif // BINARY_SEARCH_HPP
