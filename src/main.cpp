#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include "parser.hpp"
#include "mergesort.hpp"
#include "binary_search.hpp"
#include "graph.hpp"
#include "kruskal.hpp"

using namespace std::chrono;

static void write_sorted_csv(const std::string& path, const std::vector<Solicitud>& a) {
    std::ofstream f(path);
    f << "customerID,tenure,MonthlyCharges,TotalCharges,Churn\n";
    for (const auto& s : a) {
        f << s.customerID << "," << s.tenure << "," << std::fixed << std::setprecision(2) << s.monthlyCharges << "," << s.totalCharges << "," << s.churn << "\n";
    }
}

static void write_graph_stats(const std::string& path, const Graph& graph, const std::vector<double>& group_avg) {
    std::ofstream out(path);
    out << "nodos=" << graph.n << "\n";
    out << "aristas=" << graph.edges.size() << "\n";

    double total_cost = 0.0;
    for (const auto& edge : graph.edges) {
        total_cost += static_cast<double>(std::get<2>(edge));
    }
    double avg_cost = graph.edges.empty() ? 0.0 : total_cost / static_cast<double>(graph.edges.size());
    out << "costo_promedio_arista=" << std::fixed << std::setprecision(2) << avg_cost << "\n";
    out << "promedios_grupo=";
    for (size_t i = 0; i < group_avg.size(); ++i) {
        if (i) out << ";";
        out << std::fixed << std::setprecision(2) << group_avg[i];
    }
    out << "\n";
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Uso: ./ada_pf data/WA_Fn-UseC_-Telco-Customer-Churn.csv\n";
        return 1;
    }
    std::string path = argv[1];
    std::vector<Solicitud> solicitudes;
    int total_loaded = 0, total_nulls = 0;
    if (!parse_csv(path, solicitudes, total_loaded, total_nulls)) {
        std::cerr << "Error: no se pudo abrir el archivo '" << path << "'\n";
        return 2;
    }

    std::cout << "Registros cargados: " << total_loaded << "\n";
    std::cout << "Registros con TotalCharges nulo: " << total_nulls << "\n";

    // mergesort
    std::vector<int> sizes = {1000, 3500, 7043};
    std::ofstream timing_out("results/timing_mergesort.txt");
    timing_out << "n,time_ms\n";
    for (int s : sizes) {
        int use = std::min((int)solicitudes.size(), s);
        if (use == 0) continue;
        std::vector<Solicitud> sample(solicitudes.begin(), solicitudes.begin() + use);
        auto t0 = high_resolution_clock::now();
        merge_sort_desc(sample);
        auto t1 = high_resolution_clock::now();
        double ms = duration<double, std::milli>(t1 - t0).count();
        timing_out << use << "," << std::fixed << std::setprecision(2) << ms << "\n";
    }
    timing_out.close();

    // ordena vector
    merge_sort_desc(solicitudes);
    write_sorted_csv("results/solicitudes_ordenadas.csv", solicitudes);

    // consultas
    std::vector<std::pair<std::string,int>> queries = {{"Q_A01",72},{"Q_A02",60},{"Q_A03",45},{"Q_A04",30},{"Q_A05",12}};
    std::ofstream qout("results/busquedas_A.txt");
    for (auto &q : queries) {
        int idx = binary_search_first_ge(solicitudes, q.second);
        if (idx == -1) qout << q.first << "," << q.second << ",NOT_FOUND\n";
        else qout << q.first << "," << q.second << "," << solicitudes[idx].customerID << "\n";
    }
    qout.close();

    // construccion grafo
    std::vector<double> group_avg = compute_group_monthly_avg(solicitudes, 20);
    Graph graph = build_deterministic_graph(group_avg);
    write_graph_stats("results/grafo_B_stats.txt", graph, group_avg);

    // mst kruskal
    int total_mst_cost = 0;
    std::vector<Edge> mst = kruskal_mst(graph.n, graph.edges, total_mst_cost);
    std::ofstream mout("results/mst_red.txt");
    mout << "peso_total=" << total_mst_cost << "\n";
    mout << "aristas(u,v,cost)\n";
    for (const auto &e : mst) {
        mout << std::get<0>(e) << "," << std::get<1>(e) << "," << std::get<2>(e) << "\n";
    }

    // verificar
    std::vector<Edge> subedges;
    for (const auto &e : graph.edges) {
        int u = std::get<0>(e), v = std::get<1>(e), w = std::get<2>(e);
        if (u < 5 && v < 5) subedges.emplace_back(u, v, w);
    }
    int total_sub_cost = 0;
    std::vector<Edge> mst_sub = kruskal_mst(5, subedges, total_sub_cost);
    mout << "subgrafo_0_4_peso=" << total_sub_cost << "\n";
    mout << "subgrafo_aristas(u,v,cost)\n";
    for (const auto &e : mst_sub) {
        mout << std::get<0>(e) << "," << std::get<1>(e) << "," << std::get<2>(e) << "\n";
    }
    mout.close();

    // stats
    std::ofstream out("results/solicitudes_cargadas_stats.txt");
    out << "total_loaded=" << total_loaded << "\n";
    out << "total_nulls=" << total_nulls << "\n";
    out.close();

    std::cout << "Ordenamiento y consultas completadas. Archivos escritos en results/.\n";
    return 0;
}
