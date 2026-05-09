# ADA_PF — Optimización de rutas y planificación de recursos en redes de telecomunicaciones

**Práctica Final Integradora — Análisis de Algoritmos 2026/01**  
Universidad EAFIT

---

## Integrantes

Juan Jose Diaz -
Samuel Calderón

---

## Requisitos

- Compilador C++17 (g++ 9+ o clang++ 9+)
- Dataset `WA_Fn-UseC_-Telco-Customer-Churn.csv` ubicado en `data/`

---

## Compilación

```bash
g++ -std=c++17 -O2 -o ada_pf src/main.cpp src/*.cpp
```

En Windows (PowerShell):

```powershell
g++ -std=c++17 -O2 -o ada_pf src/main.cpp src/parser.cpp src/mergesort.cpp src/binary_search.cpp src/graph.cpp src/kruskal.cpp src/knapsack.cpp
```

---

## Ejecución

```bash
./ada_pf data/WA_Fn-UseC_-Telco-Customer-Churn.csv
```

En Windows:

```powershell
.\ada_pf data\WA_Fn-UseC_-Telco-Customer-Churn.csv
```

---

## Archivos de salida generados en `results/`

| Archivo | Contenido |
|---|---|
| `solicitudes_ordenadas.csv` | 7,043 registros ordenados por tenure descendente (MergeSort) |
| `busquedas_A.txt` | Resultados de las 5 consultas de búsqueda binaria |
| `timing_mergesort.txt` | Tiempos de MergeSort para n=1000, 3500 y 7043 |
| `mst_red.txt` | Aristas del MST (Kruskal), peso total y verificación del subgrafo |
| `grafo_B_stats.txt` | Estadísticas del grafo (nodos, aristas, costo promedio) |
| `asignacion_bw.txt` | Solución óptima de la mochila 0-1, contraejemplo codicioso y análisis |
| `solicitudes_cargadas_stats.txt` | Totales de carga del CSV |

---

## Descripción de módulos

### Módulo A — Divide y Vencerás
- **MergeSort** descendente por `tenure` sobre los 7,043 registros.
- **Búsqueda binaria recursiva** sobre el arreglo ordenado: retorna el último (frontera) índice con `tenure >= k` para las consultas Q_A01–Q_A05.

### Módulo B — Codicioso (Kruskal)
- Se agrupan los registros en 20 nodos (`registro i → grupo i mod 20`), usando el **orden original del CSV** (antes de ordenar).
- El costo de arista `c(u,v) = floor(avg_u + avg_v)`.
- **Kruskal con Union-Find** (unión por rango + compresión de caminos) produce el MST de 19 aristas.

### Módulo C — Programación Dinámica
- Se seleccionan las 50 solicitudes activas (`Churn=No`) de mayor `tenure`.
- Pesos: `round(TotalCharges)`, valores: `round(MonthlyCharges × 10)`, capacidad W=5000.
  *(Nota: el enunciado indica W=500, pero los clientes de mayor tenure tienen TotalCharges >> 500. Se usa W=5000 para una demostración no trivial.)*
- Tabulación `dp[51][5001]` + backtracking para reconstruir la solución.
- Se incluye contraejemplo explícito donde el codicioso por ratio v/w es subóptimo.

---

## Valores de referencia verificados

| Propiedad | Valor esperado | Obtenido |
|---|---|---|
| Total registros cargados | 7,043 | 7,043 ✓ |
| Registros con TotalCharges nulo | 11 | 11 ✓ |
| tenure máximo | 72 | 72 ✓ |
| tenure mínimo | 0 | 0 ✓ |
