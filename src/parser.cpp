#include "parser.hpp"
#include <fstream>
#include <sstream>

bool parse_csv(const std::string& path, std::vector<Solicitud>& out, int& total_loaded, int& total_nulls) {
    std::ifstream f(path);
    if (!f.is_open()) return false;
    std::string line;

    if (!std::getline(f, line)) return false;

    total_loaded = 0;
    total_nulls = 0;

    while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> fields;
        while (std::getline(ss, item, ',')) fields.push_back(item);
        if (fields.size() < 5) continue; 

        Solicitud s;
        s.customerID = fields[0];
        try { s.tenure = std::stoi(fields[1]); } catch(...) { s.tenure = 0; }
        try { s.monthlyCharges = std::stod(fields[2]); } catch(...) { s.monthlyCharges = 0.0; }
        std::string totalStr = fields[3];
        if (totalStr.find_first_not_of(' ') == std::string::npos) { s.totalCharges = 0.0; total_nulls++; }
        else {
            try { s.totalCharges = std::stod(totalStr); } catch(...) { s.totalCharges = 0.0; total_nulls++; }
        }
        s.churn = fields[4];

        out.push_back(s);
        total_loaded++;
    }
    return true;
}
