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

// Parsea el CSV y llena `out`. Devuelve true si pudo abrir el archivo.
// `total_loaded` recibe el número de registros leídos.
// `total_nulls` recibe el número de registros con TotalCharges nulo (vacío).
bool parse_csv(const std::string& path, std::vector<Solicitud>& out, int& total_loaded, int& total_nulls);

#endif // PARSER_HPP
