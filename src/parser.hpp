#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

struct Solicitud {
    std::string customerID;
    int tenure;
    double monthlyCharges;
    double totalCharges;
    std::string churn;
};


// total_loaded numero de registros leidos
// total_nulls numero de registros con nulo
bool parse_csv(const std::string& path, std::vector<Solicitud>& out, int& total_loaded, int& total_nulls);

#endif // PARSER_HPP
