# UNIVERSIDAD EAFIT  
## ANÁLISIS DE ALGORITMOS  
### PRÁCTICA FINAL (INTEGRADORA) 2026/01 (15%)

**Tema:** Optimización de rutas y planificación de recursos en redes de telecomunicaciones — Algoritmos Codiciosos, Divide y Vencerás, y Programación Dinámica sobre datos reales  

- **Modalidad:** Actividad grupal, máximo 3 integrantes  
- **Fecha de entrega:** viernes 08 de mayo de 2026, hasta las 11:59 p.m.  
- **Medio de entrega:** Enlace al repositorio GitHub publicado en InteractivaVirtual  
- **Lenguaje:** C++ (implementación obligatoria)  

---

## 1. Contexto y motivación

Un operador que despliega fibra óptica sobre una ciudad real debe resolver simultáneamente tres subproblemas:

- Ordenar y consultar solicitudes de servicio (**Divide y Vencerás**)  
- Tender el menor cableado posible (**Codicioso**)  
- Asignar ancho de banda para maximizar ingreso (**Programación Dinámica**)  

Dataset: **Telco Customer Churn (Kaggle)**  
- Registros: 7,043 clientes  
- Atributos: 21  
- Licencia: CC0  

Archivo requerido:

```
data/WA_Fn-UseC_-Telco-Customer-Churn.csv
```

---

## 2. Objetivos

- Aplicar Divide y Vencerás  
- Implementar Kruskal  
- Usar Programación Dinámica (Mochila 0-1)  
- Integrar módulos en un pipeline  

---

## 3. Descripción del problema y tareas

### Módulo A — Divide y Vencerás

#### Campos:

| Campo CSV        | Interpretación |
|-----------------|---------------|
| customerID      | ID |
| tenure          | Prioridad |
| MonthlyCharges  | Valor |
| TotalCharges    | Peso |
| Churn           | Estado |

#### Actividades:

1. **Parseo**
   - Ignorar cabecera  
   - TotalCharges vacío → 0.0  

2. **MergeSort**
   - Ordenar por tenure descendente  

3. **Búsqueda binaria recursiva**

| Consulta | k  |
|----------|----|
| Q_A01    | 72 |
| Q_A02    | 60 |
| Q_A03    | 45 |
| Q_A04    | 30 |
| Q_A05    | 12 |

4. **Análisis empírico**
   - n = 1000, 3500, 7043  
   - Verificar O(n log n)  

Salida:

```
results/solicitudes_ordenadas.csv
results/busquedas_A.txt
```

---

### Módulo B — Codicioso (Kruskal)

Actividades:

1. Construcción del grafo (20 nodos)  
2. MST con Union-Find  
3. Justificación (Lema del ciclo)  
4. Verificación manual  

Salida:

```
results/mst_red.txt
```

---

### Módulo C — Programación Dinámica

Capacidad:

```
W = 500
```

Definiciones:

- w_i = TotalCharges  
- v_i = MonthlyCharges * 10  

Actividades:

1. Mochila 0-1  
   - dp[i][w]  
   - Dimensión: 51 x 501  

2. Contraejemplo greedy  

| Enfoque | Resultado | ¿Óptimo? |
|--------|----------|----------|
| Greedy | No       | ❌ |
| DP     | Sí       | ✅ |

3. Backtracking  
4. Complejidad: Θ(n · W)  

Salida:

```
results/asignacion_bw.txt
```

---

## 4. Integración del pipeline

```
g++ -std=c++17 -O2 -o ada_pf src/main.cpp src/*.cpp
./ada_pf data/WA_Fn-UseC_-Telco-Customer-Churn.csv
```

---

## 5. Estructura del repositorio

```
ADA_PF_Apellido1_Apellido2_Apellido3/

├── README.md
├── data/
│   └── WA_Fn-UseC_-Telco-Customer-Churn.csv
├── results/
│   ├── solicitudes_ordenadas.csv
│   ├── busquedas_A.txt
│   ├── mst_red.txt
│   └── asignacion_bw.txt
├── src/
│   ├── parser.cpp / parser.hpp
│   ├── mergesort.cpp / mergesort.hpp
│   ├── binary_search.cpp / binary_search.hpp
│   ├── graph.cpp / graph.hpp
│   ├── kruskal.cpp / kruskal.hpp
│   ├── knapsack.cpp / knapsack.hpp
│   └── main.cpp
└── report/
    └── Informe.pdf
```

---

## 6. Informe técnico

Máximo 10 páginas:

1. Introducción  
2. Dataset  
3. Módulo A  
4. Módulo B  
5. Módulo C  
6. Integración  
7. Conclusiones  
8. Herramientas IA  
9. Referencias  
10. Roles  

---

## 7. Rúbrica de evaluación

Criterios:

- Módulo A (Divide y Vencerás)  
- Módulo B (Greedy)  
- Módulo C (Programación Dinámica)  
- Pipeline e integración  
- Informe y calidad técnica  

---

## 8. Uso ético de IA

### Permitido:
- Consultar teoría  
- Debug  
- Redacción  

### Prohibido:
- Generar código completo  
- Procesar dataset  
- Copiar soluciones  

---

## 9. Lineamientos técnicos

### CSV
- Ignorar header  
- TotalCharges vacío → 0.0  

### Grafo
- Agrupar por i mod 20  
- Grafo completo (190 aristas)  

Costo:

```
c(u,v) = floor(Mu + Mv)
```

---

### Tiempos
- std::chrono  
- ms con 2 decimales  

---

## 10. Verificación de resultados

| Propiedad | Valor |
|----------|------|
| Total de registros cargados | 7,043 |
| Registros con TotalCharges nulo | 11 |
| Registros con Churn = No | 5,174 |
| tenure máximo en el dataset | 72 |
| tenure mínimo en el dataset | 0 |
| MonthlyCharges promedio global | 64.76 USD |

---

## 11. Conexión con contenidos del curso

| Contenido del curso | Aplicación en el proyecto |
|--------------------|--------------------------|
| Divide y Vencerás: MergeSort | Ordenamiento |
| Divide y Vencerás: búsqueda binaria | Consultas |
| Teorema Maestro | O(n log n) |
| Algoritmos Codiciosos | MST |
| Kruskal y Union-Find | Construcción MST |
| Programación Dinámica | Mochila 0-1 |
| Fallo de la estrategia codiciosa | Contraejemplo |
| Análisis de complejidad | Formalización |
