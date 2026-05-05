# UNIVERSIDAD EAFIT  
## ANÁLISIS DE ALGORITMOS  
### PRÁCTICA FINAL (INTEGRADORA) 2026/01 (15%)

**Tema:** Optimización de rutas y planificación de recursos en redes de telecomunicaciones — Algoritmos Codiciosos, Divide y Vencerás, y Programación Dinámica sobre datos reales  

- **Modalidad:** Actividad grupal, máximo 3 integrantes.  
- **Fecha de entrega:** viernes 08 de mayo de 2026, hasta las 11:59 p.m.  
- **Medio de entrega:** Enlace al repositorio GitHub publicado en InteractivaVirtual, con los nombres completos de los integrantes del equipo.  
- **Lenguaje:** C++ (implementación obligatoria).  

---

## 1. Contexto y motivación

Un operador que despliega fibra óptica sobre una ciudad real debe resolver simultáneamente tres subproblemas: ordenar y consultar eficientemente su inventario de solicitudes de servicio (Divide y Vencerás), tender el menor cableado posible para interconectar sus nodos de red (Codicioso), y asignar el ancho de banda disponible entre solicitudes competidoras para maximizar el ingreso (Programación Dinámica).

Este proyecto utiliza el dataset **Telecom Customer Churn** disponible en Kaggle, enriquecido con un grafo sintético de topología de red generado de forma determinista a partir de los datos.

**Fuente del dataset:**
- URL: https://www.kaggle.com/datasets/blastchar/telco-customer-churn  
- Registros: 7,043 clientes, 21 atributos  
- Licencia: CC0  

---

## 2. Objetivos

- Aplicar Divide y Vencerás  
- Implementar Kruskal  
- Usar Programación Dinámica (Mochila 0-1)  
- Integrar módulos en un pipeline  

---

## 3. Descripción del problema y tareas

### Módulo A — Divide y Vencerás

- Parseo CSV  
- MergeSort  
- Búsqueda binaria  
- Análisis empírico  

### Módulo B — Kruskal

- Construcción grafo  
- MST  
- Lema del ciclo  

### Módulo C — Mochila 0-1

- Programación dinámica  
- Backtracking  
- Contraejemplo greedy  

---

## 4. Integración

Compilación:

```
g++ -std=c++17 -O2 -o ada_pf src/main.cpp src/*.cpp
```

Ejecución:

```
./ada_pf data/WA_Fn-UseC_-Telco-Customer-Churn.csv
```

---

## 5. Estructura del repositorio

```
ADA_PF_Apellido1_Apellido2_Apellido3/
```

---

## 6. Informe

Máximo 10 páginas.

---

## 7. Rúbrica

Evaluación por módulos + informe.

---

## 8. Uso de IA

Permitido: teoría, debug  
Prohibido: generar código completo  

---

## 9. Lineamientos técnicos

- CSV parsing  
- Grafo determinista  
- std::chrono  

---

## 10. Verificación

- Registros: 7043  
- Nulos: 11  

---

## 11. Contenidos del curso

- MergeSort  
- Kruskal  
- Mochila 0-1  
